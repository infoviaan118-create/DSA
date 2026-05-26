#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(int val, int prio)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = val;
    newNode->priority = prio;
    newNode->next = NULL;

    if (front == NULL || prio > front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        struct Node *temp = front;
        while (temp != NULL && temp->next->priority >= prio)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("%d inserted with priority %d\n", value, priority);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted: %d (priority %d)\n", temp->data, temp->priority);

    front = front->next;
    free(temp);
}

int main()
{

    return 0;
}
