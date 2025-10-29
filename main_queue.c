// Run this program with: gcc main_queue.c queue.c && ./a.out

#include <stdio.h>
#include "queue.h"

int main()
{
    init(101);

    for (int i = 0; i < 10; i++)
    {
        add(i);
    }

    traverse();

    return 0;
}
