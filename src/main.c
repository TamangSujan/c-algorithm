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
#include "algorithm/tree/binaryTree.h"
#include "algorithm/tree/avlTree.h"

int main()
{
    AvlTree *tree = AvlTreeHandler.newAvlTree();
    AvlTreeHandler.printAvlTree(tree);

    AvlTreeHandler.insertValueInAvlTree(tree, 1);
    AvlTreeHandler.insertValueInAvlTree(tree, 2);
    AvlTreeHandler.insertValueInAvlTree(tree, 3);
    AvlTreeHandler.insertValueInAvlTree(tree, 4);
    AvlTreeHandler.insertValueInAvlTree(tree, 5);
    AvlTreeHandler.insertValueInAvlTree(tree, 6);
    AvlTreeHandler.insertValueInAvlTree(tree, 7);
    AvlTreeHandler.insertValueInAvlTree(tree, 8);
    AvlTreeHandler.insertValueInAvlTree(tree, 9);
    AvlTreeHandler.insertValueInAvlTree(tree, 10);
    AvlTreeHandler.insertValueInAvlTree(tree, 11);
    AvlTreeHandler.insertValueInAvlTree(tree, 12);
    AvlTreeHandler.insertValueInAvlTree(tree, 13);
    AvlTreeHandler.insertValueInAvlTree(tree, 14);
    AvlTreeHandler.insertValueInAvlTree(tree, 15);
    AvlTreeHandler.insertValueInAvlTree(tree, 16);
    AvlTreeHandler.insertValueInAvlTree(tree, 17);
    AvlTreeHandler.insertValueInAvlTree(tree, 18);
    AvlTreeHandler.insertValueInAvlTree(tree, 19);
    AvlTreeHandler.insertValueInAvlTree(tree, 20);

    AvlTreeHandler.printAvlTree(tree);

    AvlTreeHandler.deleteValueFromAvlTree(tree, 12);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 5);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 14);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 17);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 0);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 8);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 16);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 20);

    AvlTreeHandler.deleteValueFromAvlTree(tree, 3);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 4);
    AvlTreeHandler.deleteValueFromAvlTree(tree, 1);

    AvlTreeHandler.printAvlTree(tree);
    AvlTreeHandler.deleteAvlTree(tree);
    Console.pause();
    return 0;
}