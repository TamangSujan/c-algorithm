#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "../../arrays/arrays.h"
#include "stdio.h"

typedef struct CountingSortStruct
{
    void (*countingSort)(int values[], int arraySize);
} CountingSortStruct;

void countingSort(int values[], int arraySize)
{
    int minValue = Arrays.getMinimumInteger(values, arraySize);
    int maxValue = Arrays.getMaximumInteger(values, arraySize);

    int countingArraySize = maxValue - minValue + 1;
    int countingArray[countingArraySize];
    Arrays.initializeArray(countingArray, 0, sizeof(countingArray));

    int arrayLength = Arrays.totalIntegers(arraySize);
    int incrementOffSet;
    for (int index = 0; index < arrayLength; index++)
    {
        incrementOffSet = values[index] - minValue;
        countingArray[incrementOffSet] = countingArray[incrementOffSet] + 1;
    }

    int arrayIndex = 0;
    for (int index = 0; index < countingArraySize; index++)
    {
        int totalCount = countingArray[index];
        int value = minValue + index;
        for (int count = 0; count < totalCount; count++)
        {
            values[arrayIndex++] = value;
        }
    }
};

CountingSortStruct CountingSort = {
    .countingSort = countingSort,
};

extern CountingSortStruct CountingSort;

#endif