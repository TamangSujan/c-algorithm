#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "../../memory/memory.h"
#include <stdlib.h>

typedef struct SinglyNode
{
    int value;
    struct SinglyNode *next;
} SinglyNode;

typedef struct SinglyLinkedList
{
    int size;
    SinglyNode *head;
} SinglyLinkedList;

typedef struct SinglyLinkedListHandlerStruct
{
    SinglyLinkedList *(*newSinglyLinkedList)();
    void (*insertSinglyItem)(SinglyLinkedList *list, int value);
    void (*insertSinglyItemAt)(SinglyLinkedList *list, int value, int position);
    void (*removeSinglyItem)(SinglyLinkedList *list);
    void (*removeSinglyItemAt)(SinglyLinkedList *list, int position);
    bool (*containsSinglyItem)(SinglyLinkedList *list, int value);
    bool (*isSinglyLinkedListEmpty)(SinglyLinkedList *list);
    int (*peekSinglyItem)(SinglyLinkedList *list);
    int (*peekSinglyItemAt)(SinglyLinkedList *list, int position);
    void (*deleteSinglyLinkedList)(SinglyLinkedList *list);
} SinglyLinkedListHandlerStruct;

SinglyLinkedList *newSinglyLinkedList()
{
    SinglyLinkedList *list = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

SinglyNode *newSinglyNode(int value)
{
    SinglyNode *node = (SinglyNode *)malloc(sizeof(SinglyNode));
    node->value = value;
    node->next = NULL;
    return node;
}

SinglyNode *lastSinglyNode(SinglyLinkedList *list)
{
    SinglyNode *head = list->head;
    if (head != NULL)
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
    }
    return head;
}

void insertSinglyItem(SinglyLinkedList *list, int value)
{
    if (list->size == 0)
    {
        list->head = newSinglyNode(value);
    }
    else
    {
        SinglyNode *node = lastSinglyNode(list);
        node->next = newSinglyNode(value);
    }
    list->size++;
}

void insertSinglyItemAt(SinglyLinkedList *list, int value, int position)
{
    if (position >= list->size)
    {
        insertSinglyItem(list, value);
    }
    else
    {
        SinglyNode *positionNode = list->head;
        for (int index = 0; index < position - 1; index++)
        {
            positionNode = positionNode->next;
        }
        SinglyNode *nextNode = positionNode->next;
        SinglyNode *newNode = newSinglyNode(value);
        positionNode->next = newNode;
        newNode->next = nextNode;
        list->size++;
    }
}

void removeSinglyItem(SinglyLinkedList *list)
{
    if (list->size <= 1)
    {
        free(list->head);
        list->head = NULL;
        list->size = 0;
    }
    else if (list->size > 1)
    {
        SinglyNode *secondLastNode = list->head;
        for (int index = 0; index < list->size - 2; index++)
        {
            secondLastNode = secondLastNode->next;
        }
        SinglyNode *currentNode = secondLastNode->next;
        free(currentNode);
        secondLastNode->next = NULL;
        list->size--;
    }
}

void removeSinglyItemAt(SinglyLinkedList *list, int position)
{
    if (position >= list->size)
    {
        removeSinglyItem(list);
    }
    else if (position == 1 && list->size > 0)
    {
        SinglyNode *head = list->head;
        list->head = head->next;
        free(head);
        list->size--;
    }
    else
    {
        SinglyNode *positionNode = list->head;
        for (int index = 0; index < position - 1; index++)
        {
            positionNode = positionNode->next;
        }
        SinglyNode *nextNode = positionNode->next;
        positionNode->next = nextNode->next;
        free(nextNode);
        list->size--;
    }
}

bool containsSinglyItem(SinglyLinkedList *list, int value)
{
    if (list->size > 0)
    {
        SinglyNode *head = list->head;
        while (head->next != NULL)
        {
            if (head->value == value)
                return 1;
            head = head->next;
        }
    }
    return 0;
}

bool isSinglyLinkedListEmpty(SinglyLinkedList *list)
{
    return list->size <= 0;
}

int peekSinglyItem(SinglyLinkedList *list)
{
    if (list->size > 0)
    {
        SinglyNode *node = lastSinglyNode(list);
        return node->value;
    }
    return -1;
}

int peekSinglyItemAt(SinglyLinkedList *list, int position)
{
    if (list->size == 0)
        return -1;
    if (position >= list->size)
    {
        SinglyNode *node = lastSinglyNode(list);
        return node->value;
    }
    SinglyNode *positionNode = list->head;
    for (int index = 0; index < position; index++)
    {
        positionNode = positionNode->next;
    }
    return positionNode->value;
}

void deleteSinglyLinkedList(SinglyLinkedList *list)
{
    SinglyNode *head = list->head;
    while (head != NULL)
    {
        SinglyNode *currentNode = head;
        head = head->next;
        free(currentNode);
    }
    list->head = NULL;
    list->size = 0;
    free(list);
}

SinglyLinkedListHandlerStruct SinglyLinkedListHandler = {
    .newSinglyLinkedList = newSinglyLinkedList,
    .insertSinglyItem = insertSinglyItem,
    .insertSinglyItemAt = insertSinglyItemAt,
    .removeSinglyItem = removeSinglyItem,
    .removeSinglyItemAt = removeSinglyItemAt,
    .containsSinglyItem = containsSinglyItem,
    .isSinglyLinkedListEmpty = isSinglyLinkedListEmpty,
    .peekSinglyItem = peekSinglyItem,
    .peekSinglyItemAt = peekSinglyItemAt,
    .deleteSinglyLinkedList = deleteSinglyLinkedList};

extern SinglyLinkedListHandlerStruct SinglyLinkedListHandler;

#endif