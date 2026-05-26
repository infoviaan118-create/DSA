#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void insertAtFirst(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int val)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;  // 14
    newNode->next = NULL; // NULL

    if (head == NULL)
    {
        head = newNode; // head[12,NULL]
        return;
    }

    //       111         temp [104]
    // head[12,*104] , *104[13, *112] -> *112[14 ,NULL]
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next; //
    }

    temp->next = newNode;
}

void create(int s)
{
    int val; // 13
    for (int i = 1; i <= s; i++)
    {
        printf("Enter The Value : ");
        scanf("%d", &val);
        insertAtEnd(val); // 14
    }
}

void insertAtPos(int val, int pos)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;

    if (pos == 1)
    {
        insertAtFirst(val);
        return;
    }
    struct Node *temp = head;
    // temp
    // head[12,*104]  ,  *104[13,NULL] ,
    // pos = 5 ,*111[33,NULL]
    //              2<4
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next; // temp=NULL
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    //
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFirst()
{

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    head = temp->next;
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (pos == 1)
    {
        deleteAtFirst();
        return;
    }
    struct Node *temp = head;
    //                                      temp
    //  head[12,*104] -> *104[13,*106] -> *106[16,NULL]
    // pos = 4 , 3<3
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    // *104[13,*106]
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display()
{
    if (head == NULL)
    {
        printf("List Is Empty...\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, s, val, pos;
    do
    {
        printf("====LL Menu====\n");
        printf("1. Create\n2. InsertAtEnd\n3. InsertAtFirst\n4. Display\n5. InsertAtPos\n6. deleteAtFirst\n7. deleteAtEnd\n8. deleteAtPos\n11.exit\n\n");
        printf("Enter The Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter The List Size : ");
            scanf("%d", &s); // 3
            create(s);
            break;
        case 2:
            printf("Enter The Val : ");
            scanf("%d", &val);
            insertAtEnd(val);
            break;
        case 3:
            printf("Enter The Val : ");
            scanf("%d", &val);
            insertAtFirst(val);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Enter The Val : ");
            scanf("%d", &val);
            printf("Enter The POS : ");
            scanf("%d", &pos);
            insertAtPos(val, pos);
            break;

        case 6:
            deleteAtFirst();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            printf("Enter The POS : ");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;
        case 11:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}
