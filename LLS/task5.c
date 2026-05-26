#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *head)
{
    struct Node *temp = head;
    // t10
    // 10 20 30
    do
    {
        printf("%d->", temp->data); // 10 20 30
        temp = temp->next;

    } while (temp!= head);
    printf("Head\n");
}

int main()
{

    struct Node n1, n2, n3;

    n1.data = 10;
    n1.next = &n2;

    n2.data = 20;
    n2.next = &n3;

    n3.data = 30;
    n3.next = &n1;

    display(&n1);

    return 0;
}