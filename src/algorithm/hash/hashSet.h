#ifndef HASH_SET_H
#define HASH_SET_H

#include "../list/singlyLinkedList.h"

typedef struct HashSetStruct
{
    int size;
    SinglyLinkedList **list;
} HashSet;

typedef struct HashSetHandlerStruct
{
    HashSet *(*newHashSet)(int size);
    void (*addValueOnHashSet)(HashSet *set, int value);
    int (*getValueFromHashSet)(HashSet *set, int value);
    void (*deleteHashSet)(HashSet *hashTable);
} HashSetHandlerStruct;

int hashIntegerFunction(int value, int bucketSize)
{
    return value % bucketSize;
}

HashSet *newHashSet(int size)
{
    HashSet *set = (HashSet *)malloc(sizeof(HashSet));
    set->list = (SinglyLinkedList **)malloc(size * sizeof(SinglyLinkedList *));
    for (int index = 0; index < size; index++)
    {
        set->list[index] = SinglyLinkedListHandler.newSinglyLinkedList();
    }
    set->size = size;
    return set;
}

void addValueOnHashSet(HashSet *set, int value)
{
    int hashIndex = hashIntegerFunction(value, set->size);
    int nullValue = set->list[hashIndex] == NULL;
    if (SinglyLinkedListHandler.containsSinglyItem(set->list[hashIndex], value) == 0)
    {
        SinglyLinkedListHandler.insertSinglyItem(set->list[hashIndex], value);
    }
}

int getValueFromHashSet(HashSet *set, int value)
{
    int hashIndex = hashIntegerFunction(value, set->size);
    if (SinglyLinkedListHandler.containsSinglyItem(set->list[hashIndex], value) == 1)
        return value;
    return -1;
}

void deleteHashSet(HashSet *set)
{
    for (int index = 0; index < set->size; index++)
    {
        SinglyLinkedList *list = set->list[index];
        free(list);
    }
    free(set);
}

HashSetHandlerStruct HashSetHandler = {
    .newHashSet = newHashSet,
    .addValueOnHashSet = addValueOnHashSet,
    .getValueFromHashSet = getValueFromHashSet,
    .deleteHashSet = deleteHashSet,
};

extern HashSetHandlerStruct HashSetHandler;

#endif