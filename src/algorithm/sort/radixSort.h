#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "../../arrays/arrays.h"
#include "../number/decimalNumberUtility.h"
#include "../list/singlyLinkedList.h"
#include "stdio.h"

typedef struct RadixSortStruct
{
    void (*radixSort)(int values[], int arraySize);
} RadixSortStruct;

void radixSort(int values[], int arraySize)
{
    int totalIntegers = Arrays.totalIntegers(arraySize);
    int minValue = Arrays.getMinimumInteger(values, arraySize);
    int maxValue = Arrays.getMaximumInteger(values, arraySize);

    int loopTimes = DecimalNumberUtility.getRightDigitPosition(maxValue);

    SinglyLinkedList *buckets[10];

    for (int index = 0; index < 10; index++)
    {
        buckets[index] = SinglyLinkedListHandler.newSinglyLinkedList();
    }

    for (int position = 1; position <= loopTimes; position++)
    {
        for (int arrayIndex = 0; arrayIndex < totalIntegers; arrayIndex++)
        {
            int bucketPosition = DecimalNumberUtility.getDigitValueFromPosition(values[arrayIndex], position);
            SinglyLinkedListHandler.insertSinglyItem(buckets[bucketPosition], values[arrayIndex]);
        }

        int arrayIndex = 0;
        for (int index = 0; index < 10; index++)
        {
            while (SinglyLinkedListHandler.isSinglyLinkedListEmpty(buckets[index]) != 1)
            {
                int nextValue = SinglyLinkedListHandler.peekSinglyItemAt(buckets[index], 0);
                values[arrayIndex++] = nextValue;
                SinglyLinkedListHandler.removeSinglyItemAt(buckets[index], 1);
            }
        }
    }

    for (int index = 0; index < 10; index++)
    {
        SinglyLinkedListHandler.deleteSinglyLinkedList(buckets[index]);
    }
};

RadixSortStruct RadixSort = {
    .radixSort = radixSort,
};

extern RadixSortStruct RadixSort;

#endif