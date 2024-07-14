#ifndef ARRAYS_H
#define ARRAYS_H

typedef struct ArraysStruct
{
    int (*totalIntegers)(int arraySize);
} ArraysStruct;

int totalIntegers(int arraySize)
{
    return arraySize / sizeof(int);
}

ArraysStruct Arrays = {
    .totalIntegers = totalIntegers,
};

extern ArraysStruct Arrays;

#endif