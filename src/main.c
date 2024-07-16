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
#include "algorithm/sort/countingSort.h"
#include "algorithm/sort/radixSort.h"
#include "algorithm/search/linearSearch.h"
#include "algorithm/search/binarySearch.h"

int main()
{
    int values[] = {178, 571, 457, 584, 123, 273, 319, 478, 251, 270};
    MergeSort.mergeSort(values, sizeof(values));
    Arrays.printArray(values, sizeof(values));
    int position = BinarySearch.binarySearch(values, 319, sizeof(values));
    Printer.printNumber(position);
    Console.pause();
    return 0;
}