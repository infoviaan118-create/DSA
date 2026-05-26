#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *head)
{
    // [10,*] -> [22,*]->  [32,*] ->  [44 ,*] ->[ 53,NULL]
    struct Node *temp = head;
    while (temp != NULL)
    {
        //              n5->data
        printf("%d -> ", temp->data);
        temp = temp->next;
        // NULL
    }
    printf("NULL\n");
}
void printEvenLoc(struct Node *head)
{
    struct Node *temp = head;
    int loc = 1;
    while (temp!=NULL)
    {
        if (loc%2==0)
        {
            printf("%d -> ",temp->data);
        }
        temp  = temp->next;
        loc++;
    }
}

    int main()
{

    struct Node n1, n2, n3, n4, n5;
    n1.data = 10;
    n2.data = 21;
    n3.data = 32;
    n4.data = 44;
    n5.data = 53;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    // printf("%d -> ",n1.data);
    // printf("%d -> ",n1.next->data);
    // printf("%d -> ",n1.next->next->data);
    // printf("%d -> ",n1.next->next->next->data);
    // printf("%d -> ",n1.next->next->next->next->data);
    // printf("%d",n1.next->next->next->next->next);

    display(&n1);
    printEvenLoc(&n1);



    return 0;
}