#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../../arrays/arrays.h"
#include "../../memory/memory.h"
#include "stdio.h"

typedef struct MergeSortStruct
{
    void (*mergeSort)(int values[], int arraySize);
} MergeSortStruct;

void mergeSortDivideAndConquer(int array[], int lowIndex, int highIndex)
{
    if (highIndex <= lowIndex)
        return;

    int mid = (highIndex + lowIndex) / 2;

    mergeSortDivideAndConquer(array, lowIndex, mid);
    mergeSortDivideAndConquer(array, mid + 1, highIndex);

    int left = lowIndex;
    int right = mid + 1;
    int tempArray[highIndex - lowIndex + 1];
    int tempArrayIndex = 0;

    while (left <= mid && right <= highIndex)
    {
        if (array[left] >= array[right])
        {
            tempArray[tempArrayIndex++] = array[right++];
        }
        if (array[left] <= array[right])
        {
            tempArray[tempArrayIndex++] = array[left++];
        }
    }

    while (left <= mid)
    {
        tempArray[tempArrayIndex++] = array[left++];
    }

    while (right <= highIndex)
    {
        tempArray[tempArrayIndex++] = array[right++];
    }

    for (int index = 0; index < tempArrayIndex; index++)
    {
        array[lowIndex + index] = tempArray[index];
    }
}

void mergeSort(int values[], int arraySize)
{
    int totalIntegers = Arrays.totalIntegers(arraySize);
    mergeSortDivideAndConquer(values, 0, totalIntegers - 1);
};

MergeSortStruct MergeSort = {
    .mergeSort = mergeSort,
};

extern MergeSortStruct MergeSort;

#endif