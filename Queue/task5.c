#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int prio;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(int val, int prio)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Heap is Overflow");
        return;
    }
    newNode->data = val;
    newNode->prio = prio;
    newNode->next = NULL;

    if (front == NULL || prio > front->prio)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        struct Node *temp = front;
        // [230,1]
        // [300,3]->[10,2]
        //            t
        while (temp->next != NULL && temp->next->prio >= prio)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d Data inserted & prio is %d", newNode->data, newNode->prio);
}

void display()
{
    if (front == NULL)
    {
        printf("queue is empty");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("[%d(%d)]", temp->data, temp->prio);
        temp = temp->next;
    }
}

int main()
{

    int val, ch, pr;
    do
    {
        printf("\n=== Queue Menu===\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.IsEmpty\n5.Exit\n\n");
        printf("Enter the Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the Value : ");
            scanf("%d", &val);
            printf("Enter the Priority : ");
            scanf("%d", &pr);

            enqueue(val, pr);
            break;
        case 2:
            // dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            // isEmpty();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (1);

    return 0;
}