#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
    int height;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalance(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct Node *rightRotate(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *T = y->right; // 22

    y->right = x;
    x->left = T;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return y;
}

struct Node *leftRotate(struct Node *y)
{
    struct Node *x = y->right;
    struct Node *T = x->left; // NULL

    y->left = x;
    y->right = T;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

// 30 , 20 , 25

insert(30, 25);

root->left = leftRotate(20);

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    // find
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int bal = getBalance(root);

    if (bal > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }
    if (bal < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }
    if (bal > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bal < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {

        printf("\n====== AVL TREE MENU ======\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted successfully!\n");
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            // printf("Preorder Traversal: ");
            // preorder(root);
            // printf("\n");
            break;

        case 6:
            // printf("Postorder Traversal: ");
            // postorder(root);
            // printf("\n");
            break;

        case 7:
            printf("Program exited.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
