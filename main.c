#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next_node;
} __attribute__((packed)) node_s;

node_s *__head = NULL;

int init(int data)
{
    if (__head)
    {
        printf("List already initialised.\n");
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
    node_s *n = malloc(sizeof(node_s));
    if (!n)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    /*
        Instead of making the current node as the next node for the
        head, we make the head point to the current node and we
        make the current node point the next node to the previous head.
        If we were to keep head as the first element always, whenever
        we add a new element, we'd have to go from head all the way
        to the last element until we find it, so we can make this
        last element point to the current node. This isn't very
        time efficient in terms of writing to the linked list.
    */
    n->next_node = __head;
    n->data = data;

    __head = n;

    return 0;
}

int add_at_the_end(int data)
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

    /*
        Different from the `add` function above, here we're doing
        the opposite. We're not adding the next node to the beginning
        of the list, but to the end of it. So, we need to go through
        all the elements to find the current end node. The time
        complexity here is then O(n) instead of O(1) (for the `add`
        function).
    */
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

int exists(int data)
{
    for (node_s *cursor = __head; cursor != NULL; cursor = cursor->next_node)
    {
        if (cursor->data == data)
        {
            return 1;
        }
    }

    return 0;
}

void traverse(void)
{
    for (node_s *cursor = __head; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%d\n", cursor->data);
    }
}

int main()
{
    init(101);

    for (int i = 0; i < 10; i++)
    {
        add(i);
    }

    for (int i = 0; i < 10; i++)
    {
        add_at_the_end(i);
    }

    traverse();

    printf("102: %d\n", exists(102));
    printf("101: %d\n", exists(101));

    return 0;
}
