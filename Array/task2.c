#include <stdio.h>
#include <stdlib.h>
void insertAtPosition(int arr[], int *s, int val, int pos)
{

    if (pos < 0 || pos > *s + 1)
    {
        printf("Invalid Position...");
        return;
    }

    for (int i = *s; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    *s = *s + 1;
}
void display(int arr[], int *s)
{
    for (int i = 0; i < *s; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteAtPosition(int arr[], int *s,int pos)
{

    if (pos < 0 || pos > *s)
    {
        printf("Invalid Position...");
        return;
    }

    for (int i = pos ; i < *s; i++)
    {
        arr[i] = arr[i+1];
    }
    *s = *s - 1;
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    int s = 5;
    int ch, val, pos;

    while (1)
    {
        printf("1. Display\n2. InsertAtPos\n3. DeleteAtPos \n4. Exit\n\n");
        printf("\nEnter the choice  : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            display(arr, &s);
            break;
        case 2:
            printf("Enter The Value : ");
            scanf("%d", &val);
            printf("Enter The pos: ");
            scanf("%d", &pos);
            insertAtPosition(arr, &s, val, pos);
            break;
        case 3:
            printf("Enter The Pos (Based on the 0-index): ");
            scanf("%d", &pos);
            deleteAtPosition(arr, &s, pos);
            break;

        case 4:
            exit(0);
        }
    }

    return 0;
}

//  insertAtPosition
// 2, 10 , 20 , 30 , 40 , 50
// arr[pos] = 2
