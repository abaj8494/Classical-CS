# Reads 10 numbers into an array, bubblesorts them
# and then prints the 10 numbers

# Constants
ARRAY_LEN = 10

main:
	# Registers:
	#  - $t0: int i
	#  - $t1: temporary result
	#  - $t2: int swapped
	#  - $t3: int x
	#  - $t4: int y
	#  - $t5: temporary result

scan_loop__init:
	li	$t0, 0				# i = 0
scan_loop__cond:
	bge	$t0, ARRAY_LEN, scan_loop__end	# while (i < ARRAY_LEN) {

scan_loop__body:
	li	$v0, 5				#   syscall 5: read_int
	syscall					#
						#
	mul	$t1, $t0, 4			#   &numbers[i] = numbers + 4 * i
	sw	$v0, numbers($t1)		#   scanf("%d", &numbers[i]);

	addi	$t0, $t0, 1			#   i++;
	b	scan_loop__cond			# }
scan_loop__end:

swap_loop__init:
	li	$t2, 1				# swapped = 1;
swap_loop__cond:
	beqz	$t2, swap_loop__end		# while (swapped) {

swap_loop__body:
	li	$t2, 0				#   swapped = 0;
sort_loop__init:
	li	$t0, 1				#   i = 1

sort_loop__cond:
	bge	$t0, ARRAY_LEN, sort_loop__end	#   while (i < ARRAY_LEN) {

	mul	$t1, $t0, 4			#     &numbers[i] = numbers + 4 * i
	lw	$t3, numbers($t1)		#     x = numbers[i]

	addi	$t5, $t1, -4			#     &numbers[i - 1] = &numbers[i] - 4
	lw	$t4, numbers($t5)		#     y = numbers[i - 1]

	bge	$t3, $t4, sort_loop__continue	#     if (x < y) {

	sw	$t4, numbers($t1)		#       numbers[i] = y;
	sw	$t3, numbers($t5)		#       numbers[i - 1] = x;
	li	$t2, 1				#       swapped = 1
						#     }
sort_loop__continue:
	addi	$t0, $t0, 1			#     i++;
	b	sort_loop__cond			#   }
sort_loop__end:
	b	swap_loop__cond			# }

swap_loop__end:
print_loop__init:
	li	$t0, 0				# i = 0
print_loop__cond:
	bge	$t0, ARRAY_LEN, print_loop__end	# while (i < ARRAY_LEN) {

print_loop__body:
	li	$v0, 1				#   syscall 1: print_int
	mul	$t1, $t0, 4			#   &numbers[i] = numbers + 4 * i
	lw	$a0, numbers($t1)		#   
	syscall					#   printf("%d", numbers[i])

	li	$v0, 11				#   syscall 11: print_char
	li	$a0, '\n'
	syscall					#   printf("%c", '\n');

	addi	$t0, $t0, 1			#   i++
	b	print_loop__cond		# }
print_loop__end:
	
	li	$v0, 0
	jr	$ra				# return 0;


	.data
numbers:
	.word	0:ARRAY_LEN			# int numbers[ARRAY_LEN] = {0};
