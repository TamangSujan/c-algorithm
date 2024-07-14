#include "printer/printer.h"
#include "console/console.h"
#include "objects/person/person.h"
#include "algorithm/stack/stack.h"
#include "algorithm/list/singlyLinkedList.h"
#include "arrays/arrays.h"
#include "algorithm/sort/bubbleSort.h"
#include "algorithm/sort/selectionSort.h"

int debugSort(int values[], int arraySize)
{
    int counter = 0;
    int arrayLength = Arrays.totalIntegers(arraySize);
    for (int index = 0; index < arrayLength; index++)
    {
        printf("%d | ", values[index]);
        counter++;
    }
    printf("Total Elemebts: %d\n", counter);
}

int main()
{
    int zeroValues[] = {};
    int values[] = {9, 5, 1, 2, 6, 48, 56, 123, 1, 84, 16, 51, 321, 0, 651, 63, 165, 4, 68};
    Printer.printNumber(Arrays.totalIntegers(sizeof(values)));
    SelectionSort.selectionSort(values, sizeof(values));
    debugSort(values, sizeof(values));
    Console.pause();
    return 0;
}