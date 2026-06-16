#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void preorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

void search(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Elem Not Found\n");
        return;
    }
    if (root->data == key)
    {
        printf("Elem Found %d\n", root->data);
        return;
    }

    if (key < root->data)
    {
        search(root->left, key);
    }
    else if (key > root->data)
    {
        search(root->right, key);
    }
}

struct Node *findMin(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree Is Empty");
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

struct Node *findMax(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree Is Empty");
        return NULL;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

int countNode(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

// int hi(){
//     lh = hi(ro->l);
//     rh = hi(ro->r);

//     if (lh>rh)
//     {
//         return 1+ lh;
//     }
//     else{
//         return 1 + rh;
//     }
// }

struct Node *deleteNode(struct Node *root, int value)
{

    // Base Case
    if (root == NULL)
    {
        return root;
    }
    // Search Node
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        //  NO Child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // one child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{

    int ch, val, key;
    struct Node *root = NULL;
    struct Node *temp = NULL;
    struct Node *min = NULL;
    struct Node *max = NULL;

    do
    {
        printf("====Binary Search Tree Menu====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Inorder\n");
        printf("6. Min Elem\n");
        printf("7. Max Elem\n");
        printf("8. Search\n");
        printf("9. countNode\n\n");
        printf("10. Exit\n\n");

        printf("Enter The Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter The value for insert :");
            scanf("%d", &val);

            root = insert(root, val);

            printf("Inserted Data successfully...\n");
            break;
        case 2:

            printf("Enter The value for Delete :");
            scanf("%d", &val);
            root = deleteNode(root, val);
            
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            /* code */
            break;
        case 5:

            break;
        case 6:
            min = findMin(root);
            printf("Min elem Is : %d\n", min->data);

            break;
        case 7:
            max = findMax(root);
            printf("Max elem Is : %d\n", max->data);

            break;
        case 8:
            printf("Enter The Key For search : ");
            scanf("%d", &key);
            search(root, key);

            break;
        case 9:
            printf("Count Is : %d\n", countNode(root));

            break;
        case 10:
            exit(0);
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (1);

    return 0;
}