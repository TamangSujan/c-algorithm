#ifndef PERSON_H
#define PERSON_H

#include "../../memory/memory.h"

typedef struct PersonStruct
{
    int age;
} Person;

typedef struct PersonHandlerStruct
{
    Person *(*New)(int age);
    void (*Delete)(Person *person);
} PersonHandlerStruct;

Person *New(int age)
{
    Person *person = (Person *)malloc(sizeof(Person));
    person->age = age;
    return person;
}

void Delete(Person *person)
{
    free(person);
}

PersonHandlerStruct PersonHandler = {
    .New = New,
    .Delete = Delete};

extern PersonHandlerStruct PersonHandler;

#endif