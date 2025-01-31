CC	?= clang
CFLAGS	?= -O3 -fvisibility=hidden
LDFLAGS	?= -s -static
LIBS	?= -lm

THIS	?= minesweeper

.SUFFIXES:
.SUFFIXES: .c

#
# We can't build `cs_paint' in prod:public because the rsync(1) from
# prod:private drops the solutions -- and apparently the binaries too.
#

.PHONY: all
all::	bin/${THIS}

ifeq (,$(findstring /public/, $(realpath ${PWD})))
bin/${THIS}:	solutions/${THIS}.c
	install -d -m 755 bin
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ${LIBS}
else
PRIVATE_DIR	= ../../../private

bin/${THIS}:	${PRIVATE_DIR}/activities/${THIS}/bin/${THIS}
	install -d -m 755 bin
	install $< -m 755 $@
endif

.PHONY:	clean
clean::
	-rm -f ${THIS}


.PHONY: autotest/tests.txt
autotest/tests.txt: generate_test_file minesweeper $(glob tests/*) autotest_update_from_solution
	sh generate_test_file
	mv tests.txt $@

# all::	tests.zip
# TESTS	:= $(sort $(wildcard tests/*/*.in))
# tests.zip: ${TESTS}
#	@zip -r $@ $^
