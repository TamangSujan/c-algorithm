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
#include "algorithm/queue/queue.h"
#include "algorithm/hash/hashSet.h"

int main()
{
    HashSet *set = HashSetHandler.newHashSet(10);
    HashSetHandler.addValueOnHashSet(set, 0);
    HashSetHandler.addValueOnHashSet(set, 1);
    HashSetHandler.addValueOnHashSet(set, 2);
    HashSetHandler.addValueOnHashSet(set, 4);
    HashSetHandler.addValueOnHashSet(set, 5);
    HashSetHandler.addValueOnHashSet(set, 7);
    HashSetHandler.addValueOnHashSet(set, 9);
    HashSetHandler.addValueOnHashSet(set, 12);

    Printer.printNumber(HashSetHandler.getValueFromHashSet(set, 12));
    Printer.printNumber(HashSetHandler.getValueFromHashSet(set, 3));

    HashSetHandler.deleteHashSet(set);
    Console.pause();
    return 0;
}