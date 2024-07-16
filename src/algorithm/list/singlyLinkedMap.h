#ifndef SINGLY_LINKED_MAP_H
#define SINGLY_LINKED_MAP_H

#include "../../memory/memory.h"
#include <stdlib.h>

typedef struct SinglyMapNode
{
    int key;
    int value;
    struct SinglyMapNode *next;
} SinglyMapNode;

typedef struct SinglyLinkedMap
{
    int size;
    SinglyMapNode *head;
} SinglyLinkedMap;

typedef struct SinglyLinkedMapHandlerStruct
{
    SinglyLinkedMap *(*newSinglyLinkedMap)();
    void (*insertSinglyKeyValue)(SinglyLinkedMap *map, int key, int value);
    void (*removeSinglyKeyValue)(SinglyLinkedMap *map);
    bool (*containsSinglyKey)(SinglyLinkedMap *map, int key);
    bool (*isSinglyLinkedMapEmpty)(SinglyLinkedMap *map);
    int (*getSinglyMapValue)(SinglyLinkedMap *map, int key);
    void (*deleteSinglyLinkedMap)(SinglyLinkedMap *map);
} SinglyLinkedMapHandlerStruct;

SinglyLinkedMap *newSinglyLinkedMap()
{
    SinglyLinkedMap *list = (SinglyLinkedMap *)malloc(sizeof(SinglyLinkedMap));
    list->size = 0;
    list->head = NULL;
    return list;
}

SinglyMapNode *newSinglyMapNode(int key, int value)
{
    SinglyMapNode *node = (SinglyMapNode *)malloc(sizeof(SinglyMapNode));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

SinglyMapNode *lastSinglyMapNode(SinglyLinkedMap *map)
{
    SinglyMapNode *head = map->head;
    if (head != NULL)
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
    }
    return head;
}

void insertSinglyKeyValue(SinglyLinkedMap *map, int key, int value)
{
    if (map->size == 0)
    {
        map->head = newSinglyMapNode(key, value);
    }
    else
    {
        SinglyMapNode *node = lastSinglyMapNode(map);
        node->next = newSinglyMapNode(key, value);
    }
    map->size++;
}

void removeSinglyKeyValue(SinglyLinkedMap *map)
{
    if (map->size <= 1)
    {
        free(map->head);
        map->head = NULL;
        map->size = 0;
    }
    else if (map->size > 1)
    {
        SinglyMapNode *secondLastNode = map->head;
        for (int index = 0; index < map->size - 2; index++)
        {
            secondLastNode = secondLastNode->next;
        }
        SinglyMapNode *currentNode = secondLastNode->next;
        free(currentNode);
        secondLastNode->next = NULL;
        map->size--;
    }
}

bool containsSinglyKey(SinglyLinkedMap *map, int key)
{
    if (map->size > 0)
    {
        SinglyMapNode *head = map->head;
        while (head != NULL)
        {
            if (head->key == key)
                return 1;
            head = head->next;
        }
    }
    return 0;
}

int getSinglyMapValue(SinglyLinkedMap *map, int key)
{
    SinglyMapNode *head = map->head;
    while (head != NULL)
    {
        if (head->key == key)
            return head->value;
        head = head->next;
    }
    return -1;
}

bool isSinglyLinkedMapEmpty(SinglyLinkedMap *map)
{
    return map->size <= 0;
}

void deleteSinglyLinkedMap(SinglyLinkedMap *map)
{
    SinglyMapNode *head = map->head;
    while (head != NULL)
    {
        SinglyMapNode *currentNode = head;
        head = head->next;
        free(currentNode);
    }
    map->head = NULL;
    map->size = 0;
    free(map);
}

SinglyLinkedMapHandlerStruct SinglyLinkedMapHandler = {
    .newSinglyLinkedMap = newSinglyLinkedMap,
    .insertSinglyKeyValue = insertSinglyKeyValue,
    .removeSinglyKeyValue = removeSinglyKeyValue,
    .containsSinglyKey = containsSinglyKey,
    .isSinglyLinkedMapEmpty = isSinglyLinkedMapEmpty,
    .getSinglyMapValue = getSinglyMapValue,
    .deleteSinglyLinkedMap = deleteSinglyLinkedMap,
};

extern SinglyLinkedMapHandlerStruct SinglyLinkedMapHandler;

#endif