#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Heap is Overflow");
        return;
    }

    newNode->data = val;
    if (front == NULL)
    {
        rear = front = newNode;
        newNode->next = newNode;
    }
    else
    {

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Data inserted %d", val);
}

void display()
{
    if (front == NULL)
    {
        printf("Circular Queue Empty\n");
        return;
    }
    struct Node *temp = front;
    // f10 20 30f
    //         r
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}
void dequeue()
{
    if (front == NULL)
    {
        printf("Circular Queue Empty\n");
        return;
    }

    if (front == rear)
    {
        printf("%d data dequeue", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct Node *temp = front;
        printf("%d data dequeue", temp->data);
        front = temp->next;
        rear->next= front;
        free(temp);
    }
}

int main()
{

    int val, ch;
    do
    {
        printf("\n===Circular Queue Menu===\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.IsEmpty\n5.Exit\n\n");
        printf("Enter the Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the Value : ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
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