#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "../../arrays/arrays.h"
#include "stdio.h"

typedef struct QuickSortStruct
{
    void (*quickSort)(int values[], int arraySize);
} QuickSortStruct;

void quickSortSwap(int array[], int fromIndex, int toIndex)
{
    int temporaryValue = array[fromIndex];
    array[fromIndex] = array[toIndex];
    array[toIndex] = temporaryValue;
}

int partition(int array[], int lowIndex, int highIndex)
{
    int pivot = array[lowIndex];
    int leftIndex = lowIndex + 1;
    for (int index = lowIndex + 1; index <= highIndex; index++)
    {
        if (array[index] < pivot)
        {
            quickSortSwap(array, index, leftIndex);
            leftIndex++;
        }
    }
    quickSortSwap(array, lowIndex, leftIndex - 1);
    return leftIndex - 1;
}

void quickSortImplementation(int array[], int lowIndex, int highIndex)
{
    if (lowIndex < highIndex)
    {
        int pivotIndex = partition(array, lowIndex, highIndex);
        quickSortImplementation(array, lowIndex, pivotIndex);
        quickSortImplementation(array, pivotIndex + 1, highIndex);
    }
}

void quickSort(int values[], int arraySize)
{
    int arrayLength = Arrays.totalIntegers(arraySize);
    quickSortImplementation(values, 0, arrayLength - 1);
};

QuickSortStruct QuickSort = {
    .quickSort = quickSort,
};

extern QuickSortStruct QuickSort;

#endif