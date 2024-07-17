#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../../memory/memory.h"

// Doubly Linked List

typedef struct LinkedNode
{
    int value;
    struct LinkedNode *next;
    struct LinkedNode *previous;
} LinkedNode;

typedef struct LinkedListStruct
{
    int size;
    LinkedNode *head;
    LinkedNode *tail;
} LinkedList;

typedef struct LinkedListHandlerStruct
{
    LinkedList *(*newLinkedList)();
    void (*insertLinkedNodeAtFirst)(LinkedList *list, int value);
    void (*insertLinkedNodeAtLast)(LinkedList *list, int value);
    void (*insertLinkedNodeAt)(LinkedList *list, int value, int position);
    void (*removeFirstLinkedNode)(LinkedList *list);
    void (*removeLastLinkedNode)(LinkedList *list);
    void (*removeLinkedNodeAt)(LinkedList *list, int position);
    int (*peekFirstLinkedNode)(LinkedList *list);
    int (*peekLastLinkedNode)(LinkedList *list);
    int (*peekLinkedNodeAt)(LinkedList *list, int position);
    int (*isLinkedListEmpty)(LinkedList *list);
    int (*containsValue)(LinkedList *list, int value);
    void (*debugLinkedList)(LinkedList *list);
    void (*printLinkedList)(LinkedList *list);
    void (*deleteLinkedList)(LinkedList *list);
} LinkedListHandlerStruct;

LinkedList *newLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

