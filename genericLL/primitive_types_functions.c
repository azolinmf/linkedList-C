#include <stdio.h>
#include <string.h>
#include "primitive_types_functions.h"

void printChar(void *data)
{
    printf("%c ", *(char *)data);
}

void printInt(void *data)
{
    printf("%d ", *(int *)data);
}

void printFloat(void *data)
{
    printf("%f ", *(float *)data);
}

void printDouble(void *data)
{
    printf("%lf ", *(double *)data);
}

void printString(void *data)
{
    printf("%s ", (char *)data);
}

int compareChar(void *a, void *b)
{
    char num1 = *(char *)a;
    char num2 = *(char *)b;
    if (num1 > num2)
        return 1;
    if (num1 == num2)
        return 0;
    return -1;
}

int compareInt(void *a, void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 > num2)
        return 1;
    if (num1 == num2)
        return 0;
    return -1;
}

int compareFloat(void *a, void *b)
{
    float precision = 0.000001;
    float num1 = *(float *)a;
    float num2 = *(float *)b;

    float aux = num1 - num2;
    if (aux > precision)
        return 1;
    if (aux <= precision && aux > precision * -1.0)
        return 0;
    return -1;
}

int compareDouble(void *a, void *b)
{
    double precision = 0.000001;
    double num1 = *(double *)a;
    double num2 = *(double *)b;

    double aux = num1 - num2;
    if (aux > precision)
        return 1;
    if (aux <= precision && aux > precision * -1.0)
        return 0;
    return -1;
}

int compareStrings(void *a, void *b)
{

    return (strcmp((char *)a, (char *)b));
}