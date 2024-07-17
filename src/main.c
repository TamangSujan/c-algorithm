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
#include "algorithm/list/linkedList.h"

int main()
{
    LinkedList *list = LinkedListHandler.newLinkedList();
    LinkedListHandler.removeFirstLinkedNode(list);
    LinkedListHandler.removeLastLinkedNode(list);
    LinkedListHandler.removeLinkedNodeAt(list, 10);

    LinkedListHandler.insertLinkedNodeAtLast(list, 4);
    LinkedListHandler.insertLinkedNodeAtFirst(list, 1);
    LinkedListHandler.insertLinkedNodeAt(list, 2, 1);
    LinkedListHandler.insertLinkedNodeAt(list, 3, 2);

    LinkedListHandler.insertLinkedNodeAt(list, 0, 0);
    LinkedListHandler.insertLinkedNodeAt(list, 10, 3);
    LinkedListHandler.insertLinkedNodeAt(list, 15, 1);

    LinkedListHandler.removeFirstLinkedNode(list);
    LinkedListHandler.removeLastLinkedNode(list);
    LinkedListHandler.removeLinkedNodeAt(list, 2);

    LinkedListHandler.printLinkedList(list);

    Printer.printNumber(LinkedListHandler.containsValue(list, 15));
    Printer.printNumber(LinkedListHandler.containsValue(list, 8));

    LinkedListHandler.debugLinkedList(list);
    LinkedListHandler.deleteLinkedList(list);
    Console.pause();
    return 0;
}