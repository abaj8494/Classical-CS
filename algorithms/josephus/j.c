// linked list implementation of the jocephus problem
// input: n = number of prisoners, m = mth person to die

#include <stdlib.h>
#include <stdio.h>


typedef struct node* Node; // you must typedef to the full original. cannot nest

typedef struct node{
    int p;
    Node next;
} node;

void printlist(Node head, int n){
    Node curr = head;
    for (int i = 0; i < n; i++) {
        printf("%d -> ", curr->p);
        curr = curr->next;
    }
    printf("head\n");
}


int main(int argc, char *argv[])
{
    if (argc != 3) {fprintf(stderr, "Usage %s n m\n", argv[0]); return 1;}

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // create head node
    Node head = malloc(sizeof(head));
    head->p = n;
    head->next = head; // making it circular
    Node tail = head; // keeping track of the tail
    // insert rest of nodes
    for (int i = n - 1; i > 0; i--) {
        Node node = malloc(sizeof(node));
        node->p = i;
        node->next = head;
        head = node;
        tail->next = head;
    }
    // printlist(head, n);
    // circular list complete
    

    Node curr = head;
    while (head->next != head) { // while you have more than one person standing
        // printlist(head, n--);
        // get (m - 1)th
        for (int i = 1; i < m - 1; i++) {
            curr = curr->next;
        }
        Node temp = curr->next;
        curr->next = curr->next->next;
        printf("%d ", temp->p);
        curr = temp->next;
        head = curr;
        free(temp);
    }
    printf("\n");
    printf("Prisoner %d lives!\n", head->p);
}
