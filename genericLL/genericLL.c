#include <stdlib.h>
#include <stdio.h>
#include "genericLL.h"

void push(Node **head, void *val, size_t data_size)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = malloc(data_size);
    /*como char tem um byte copia byte por byte*/
    for (int i = 0; i < data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(val + i);

    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *p = *head;
    while (p->next != NULL)
        p = p->next;

    p->next = new_node;
    return;
}

/*Como a lista é genérica, ou seja, pode ter qualquer tipo de data type, passamos uma função específica para o data type que está sendo usado
para comparar os elementos.*/
void delete (Node **head, void *val, int (*compare)(void *, void *))
{
    if (*head == NULL)
        return;

    Node *p = *head;
    Node *ant = NULL;

    if (p->next == NULL && (*compare)(p->data, val) == 0)
    {
        *head = NULL;
        return;
    }

    while (p->next != NULL)
    {
        int comp = (*compare)(p->data, val);
        if (comp == 0)
        {

            if (ant == NULL)
            {
                *head = p->next;
                free(p->data);
                return;
            }
            else
            {
                ant->next = p->next;
                free(p->data);
            }
        }
        ant = p;
        p = p->next;
    }
}
/*Essa função vai apenas percorrer a lista e passar cada elemento para uma função
recebida como parâmetro que printa especificamente aquele data type. */
void printList(Node *head, void (*printData)(void *))
{
    Node *p = head;
    while (p)
    {
        (*printData)(p->data);
        p = p->next;
    }
    puts("");
}
