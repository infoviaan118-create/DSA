#include <stdio.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void displayForword(struct Node *head){
    if (head == NULL )
    {   
        printf("Empty List\n");
        return;
    }

    struct Node *temp = head;

    printf("NULL <=> ");
    while (temp != NULL)
    {
        printf("%d <=> ",temp->data);
        temp = temp->next;
    }   
    printf("NULL\n");
}


int main() {

    // struct Node n1,n2,n3,n4;

    // n1.prev = NULL;
    // n1.data = 10;
    // n1.next = &n2;

    // n2.prev = &n1;
    // n2.data = 20;
    // n2.next = &n3;

    // n3.prev = &n2;
    // n3.data = 30;
    // n3.next = &n4;

    // n4.prev = &n3;
    // n4.data = 40;
    // n4.next = NULL;

    // printf("%d " , n1.next->next->next->next);

    // displayForword(&n1);









    return 0;
}