LinkedNode *newLinkedNode(int value)
{
    LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

void insertLinkedNodeOnEmptyList(LinkedList *list, int value)
{
    LinkedNode *node = newLinkedNode(value);
    list->head = node;
    list->tail = node;
    list->size++;
}

void insertLinkedNodeAtFirst(LinkedList *list, int value)
{
    if (list->size == 0)
    {
        insertLinkedNodeOnEmptyList(list, value);
    }
    else
    {
        LinkedNode *node = newLinkedNode(value);
        node->value = value;
        node->next = list->head;
        list->head->previous = node;
        list->head = node;
        list->size++;
    }
}

void insertLinkedNodeAtLast(LinkedList *list, int value)
{
    if (list->size == 0)
    {
        insertLinkedNodeOnEmptyList(list, value);
    }
    else
    {
        LinkedNode *node = newLinkedNode(value);
        node->value = value;
        node->previous = list->tail;
        list->tail->next = node;
        list->tail = node;
        list->size++;
    }
}

LinkedNode *getNodeByTraversingFromLeft(LinkedList *list, int traverseTimes)
{
    LinkedNode *node = list->head;
    for (int index = 0; index < traverseTimes; index++)
    {
        node = node->next;
    }
    return node;
}

LinkedNode *getNodeByTraversingFromRight(LinkedList *list, int traverseTimes)
{
    LinkedNode *node = list->tail;
    for (int index = 0; index < traverseTimes; index++)
    {
        node = node->previous;
    }
    return node;
}

void insertLinkedNodeAt(LinkedList *list, int value, int position)
{
    if (position < list->size)
    {
        if (position == 0)
        {
            insertLinkedNodeAtFirst(list, value);
        }
        else if (position >= list->size)
        {
            insertLinkedNodeAtLast(list, value);
        }
        else
        {
            LinkedNode *currentPositionNode;
            if (list->size / 2 >= position)
            {
                currentPositionNode = getNodeByTraversingFromLeft(list, position);
            }
            else
            {
                currentPositionNode = getNodeByTraversingFromRight(list, list->size - position - 1);
            }
            LinkedNode *newNode = newLinkedNode(value);
            LinkedNode *previousNode = currentPositionNode->previous;
            currentPositionNode->previous = newNode;
            newNode->previous = previousNode;
            newNode->next = currentPositionNode;
            previousNode->next = newNode;
            list->size++;
        }
    }
}

void removeIfOnlySingleNode(LinkedList *list)
{
    LinkedNode *node = list->head;
    free(node);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
}

void removeFirstLinkedNode(LinkedList *list)
{
    if (list->size <= 0)
        return;
    if (list->size == 1)
    {
        removeIfOnlySingleNode(list);
    }
    else
    {
        LinkedNode *node = list->head;
        list->head = node->next;
        list->head->previous = NULL;
        free(node);
        list->size--;
    }
}

void removeLastLinkedNode(LinkedList *list)
{
    if (list->size <= 0)
        return;
    if (list->size == 1)
    {
        removeIfOnlySingleNode(list);
    }
    else
    {
        LinkedNode *node = list->tail;
        list->tail = node->previous;
        list->tail->next = NULL;
        free(node);
        list->size--;
    }
}

void removeLinkedNodeAt(LinkedList *list, int position)
{
    if (position < list->size)
    {
        if (position == 0)
        {
            removeFirstLinkedNode(list);
        }
        else if (position == list->size - 1)
        {
            removeLastLinkedNode(list);
        }
        else
        {
            LinkedNode *currentPositionNode;
            if (list->size / 2 >= position)
            {
                currentPositionNode = getNodeByTraversingFromLeft(list, position);
            }
            else
            {
                currentPositionNode = getNodeByTraversingFromRight(list, list->size - position - 1);
            }
            LinkedNode *previousNode = currentPositionNode->previous;
            LinkedNode *nextPositionNode = currentPositionNode->next;

            previousNode->next = nextPositionNode;
            nextPositionNode->previous = previousNode;
            free(currentPositionNode);
            list->size--;
        }
    }
}

int peekFirstLinkedNode(LinkedList *list)
{
    if (list->size > 0)
        return list->head->value;
    return -1;
}

int peekLastLinkedNode(LinkedList *list)
{
    if (list->size > 0)
        return list->tail->value;
    return -1;
}

int peekLinkedNodeAt(LinkedList *list, int position)
{
    if (position < list->size)
    {
        LinkedNode *currentPositionNode;
        if (list->size / 2 >= position)
        {
            currentPositionNode = getNodeByTraversingFromLeft(list, position);
        }
        else
        {
            currentPositionNode = getNodeByTraversingFromRight(list, list->size - position - 1);
        }
        return currentPositionNode->value;
    }
    return -1;
}

int isLinkedListEmpty(LinkedList *list)
{
    return list->size <= 0;
}

int containsValue(LinkedList *list, int value)
{
    if (list->size > 0)
    {
        LinkedNode *node = list->head;
        while (node != NULL)
        {
            if (node->value == value)
                return 1;
            node = node->next;
        }
    }
    return 0;
}

void debugLinkedList(LinkedList *list)
{
    if (list->size <= 0)
        return;
    printf("----------HEAD----------\n");
    LinkedNode *head = list->head;
    while (head != NULL)
    {
        printf("----------NODE----------\n");
        printf("Current Address: %d\nPrevious Address: %d\nValue: %d\nNext Address: %d\n", head, head->previous, head->value, head->next);
        printf("--------------------\n");
        head = head->next;
    }
    printf("----------TAIL----------\n");
    LinkedNode *tail = list->tail;
    while (tail != NULL)
    {
        printf("----------NODE----------\n");
        printf("Current Address: %d\nPrevious Address: %d\nValue: %d\nNext Address: %d\n", tail, tail->previous, tail->value, tail->next);
        printf("--------------------\n");
        tail = tail->previous;
    }
    printf("------------------------\n");
}

void printLinkedList(LinkedList *list)
{
    if (list->size > 0)
    {
        LinkedNode *node = list->head;
        while (node != NULL)
        {
            printf("%d | ", node->value);
            node = node->next;
        }
        printf("\n");
    }
}

void deleteLinkedList(LinkedList *list)
{
    while (list->head != NULL)
    {
        LinkedNode *node = list->head;
        list->head = node->next;
        free(node);
    }
    list->tail = NULL;
    free(list);
}

LinkedListHandlerStruct LinkedListHandler = {
    .newLinkedList = newLinkedList,
    .insertLinkedNodeAtFirst = insertLinkedNodeAtFirst,
    .insertLinkedNodeAtLast = insertLinkedNodeAtLast,
    .insertLinkedNodeAt = insertLinkedNodeAt,
    .removeFirstLinkedNode = removeFirstLinkedNode,
    .removeLastLinkedNode = removeLastLinkedNode,
    .removeLinkedNodeAt = removeLinkedNodeAt,
    .peekFirstLinkedNode = peekFirstLinkedNode,
    .peekLastLinkedNode = peekLastLinkedNode,
    .peekLinkedNodeAt = peekLinkedNodeAt,
    .isLinkedListEmpty = isLinkedListEmpty,
    .containsValue = containsValue,
    .debugLinkedList = debugLinkedList,
    .printLinkedList = printLinkedList,
    .deleteLinkedList = deleteLinkedList,
};

extern LinkedListHandlerStruct LinkedListHandler;

#endif