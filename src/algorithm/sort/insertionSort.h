#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "../../arrays/arrays.h"

typedef struct InsertionSortStruct
{
    void (*insertionSort)(int values[], int arraySize);
} InsertionSortStruct;

void insertionSort(int values[], int arraySize)
{
    int arrayLength = Arrays.totalIntegers(arraySize);
    for (int loop = 1; loop < arrayLength; loop++)
    {
        int checkIndex = loop;
        while ((values[checkIndex] < values[checkIndex - 1]) && checkIndex > 0)
        {
            int currentValue = values[checkIndex];
            values[checkIndex] = values[checkIndex - 1];
            values[checkIndex - 1] = currentValue;
            checkIndex--;
        }
    }
};

InsertionSortStruct InsertionSort = {
    .insertionSort = insertionSort,
};

extern InsertionSortStruct InsertionSort;

#endif