#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    //     *111
    // null 10 *104 < = > *111  20 null
    //  *104
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void create(int s)
{
    int val;
    for (int i = 1; i <= s; i++)
    {
        printf("Enter The Value : ");
        scanf("%d", &val);
        insertEnd(val);
    }
}

void displayF()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct Node *temp = head;
    printf("NULL <=> ");
    while (temp != NULL)
    {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertFirst(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;

    // head [NULL]
    // head [NULL 20 (*112) ]<=>[(*113) 10 null]
    // [NULL 20 () ]
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtPos(int pos, int val)
{

    if (pos == 1)
    {
        insertFirst(val);
        return;
    }

    struct Node *temp = head;
    //       temp
    // 10 <=> 20 <=> null
    // 2<2
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    //                       temp
    // null <=> 10 <=> 20 <=> 30(*111)<=> 30<40>null
    // 2<2
    // 30<40>null

    //       temp
    // 10 <=> 20 <=> null
    // 2<2
    // 20<40>null
    newNode->prev = temp;
    newNode->next =  temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int main()
{
    int s, val, pos, ch;
    do
    {
        printf("1. Create\n2. InsertEnd\n3. InsertFirst\n4. InsertAtPos\n5. DisplayF\n6. DisplayB\n7. Exit\n\n");
        printf("Enter The Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter The Size of DoublyLL : ");
            scanf("%d", &s);
            create(s);
            break;
        case 2:
            printf("Enter The value: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            printf("Enter The value: ");
            scanf("%d", &val);

            insertFirst(val);
            break;
        case 4:
            printf("Enter The value: ");
            scanf("%d", &val);
            printf("Enter The pos: ");
            scanf("%d", &pos);

            insertAtPos(pos,val);

            break;
        case 5:
            displayF();
            break;
        case 6:
            /* code */
            break;
        case 7:
            exit(0);
            break;

        default:
            printf("Invalid Position...\n");
            break;
        }

    } while (1);

    return 0;
}
