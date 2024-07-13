#ifndef CONSOLE_H
#define CONSOLE_H

#include <conio.h>

typedef struct ConsoleStruct
{
    void (*pause)();
} ConsoleStruct;

void pause()
{
    getch();
}

ConsoleStruct Console = {
    .pause = pause,
};

extern ConsoleStruct Console;

#endif