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

int main()
{
    BinaryTree *binaryTree = BinaryTreeHandler.newBinaryTree();
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 10);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 5);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 15);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 10);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 5);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 15);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 6);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 7);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 8);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 16);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 11);
    BinaryTreeHandler.insertValueInBinaryTree(binaryTree, 18);
    BinaryTreeHandler.traverseBinaryTree(binaryTree);
    printf("\n");
    Printer.printNumber(BinaryTreeHandler.searchBinaryTree(binaryTree, 20));
    Printer.printNumber(BinaryTreeHandler.searchBinaryTree(binaryTree, 8));
    BinaryTreeHandler.deleteBinaryTree(binaryTree);
    Console.pause();
    return 0;
}