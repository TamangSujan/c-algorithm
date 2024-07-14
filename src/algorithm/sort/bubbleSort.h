#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../../arrays/arrays.h"

typedef struct BubbleSortStruct
{
    void (*bubbleSort)(int values[], int arraySize);
} BubbleSortStruct;

void bubbleSort(int values[], int arraySize)
{
    int arrayLength = Arrays.totalIntegers(arraySize);
    for (int loop = 0; loop < arrayLength - 1; loop++)
    {
        for (int index = 0; index < arrayLength - loop; index++)
        {
            if (values[index] > values[index + 1])
            {
                int currentValue = values[index];
                values[index] = values[index + 1];
                values[index + 1] = currentValue;
            }
        }
    }
};

BubbleSortStruct BubbleSort = {
    .bubbleSort = bubbleSort,
};

extern BubbleSortStruct BubbleSort;

#endif