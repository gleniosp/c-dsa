// A queue is a linked list with FIFO properties.
// That is, a new node is always add at the end
// of the list. While we always read the first
// nodes that entered the list. That's why the name
// First In First Out. Or, another name First Come
// First Serve (FCFS).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next_node;
} __attribute__((packed)) node_s;

static node_s *__head = NULL;

int init(int data)
{
    if (__head)
    {
        printf("Queue already initialised.\n");
        return -1;
    }

    // Allocate memory and assign the address to __head;
    __head = malloc(sizeof(node_s));
    // If malloc fails, it'll return NULL, which will make this if condition
    // to be true as NULL will be considered as a 0 for the validation
    if (!__head)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Make the node point to NULL because there is nothing
    // to point to.
    __head->next_node = NULL;

    /* Copy over the given data and save. */
    __head->data = data;

    return 0;
}

int add(int data)
{
    node_s *cur;

    node_s *n = malloc(sizeof(node_s));
    if (!n)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    n->data = data;
    n->next_node = NULL;

    for (cur = __head; cur->next_node != NULL; cur = cur->next_node)
    {
        /*
            Nothing to do here, just heading to the end of the list,
            so `cur` points to it.
        */
    }

    cur->next_node = n;

    return 0;
}

void traverse(void)
{
    for (node_s *cursor = __head; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%d --> ", cursor->data);
    }
    printf("{}\n");
}