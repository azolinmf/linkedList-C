typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

void push(Node **head, void *val, size_t size);
void delete (Node **head, void *val, int (*compare)(void *, void *));
void printList(Node *head, void (*printData)(void *));