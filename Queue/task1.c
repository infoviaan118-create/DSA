#include <stdio.h>
#include <stdlib.h>
#define Max 3

int queue[Max];
int front = -1, rear = -1;

void enqueue(int val)
{
    // 2 == 2
    if (rear == Max - 1)
    {
        printf("Queue is Overflow\n");
        return;
    }
    else
    { // 10
        //  f[10] , [20] , [30]
        //                  r
        if (front == -1) // f
        {
            front++;// 0
        }     
         
        rear++; // 2
            queue[rear] = val;
    }
}
void dequeue(){
    if (front==-1 || front > rear)
    {
        printf("Queue is underflow\n");
        return;
    }   

    printf("%d Deleted\n",queue[front]);
    front++;
}

void display(){
    if (front == -1 || front > rear)
    {
       printf("Queue is empty\n");
       return;
    }
    printf("Queue Elements Are\n");
    for (int i = front; i <= rear; i++)
    {
        printf("[ %d ],",queue[i]);
    }
    printf("\n");
}

void isEmpty(){
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }else{
        printf("Queue is not-empty\n");
    }
}

int main()
{

    int val, ch;

    do
    {
        printf("\n===Queue Menu===\n");
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
            isEmpty();
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