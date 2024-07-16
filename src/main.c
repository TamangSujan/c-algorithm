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
#include "algorithm/hash/hashMap.h"

int main()
{
    HashMap *map = HashMapHandler.newHashMap(10);
    HashMapHandler.addValueOnHashMap(map, 0, 123);
    HashMapHandler.addValueOnHashMap(map, 1, 123);
    HashMapHandler.addValueOnHashMap(map, 2, 234);
    HashMapHandler.addValueOnHashMap(map, 4, 234);
    HashMapHandler.addValueOnHashMap(map, 5, 456);

    Printer.printNumber(HashMapHandler.getValueFromHashMap(map, 0));
    Printer.printNumber(HashMapHandler.getValueFromHashMap(map, 1));
    Printer.printNumber(HashMapHandler.getValueFromHashMap(map, 2));
    Printer.printNumber(HashMapHandler.getValueFromHashMap(map, 3));
    Printer.printNumber(HashMapHandler.getValueFromHashMap(map, 4));
    Printer.printNumber(HashMapHandler.getValueFromHashMap(map, 5));

    HashMapHandler.deleteHashMap(map);
    Console.pause();
    return 0;
}