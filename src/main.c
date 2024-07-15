#include "printer/printer.h"
#include "console/console.h"
#include "objects/person/person.h"
#include "algorithm/stack/stack.h"
#include "algorithm/list/singlyLinkedList.h"
#include "arrays/arrays.h"
#include "algorithm/sort/bubbleSort.h"
#include "algorithm/sort/selectionSort.h"
#include "algorithm/sort/insertionSort.h"
#include "algorithm/sort/quickSort.h"
#include "algorithm/sort/mergeSort.h"

int debugSort(int values[], int arraySize)
{
    int counter = 0;
    int arrayLength = Arrays.totalIntegers(arraySize);
    for (int index = 0; index < arrayLength; index++)
    {
        printf("%d | ", values[index]);
        counter++;
    }
    printf("Total Elements: %d\n", counter);
}

int main()
{
    int zeroValues[] = {};
    int values[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    Printer.printNumber(Arrays.totalIntegers(sizeof(values)));
    MergeSort.mergeSort(values, sizeof(values));
    debugSort(values, sizeof(values));
    Console.pause();
    return 0;
}