#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct queue_node
{
    void *node;
    struct queue_node *next_q_node;
} q_node;

// static to make variables available only in this file
static q_node *__queue_front = NULL;
static q_node *__queue_end = NULL;

bool queue_empty()
{
    if (__queue_front == NULL)
        return true;
    return false;
}

void enqueue(void *node_to_explore)
{
    q_node *new_entry = (q_node *)malloc(sizeof(q_node));
    new_entry->node = node_to_explore;
    new_entry->next_q_node = NULL;

    if (__queue_end)
    {
        __queue_end->next_q_node = new_entry;
        __queue_end = new_entry;
    }
    else
    {
        // for the first queue entry, both front and end will point to the same queue item
        __queue_end = new_entry;
        __queue_front = new_entry;
    }
}

void *dequeue()
{
    void *return_node_address = NULL;

    if (!__queue_front)
        return NULL;

    return_node_address = __queue_front->node;
    q_node *temp = __queue_front->next_q_node;
    free(__queue_front);
    __queue_front = temp;

    return return_node_address;
}

void destroy_queue()
{
    q_node *ptr = __queue_front;

    if (ptr == NULL)
        return;

    while (ptr)
    {
        q_node *tmp = ptr;
        ptr = ptr->next_q_node;

        free(tmp);
    }

    __queue_front = NULL;
    __queue_end = NULL;
}