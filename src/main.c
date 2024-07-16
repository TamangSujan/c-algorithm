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

int main()
{
    Queue *queue = QueueHandler.newQueue();
    QueueHandler.enqueue(queue, 3);
    QueueHandler.enqueue(queue, 1);
    QueueHandler.enqueue(queue, 4);
    QueueHandler.enqueue(queue, 2);
    QueueHandler.enqueue(queue, 5);

    Printer.printNumber(QueueHandler.peekQueue(queue));
    QueueHandler.dequeue(queue);
    Printer.printNumber(QueueHandler.peekQueue(queue));
    QueueHandler.dequeue(queue);
    Printer.printNumber(QueueHandler.peekQueue(queue));
    QueueHandler.dequeue(queue);
    Printer.printNumber(QueueHandler.peekQueue(queue));
    QueueHandler.dequeue(queue);
    Printer.printNumber(QueueHandler.peekQueue(queue));
    QueueHandler.dequeue(queue);

    QueueHandler.deleteQueue(queue);
    Console.pause();
    return 0;
}