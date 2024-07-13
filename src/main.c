#include "printer/printer.h"
#include "console/console.h"
#include "objects/person/person.h"
#include "algorithm/stack/stack.h"

int main()
{
    Stack *stack = StackHandler.newStack();
    Printer.printNumber(StackHandler.isEmpty(stack));
    Printer.printNumber(StackHandler.peek(stack));

    StackHandler.push(stack, 10);
    StackHandler.push(stack, 20);
    StackHandler.push(stack, 30);
    StackHandler.push(stack, 40);
    StackHandler.push(stack, 50);

    Printer.printNumber(StackHandler.peek(stack));
    Printer.printNumber(stack->size);
    Printer.printNumber(StackHandler.isEmpty(stack));

    StackHandler.pop(stack);
    Printer.printNumber(StackHandler.peek(stack));
    Printer.printNumber(stack->size);
    Printer.printNumber(StackHandler.isEmpty(stack));

    StackHandler.deleteStack(stack);
    Console.pause();
    return 0;
}