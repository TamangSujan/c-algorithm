#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>

typedef struct PrinterStruct
{
    void (*printLine)(char *characters);
    void (*printNumber)(int value);
} PrinterStruct;

void printLine(char *characters)
{
    printf("%s\n", characters);
};

void printNumber(int value)
{
    printf("%d\n", value);
};

PrinterStruct Printer = {
    .printLine = printLine,
    .printNumber = printNumber};

extern PrinterStruct Printer;

#endif