#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "stdio.h"
#include "../../memory/memory.h"

typedef struct BinaryTreeNode
{
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef struct BinaryTreeStruct
{
    int size;
    struct BinaryTreeNode *root;
} BinaryTree;

typedef struct BinaryTreeHandlerStruct
{
    BinaryTree *(*newBinaryTree)();
    void (*insertValueInBinaryTree)(BinaryTree *tree, int value);
    void (*traverseBinaryTree)(BinaryTree *tree);
    int (*searchBinaryTree)(BinaryTree *tree, int value);
    void (*deleteBinaryTree)(BinaryTree *tree);
} BinaryTreeHandlerStruct;

BinaryTree *newBinaryTree()
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

BinaryTreeNode *newBinaryTreeNode(int value)
{
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTreeNode *getAddingNodeFromBinaryTree(BinaryTreeNode *root, int value)
{
    if (root->left != NULL && root->value >= value)
        return getAddingNodeFromBinaryTree(root->left, value);
    if (root->right != NULL && root->value < value)
        return getAddingNodeFromBinaryTree(root->right, value);
    return root;
}

void insertValueInBinaryTree(BinaryTree *tree, int value)
{
    if (tree->size == 0)
    {
        tree->root = newBinaryTreeNode(value);
        tree->size++;
    }
    else
    {
        BinaryTreeNode *addingNode = getAddingNodeFromBinaryTree(tree->root, value);
        if (value < addingNode->value)
        {
            addingNode->left = newBinaryTreeNode(value);
        }
        else
        {
            addingNode->right = newBinaryTreeNode(value);
        }
        tree->size++;
    }
}

void preTraverseBinaryTreeAndPrintValues(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printf("%d | ", root->value);
        preTraverseBinaryTreeAndPrintValues(root->left);
        preTraverseBinaryTreeAndPrintValues(root->right);
    }
}

void traverseBinaryTree(BinaryTree *tree)
{
    if (tree->size > 0)
    {
        preTraverseBinaryTreeAndPrintValues(tree->root);
    }
}

int preTraversalSearchInBinaryTree(BinaryTreeNode *node, int value)
{
    if (node == NULL)
        return 0;
    if (value == node->value)
        return 1;
    return preTraversalSearchInBinaryTree(node->left, value) || preTraversalSearchInBinaryTree(node->right, value);
}

int searchBinaryTree(BinaryTree *tree, int value)
{
    return preTraversalSearchInBinaryTree(tree->root, value);
}

void deleteAllBinaryTreeNode(BinaryTreeNode *node)
{
    if (node != NULL)
    {
        deleteAllBinaryTreeNode(node->left);
        deleteAllBinaryTreeNode(node->right);
        free(node);
    }
}

void deleteBinaryTree(BinaryTree *tree)
{
    if (tree->root != NULL)
    {
        deleteAllBinaryTreeNode(tree->root);
    }
}

BinaryTreeHandlerStruct BinaryTreeHandler = {
    .newBinaryTree = newBinaryTree,
    .insertValueInBinaryTree = insertValueInBinaryTree,
    .traverseBinaryTree = traverseBinaryTree,
    .searchBinaryTree = searchBinaryTree,
    .deleteBinaryTree = deleteBinaryTree,
};

extern BinaryTreeHandlerStruct BinaryTreeHandler;

#endif