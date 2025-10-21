#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[40];
    struct node *next_node;
} __attribute__((packed)) node_s;

node_s *__head = NULL;

int init(char *data) {
    if (__head) {
        printf("List already initialised.\n");
        return -1;
    }

    // Allocate memory and assign the address to __head;
    __head = malloc(sizeof(node_s));
    // If malloc fails, it'll return NULL, which will make this if condition
    // to be true as NULL will be considered as a 0 for the validation
    if (!__head) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Make the node point to NULL because there is nothing
    // to point to.
    __head->next_node = NULL;

    /* Copy over the given data and save.
    Just to be aware of: at this point, if data has more than 40 chars,
    this code will propably produce some errors at runtime.
    It's also missing a check to see if memcpy failed or not. */
    memcpy(__head->data, data, strlen(data));

    return 0;
}

int add (char *data) {
    if (!data) {
        printf("Invalid data!\n");
        return -1;
    }

    node_s *n = malloc(sizeof(node_s));
    if (!n) {
        printf("Memory allocation failed!\n");
        return -2;
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
    memcpy(n->data, data, strlen(data));

    __head = n;

    return 0;
}

void traverse(void) {
    for (node_s *cursor = __head; cursor != NULL; cursor = cursor->next_node) {
        printf("%s\n", cursor->data);
    }
}

int main() {
    init("hello");
    add("world");
    add("from linked list");

    traverse();
    return 0;
}
