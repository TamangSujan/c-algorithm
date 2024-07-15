#ifndef DECIMAL_NUMBER_UTILITY_H
#define DECIMAL_NUMBER_UTILITY_H

typedef struct DecimalNumberUtilityStruct
{
    int (*getDigitValueFromPosition)(int value, int position);
    int (*getRightDigitPosition)(int value);
} DecimalNumberUtilityStruct;

int getRightDigitPosition(int value)
{
    int position = 0;
    while (value != 0)
    {
        value = value / 10;
        position++;
    }
    return position;
}

int getDigitValueFromPosition(int value, int position)
{
    if (position < 0 || getRightDigitPosition(value) < position)
        return 0;
    int requiredValue = 0;
    for (int index = 0; index < position; index++)
    {
        requiredValue = value % 10;
        value = value / 10;
    }
    return requiredValue;
}

DecimalNumberUtilityStruct DecimalNumberUtility = {
    .getDigitValueFromPosition = getDigitValueFromPosition,
    .getRightDigitPosition = getRightDigitPosition,
};

extern DecimalNumberUtilityStruct DecimalNumberUtility;

#endif