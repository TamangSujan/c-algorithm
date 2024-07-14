#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "../../arrays/arrays.h"

typedef struct SelectionSortStruct
{
    void (*selectionSort)(int values[], int arraySize);
} SelectionSortStruct;

void selectionSort(int values[], int arraySize)
{
    int arrayLength = Arrays.totalIntegers(arraySize);
    for (int loop = 0; loop < arrayLength - 1; loop++)
    {
        int minIndex = loop;
        for (int index = loop; index < arrayLength - 1; index++)
        {
            if (values[minIndex] > values[index + 1])
            {
                minIndex = index + 1;
            }
        }
        if (minIndex != loop)
        {
            int currentValue = values[loop];
            values[loop] = values[minIndex];
            values[minIndex] = currentValue;
        }
    }
};

SelectionSortStruct SelectionSort = {
    .selectionSort = selectionSort,
};

extern SelectionSortStruct SelectionSort;

#endif