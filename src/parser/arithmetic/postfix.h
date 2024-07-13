#ifndef POSTFIX_H
#define POSTFIX_H

typedef struct PostfixStruct
{
    char *(*postfix)(char *characters);
} PostfixStruct;

char *postfix(char *characters)
{
    char *a;
    return a;
}

PostfixStruct Postfix = {
    .postfix = postfix};

extern PostfixStruct Postfix;

#endif