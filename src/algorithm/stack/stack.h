#ifndef STACK_H
#define STACK_H

#include "../../memory/memory.h"
#include "stdbool.h"

typedef struct StackNode
{
    int value;
    struct StackNode *previousNode;
} StackNode;

typedef struct StackStruct
{
    int size;
    StackNode *node;
} Stack;

typedef struct StackHandlerStruct
{
    Stack *(*newStack)();
    void (*push)(Stack *stack, int value);
    void (*pop)(Stack *stack);
    bool (*isEmpty)(Stack *stack);
    int (*peek)(Stack *stack);
    void (*deleteStack)(Stack *stack);
} StackHandlerStruct;

Stack *newStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->node = NULL;
    stack->size = 0;
    return stack;
};

void push(Stack *stack, int value)
{
    StackNode *currentNode = (StackNode *)malloc(sizeof(StackNode));
    currentNode->value = value;
    currentNode->previousNode = stack->node;
    stack->node = currentNode;
    stack->size = stack->size + 1;
}

void pop(Stack *stack)
{
    if (stack->node != NULL)
    {
        StackNode *currentNode = stack->node;
        stack->node = currentNode->previousNode;
        free(currentNode);
        stack->size = stack->size - 1;
    }
}

bool isEmpty(Stack *stack)
{
    return stack->node == NULL && stack->size == 0;
}

int peek(Stack *stack)
{
    if (stack->node != NULL)
        return stack->node->value;
    return -1;
}

void deleteStack(Stack *stack)
{
    while (stack->node != NULL)
    {
        pop(stack);
    }
    free(stack);
};

StackHandlerStruct StackHandler = {
    .newStack = newStack,
    .push = push,
    .pop = pop,
    .peek = peek,
    .isEmpty = isEmpty,
    .deleteStack = deleteStack};

extern StackHandlerStruct StackHandler;

#endif