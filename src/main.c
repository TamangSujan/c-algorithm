#include "printer/printer.h"
#include "console/console.h"
#include "objects/person/person.h"
#include "algorithm/stack/stack.h"
#include "algorithm/list/singlyLinkedList.h"

void debugList(SinglyLinkedList *list)
{
    if (list->size > 0)
    {
        SinglyNode *head = list->head;
        while (head != NULL)
        {
            printf("%d | ", head->value);
            head = head->next;
        }
        printf("\n");
    }
}

int main()
{
    Console.pause();
    return 0;
}