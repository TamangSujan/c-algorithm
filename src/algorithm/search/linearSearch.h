#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "../../arrays/arrays.h"

typedef struct LinearSearchStruct
{
    int (*linearSearch)(int array[], int value, int arraySize);
} LinearSearchStruct;

int linearSearch(int array[], int value, int arraySize)
{
    int totalIntegers = Arrays.totalIntegers(arraySize);
    for (int index = 0; index < totalIntegers; index++)
    {
        if (value == array[index])
            return index;
    }
    return -1;
}

LinearSearchStruct LinearSearch = {
    .linearSearch = linearSearch,
};

extern LinearSearchStruct LinearSearch;

#endif