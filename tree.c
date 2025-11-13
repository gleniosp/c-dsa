#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue4tree.h"

typedef struct node
{
    char data;
    struct node *l_child;
    struct node *r_child;
} __attribute__((packed)) node_s;

node_s *__root = NULL;

void add(char data)
{
    /* Ideally, we should also add later an error handling
    in case malloc isn't able to allocate memory. */
    node_s *new = (node_s *)malloc(sizeof(node_s));
    new->data = data;
    new->l_child = NULL;
    new->r_child = NULL;

    if (__root == NULL)
    {
        printf("Root: %c\n", data);
        __root = new;
        return;
    }

    // check l_child for root
    if (__root->l_child == NULL)
    {
        printf("%c (l-child): %c\n", __root->data, data);
        __root->l_child = new;
        return;
    }
    else
    {
        // add it for future exploration
        enqueue((void *)(__root->l_child));
    }

    // check r_child for root
    if (__root->r_child == NULL)
    {
        printf("%c (r-child): %c\n", __root->data, data);
        __root->r_child = new;
        destroy_queue();
        return;
    }
    else
    {
        // add it for future exploration
        enqueue((void *)(__root->r_child));
    }

    // explore and find a free slot
    while (queue_empty() == false)
    {
        // Later we should also check if dequeue returned NULL or not
        node_s *node = (node_s *)dequeue();
        if (node->l_child == NULL)
        {
            node->l_child = new;
            printf("%c (l-child): %c\n", node->data, data);
            destroy_queue();
            return;
        }
        else
        {
            enqueue((void *)(node->l_child));
        }

        if (node->r_child == NULL)
        {
            node->r_child = new;
            printf("%c (r-child): %c\n", node->data, data);
            destroy_queue();
            return;
        }
        else
        {
            enqueue((void *)(node->r_child));
        }
    }
}