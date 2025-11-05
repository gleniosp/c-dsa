// A stack is a linked list with FILO properties.
// That is, a new node is always add at the top
// of the list. While we always read the last
// nodes that entered the list. That's why the name
// First In Last Out.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next_node;
} __attribute__((packed)) node_s;

static node_s *__top = NULL;

void push(int data)
{
    node_s *node = (node_s *)malloc(sizeof(node_s));
    if (!node)
    {
        printf("Memory allocation failed\n");
        return;
    }

    node->data = data;
    node->next_node = __top;

    __top = node;

    return;
}

void print_stack()
{
    for (node_s *node = __top; node != NULL; node = node->next_node)
    {
        printf("%d\n", node->data);
        printf("--\n");
    }
}

void peek()
{
    if (__top)
    {
        printf("peek: %d\n", __top->data);
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

void pop()
{
    if (__top)
    {
        printf("pop: %d\n", __top->data);
        node_s *victim = __top;

        __top = __top->next_node;

        free(victim);
    }
    else
    {
        printf("Stack is empty.\n");
    }
}