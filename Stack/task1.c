#include <stdio.h>
#include <stdlib.h>
#define Max 3

int stack[Max];
int top = -1;

void push(int data)
{
    if (top == Max - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("Data Added\n\n");
}
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Elements Are: \n");
    for (int i = top; i >= 0; i--)
    {
        printf("|%d|\n", stack[i]);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Underflow\n");
        return;
    }
    printf("Poped Out %d\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Top Elem is %d\n", stack[top]);
}

void isEmpty(){
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }else{
        printf("Stack is Not Empty\n");
    }
}
void isFull(){
    if (top == Max-1)
    {
        printf("Stack is Full \n");
    }else{
        printf("Stack is Not Full\n");
    }
}
int main()
{
    int ch, data;
    do
    {
        printf("====Stack Menu====\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n\n");
        printf("Enter The Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter The Data : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (1);

    return 0;
}