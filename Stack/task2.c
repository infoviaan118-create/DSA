#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Heap OverFlow");
        return;
    }

    //
    // top->30*106-> 20 [*104]-> 10 null
    newNode->data = val;
    newNode->next = top;
    top = newNode;

    printf("Data is Insetred into stack\n\n");
}
void pop()
{

    if (top == NULL)
    {
        printf("Stack is UnderFlow");
        return;
    }
    struct Node *temp = top;
    printf("Popout %d", top->data);

    top = top->next;
    free(temp);
}

void create(int s)
{
    int val;
    for (int i = 1; i <= s; i++)
    {
        printf("Enter The Data : ");
        scanf("%d", &val);
        push(val);
    }
}
void peek()
{

    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top elem is %d", top->data);
}
void isFull()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Full(Heap OverFlow)\n");
    }
    else
    {
        free(newNode);
        printf("Stack Is Not Full\n");
    }
}
void isEmpty()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is Not Empty\n");
    }
}
void display()
{
    if (top == NULL)
    {
        printf("Stack Is Empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack Elems Are : \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{

    int ch, data, s;
    do
    {
        printf("\n====Dynamic Stack Menu====\n");
        printf("1. Create\n2. Display\n3. Push\n4. Pop\n5. Peek\n6. isFull\n7. IsEmpty\n8. Exit\n\n");
        printf("Enter The Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("How many elems you want to insert into stack : ");
            scanf("%d", &s);
            create(s);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter The Data : ");
            scanf("%d", &data);
            push(data);
            break;
        case 4:
            pop();
            break;
        case 5:
            peek();
            break;
        case 6:
            isFull();
            break;
        case 7:
            isEmpty();
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (1);

    return 0;
}