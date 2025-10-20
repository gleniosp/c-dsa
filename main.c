#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[40];
    struct node *next_node;
} __attribute__((packed)) node_s;

node_s *__head = NULL;

int init(char *data) {
    // Allocate memory and assign the address to __head;
    __head = malloc(sizeof(node_s));
    // If malloc fails, it'll return NULL, which will make this if condition
    // to be true as NULL will be considered as a 0 for the validation
    if (!__head) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Make the node point to NULL because there is nothing
    // to point to.
    __head->next_node = NULL;

    /* Copy over the given data and save.
    Just to be aware of: at this point, if data has more than 40 chars,
    this code will propably produce some errors at runtime. */
    memcpy(__head->data, data, strlen(data));

    return 0;
}

int main() {
    init("hello");
    return 0;
}
