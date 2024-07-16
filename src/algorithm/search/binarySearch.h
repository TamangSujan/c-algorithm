#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "../../arrays/arrays.h"

typedef struct BinarySearchStruct
{
    int (*binarySearch)(int array[], int value, int arraySize);
} BinarySearchStruct;

int binarySearchImplementation(int array[], int low, int high, int value)
{
    if (low == high)
    {
        if (value == array[high])
            return high;
        else
            return -1;
    }
    int mid = (low + high) / 2;
    if (array[mid] == value)
        return mid;
    else if (array[mid] < value)
    {
        return binarySearchImplementation(array, mid + 1, high, value);
    }
    else
    {
        return binarySearchImplementation(array, low, mid, value);
    }
}

int binarySearch(int array[], int value, int arraySize)
{
    int totalIntegers = Arrays.totalIntegers(arraySize);
    if (totalIntegers == 0)
        return -1;
    if (totalIntegers == 1)
        if (array[0] == value)
            return 0;
        else
            return -1;
    return binarySearchImplementation(array, 0, totalIntegers - 1, value);
}

BinarySearchStruct BinarySearch = {
    .binarySearch = binarySearch,
};

extern BinarySearchStruct BinarySearch;

#endif