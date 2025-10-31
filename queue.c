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
static node_s *__tail = NULL;

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

    // tail and head point to the same location
    __tail = __head;
    return 0;
}

int add(int data)
{
    node_s *n = malloc(sizeof(node_s));
    if (!n)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    n->data = data;
    n->next_node = NULL;

    __tail->next_node = n;

    __tail = n;

    return 0;
}

int fetch(void)
{
    int first;
    node_s *to_be_deleted;

    if (!__head)
    {
        printf("Empty queue\n");
        return -1;
    }

    first = __head->data;

    to_be_deleted = __head;
    __head = __head->next_node;
    free(to_be_deleted);

    return first;
}

void traverse(void)
{
    for (node_s *cursor = __head; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%d --> ", cursor->data);
    }
    printf("{}\n");
}