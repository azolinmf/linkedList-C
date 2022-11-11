#include <stdio.h>
#include <stdlib.h>
#include "genericLL.h"

/*print e compare para char, int, float, double and string*/
#include "primitive_types_functions.h"

int main()
{
    Node *integers = NULL;
    Node *floats = NULL;
    Node *chars = NULL;
    Node *strings = NULL;

    char char_arguments[10] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106};
    for (int i = 0; i < 10; i++)
        push(&chars, &char_arguments[i], sizeof(char_arguments[i]));
    printList(chars, printChar);
    for (int i = 0; i < 10; i++)
    {
        printf("Após tirar o %c: ", char_arguments[i]);
        delete (&chars, &char_arguments[i], compareChar);
        printList(chars, printChar);
    }

    int arguments[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 10; i++)
        push(&integers, &arguments[i], sizeof(arguments[i]));
    printList(integers, printInt);
    for (int i = 0; i < 10; i++)
    {
        printf("Após tirar o %d: ", arguments[i]);
        delete (&integers, &arguments[i], compareInt);
        printList(integers, printInt);
    }

    float float_arguments[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 10; i++)
        push(&floats, &float_arguments[i], sizeof(float_arguments[i]));
    printList(floats, printFloat);
    for (int i = 0; i < 10; i++)
    {
        printf("Após tirar o %f: ", float_arguments[i]);
        delete (&floats, &float_arguments[i], compareFloat);
        printList(floats, printFloat);
    }

    char strings_arguments[10][20] =
        {
            "Casa", "cavalo", "carteira", "fidedigno", "nasogástrico",
            "hipopótamo", "malabarista", "JBL", "React-native", "Swift"};

    for (int i = 0; i < 10; i++)
        push(&strings, &strings_arguments[i], sizeof(strings_arguments[i]));
    printList(strings, printString);
    for (int i = 0; i < 10; i++)
    {
        printf("Após tirar o %s: ", strings_arguments[i]);
        delete (&strings, &strings_arguments[i], compareStrings);
        printList(strings, printString);
    }
}