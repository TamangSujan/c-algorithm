#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "stdio.h"
#include "../../memory/memory.h"

typedef struct AvlTreeNodeStruct
{
    int value;
    struct AvlTreeNodeStruct *left;
    struct AvlTreeNodeStruct *right;
} AvlTreeNode;

typedef struct AvlTreeStruct
{
    int size;
    AvlTreeNode *root;
} AvlTree;

typedef struct AvlTreeHandlerStruct
{
    AvlTree *(*newAvlTree)();
    int (*getAvlTreeSize)(AvlTree *tree);
    int (*getAvlTreeHeight)(AvlTree *tree);
    void (*insertValueInAvlTree)(AvlTree *tree, int value);
    void (*deleteValueFromAvlTree)(AvlTree *tree, int value);
    void (*printAvlTree)(AvlTree *tree);
    void (*deleteAvlTree)(AvlTree *tree);
} AvlTreeHandlerStruct;

int getAvlTreeMaxValue(int a, int b)
{
    return a > b ? a : b;
}

int getAvlTreeHeightFromNode(AvlTreeNode *node)
{
    if (node == NULL)
        return -1;
    return 1 + getAvlTreeMaxValue(getAvlTreeHeightFromNode(node->left), getAvlTreeHeightFromNode(node->right));
}

int getAvlTreeSize(AvlTree *tree)
{
    return tree->size;
}

int getAvlTreeHeight(AvlTree *tree)
{
    return getAvlTreeHeightFromNode(tree->root);
}

int getAvlTreeBalance(AvlTreeNode *node)
{
    if (node == NULL)
        return 0;
    return getAvlTreeHeightFromNode(node->left) - getAvlTreeHeightFromNode(node->right);
}

AvlTree *newAvlTree()
{
    AvlTree *tree = (AvlTree *)malloc(sizeof(AvlTree));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

AvlTreeNode *getParentNodeAfterLeftRotation(AvlTreeNode *node)
{
    if (node == NULL || node->right == NULL)
        return node;
    AvlTreeNode *parent = node->right;
    AvlTreeNode *parentLeftChild = parent->left;
    node->right = parentLeftChild;
    parent->left = node;
    return parent;
}

AvlTreeNode *getParentNodeAfterRightRotation(AvlTreeNode *node)
{
    if (node == NULL || node->left == NULL)
        return node;
    AvlTreeNode *parent = node->left;
    AvlTreeNode *parentRightChild = parent->right;
    node->left = parentRightChild;
    parent->right = node;
    return parent;
}

AvlTreeNode *newAvlTreeNode(int value)
{
    AvlTreeNode *node = (AvlTreeNode *)malloc(sizeof(AvlTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

AvlTreeNode *balanceAvlTreeAndReturnRoot(AvlTreeNode *root, int value)
{
    int balance = getAvlTreeBalance(root);

    if (balance > 1 && value < root->left->value)
    {
        return getParentNodeAfterRightRotation(root);
    }

    if (balance < -1 && value > root->right->value)
    {
        return getParentNodeAfterLeftRotation(root);
    }

    if (balance > 1 && value > root->left->value)
    {
        root->left = getParentNodeAfterLeftRotation(root->left);
        return getParentNodeAfterRightRotation(root);
    }

    if (balance < -1 && value < root->right->value)
    {
        root->right = getParentNodeAfterRightRotation(root->right);
        return getParentNodeAfterLeftRotation(root);
    }
    return root;
}

AvlTreeNode *recursiveInsertAvlTree(AvlTreeNode *root, int value)
{
    if (root == NULL)
    {
        return newAvlTreeNode(value);
    }
    if (value < root->value)
    {
        root->left = recursiveInsertAvlTree(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = recursiveInsertAvlTree(root->right, value);
    }
    return balanceAvlTreeAndReturnRoot(root, value);
}

void insertValueInAvlTree(AvlTree *tree, int value)
{
    tree->root = recursiveInsertAvlTree(tree->root, value);
    tree->size++;
}

AvlTreeNode *getLeftMostNode(AvlTreeNode *node)
{
    AvlTreeNode *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

AvlTreeNode *recursiveDeleteAvlTree(AvlTreeNode *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->value)
    {
        root->left = recursiveDeleteAvlTree(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = recursiveDeleteAvlTree(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            AvlTreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            AvlTreeNode *temp = root->left;
            free(root);
            return temp;
        }
        AvlTreeNode *temp = getLeftMostNode(root->right);
        root->value = temp->value;
        root->right = recursiveDeleteAvlTree(root->right, temp->value);
    }

    return balanceAvlTreeAndReturnRoot(root, value);
}

void deleteValueFromAvlTree(AvlTree *tree, int value)
{
    tree->root = recursiveDeleteAvlTree(tree->root, value);
    tree->size--;
}

void preTraversalPringAvlTreeNode(AvlTreeNode *node)
{
    if (node != NULL)
    {
        printf("%d | ", node->value);
        preTraversalPringAvlTreeNode(node->left);
        preTraversalPringAvlTreeNode(node->right);
    }
}

void printAvlTree(AvlTree *tree)
{
    printf("Avl Tree Size: %d\n", getAvlTreeSize(tree));
    printf("Avl Tree Height: %d\n", getAvlTreeHeight(tree));
    printf("Avl Tree Balance: %d\n", getAvlTreeBalance(tree->root));
    preTraversalPringAvlTreeNode(tree->root);
    printf("\n------------------------------\n");
}

void postTraversalDeleteAvlTreeNode(AvlTreeNode *root)
{
    if (root != NULL)
    {
        postTraversalDeleteAvlTreeNode(root->left);
        postTraversalDeleteAvlTreeNode(root->right);
        root->left = NULL;
        root->right = NULL;
        free(root);
    }
}

void deleteAvlTree(AvlTree *tree)
{
    postTraversalDeleteAvlTreeNode(tree->root);
    tree->size = 0;
    tree->root = NULL;
    free(tree);
}

AvlTreeHandlerStruct AvlTreeHandler = {
    .newAvlTree = newAvlTree,
    .getAvlTreeSize = getAvlTreeSize,
    .getAvlTreeHeight = getAvlTreeHeight,
    .insertValueInAvlTree = insertValueInAvlTree,
    .printAvlTree = printAvlTree,
    .deleteValueFromAvlTree = deleteValueFromAvlTree,
    .deleteAvlTree = deleteAvlTree,
};

extern AvlTreeHandlerStruct AvlTreeHandler;

#endif