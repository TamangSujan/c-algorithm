#include "printer/printer.h"
#include "console/console.h"
#include "objects/person/person.h"
#include "algorithm/stack/stack.h"
#include "algorithm/list/singlyLinkedList.h"
#include "arrays/arrays.h"
#include "algorithm/sort/bubbleSort.h"

int debugSort(int values[], int arraySize)
{
    int arrayLength = Arrays.totalIntegers(arraySize);
    for (int index = 0; index < arrayLength; index++)
    {
        printf("%d | ", values[index]);
    }
    printf("\n");
}

int main()
{
    int values[] = {15, 88, 10, 36, -1, 58, 31, 74, 9, 25, 01, 32, 6, 558};
    BubbleSort.bubbleSort(values, sizeof(values));
    debugSort(values, sizeof(values));
    Console.pause();
    return 0;
}