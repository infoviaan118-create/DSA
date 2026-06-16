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
    if (root==NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}





int main()
{
    struct Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(90);
    root->left->right = createNode(60);

    root->right->right = createNode(50);

    // preorder(root);
    // printf("NULL\n");

    // postorder(root);
    // printf("NULL\n");

    inorder(root);
    printf("NULL\n");
    return 0;
}