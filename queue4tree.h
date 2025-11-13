#include <stdbool.h>

bool queue_empty();

void enqueue(void *node_to_explore);

void *dequeue();

void destroy_queue();
