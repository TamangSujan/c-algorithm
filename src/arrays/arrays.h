#ifndef ARRAYS_H
#define ARRAYS_H

typedef struct ArraysStruct
{
    int (*totalIntegers)(int arraySize);
    int (*getMinimumInteger)(int array[], int arraySize);
    int (*getMaximumInteger)(int array[], int arraySize);
    void (*initializeArray)(int array[], int value, int size);
} ArraysStruct;

int totalIntegers(int arraySize)
{
    return arraySize / sizeof(int);
}

int getMinimumInteger(int array[], int arraySize)
{
    int totalInteger = totalIntegers(arraySize);
    if (totalInteger <= 0)
        return -1;
    int minimum = array[0];
    for (int index = 0; index < totalInteger; index++)
    {
        if (minimum > array[index])
            minimum = array[index];
    }
    return minimum;
}

int getMaximunInteger(int array[], int arraySize)
{
    int totalInteger = totalIntegers(arraySize);
    if (totalInteger <= 0)
        return -1;
    int maximum = array[0];
    for (int index = 0; index < totalInteger; index++)
    {
        if (maximum < array[index])
            maximum = array[index];
    }
    return maximum;
}

void initializeArray(int array[], int value, int arraySize)
{
    int size = totalIntegers(arraySize);
    if (size <= 0)
        return;
    for (int index = 0; index < size; index++)
    {
        array[index] = value;
    }
}

ArraysStruct Arrays = {
    .totalIntegers = totalIntegers,
    .getMinimumInteger = getMinimumInteger,
    .getMaximumInteger = getMaximunInteger,
    .initializeArray = initializeArray};

extern ArraysStruct Arrays;

#endif