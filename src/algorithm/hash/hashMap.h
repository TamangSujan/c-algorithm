#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "../list/singlyLinkedMap.h"

typedef struct HashMapStruct
{
    int size;
    SinglyLinkedMap **map;
} HashMap;

typedef struct HashMapHandlerStruct
{
    HashMap *(*newHashMap)(int size);
    void (*addValueOnHashMap)(HashMap *map, int key, int value);
    int (*getValueFromHashMap)(HashMap *map, int key);
    void (*deleteHashMap)(HashMap *hashMap);
} HashMapHandlerStruct;

int hashMapIntegerFunction(int key, int bucketSize)
{
    return key % bucketSize;
}

HashMap *newHashMap(int size)
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->map = (SinglyLinkedMap **)malloc(size * sizeof(SinglyLinkedMap *));
    for (int index = 0; index < size; index++)
    {
        map->map[index] = SinglyLinkedMapHandler.newSinglyLinkedMap();
    }
    map->size = size;
    return map;
}

void addValueOnHashMap(HashMap *map, int key, int value)
{
    int hashIndex = hashMapIntegerFunction(key, map->size);
    if (SinglyLinkedMapHandler.containsSinglyKey(map->map[hashIndex], key) == 0)
    {
        SinglyLinkedMapHandler.insertSinglyKeyValue(map->map[hashIndex], key, value);
    }
}

int getValueFromHashMap(HashMap *map, int key)
{
    int hashIndex = hashMapIntegerFunction(key, map->size);
    if (SinglyLinkedMapHandler.containsSinglyKey(map->map[hashIndex], key) == 1)
        return SinglyLinkedMapHandler.getSinglyMapValue(map->map[hashIndex], key);
    return -1;
}

void deleteHashMap(HashMap *map)
{
    for (int index = 0; index < map->size; index++)
    {
        SinglyLinkedMap *singlyMap = map->map[index];
        free(singlyMap);
    }
    free(map);
}

HashMapHandlerStruct HashMapHandler = {
    .newHashMap = newHashMap,
    .addValueOnHashMap = addValueOnHashMap,
    .getValueFromHashMap = getValueFromHashMap,
    .deleteHashMap = deleteHashMap,
};

extern HashMapHandlerStruct HashMapHandler;

#endif