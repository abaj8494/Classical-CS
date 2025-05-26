#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LEN 100

struct arg_node {
    char data[MAX_LEN];
    struct arg_node *next;
};

struct StackNode {
	int data;
	struct StackNode *next;
};

struct StackNode *tail = NULL;


// my prototypes
void push(int value);
struct StackNode *pop();
void print_stack();

static struct arg_node *strings_to_list(int len, char *strings[]);
int evaluate_reverse_polish_notation(struct arg_node *head);
void free_arg_list(struct arg_node *head);


int negative(int num) {
	return -num;
}

int evaluate_reverse_polish_notation(struct arg_node *head) {
	if (head == NULL) return 0;
	struct arg_node *current = head;
	while (current != NULL) {
		if (strcmp(current->data, "-") == 0) {
			push(negative(pop()->data) + pop()->data);
		}
		else if (strcmp(current->data, "+") == 0) {
			push(pop()->data + pop()->data);
		}
		else if (strcmp(current->data, "/") == 0) {
			push(pop()->data / pop()->data);
		}
		else if (strcmp(current->data, "x") == 0) {
			push(pop()->data * pop()->data);
		}
		else {
			push(atoi(current->data));
		}
		current = current->next;
	}
    
	return tail->data;
}


int main(int argc, char *argv[]) {
    int length = argc - 1;
    struct arg_node *head = strings_to_list(length, &argv[1]);

    printf("%d\n", evaluate_reverse_polish_notation(head));
    free_arg_list(head);

    return 0;
}

// create linked list from array of strings
static struct arg_node *strings_to_list(int len, char *strings[]) {
    struct arg_node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct arg_node *n = malloc(sizeof (*n));
        assert(n != NULL);
        n->next = head;
        strcpy(n->data, strings[i]);
        head = n;
    }
    return head;
}

void free_arg_list(struct arg_node *head) {
    if (head == NULL) return;
    free_arg_list(head->next);
    free(head);
}


void push(int value)
{
	struct StackNode* new = (struct StackNode*)malloc(sizeof(struct StackNode));
	new->data = value;
	new->next = tail;
	tail = new;
}	


struct StackNode *pop()
{
	if (tail == NULL) return NULL;
	struct StackNode *popped = tail;
	tail = tail->next;
	return popped;
}


void print_stack()
{
	if (tail == NULL) return;
	
	struct StackNode *current = tail;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
