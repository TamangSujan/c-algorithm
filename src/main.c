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
    int values[] = {2, 6, 5, 3, 8, 7, 1, 0, 10, 41, 6};
    Printer.printNumber(Arrays.totalIntegers(sizeof(values)));
    QuickSort.quickSort(values, sizeof(values));
    debugSort(values, sizeof(values));
    Console.pause();
    return 0;
}