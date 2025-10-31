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

    fetch();
    traverse();

    fetch();
    traverse();

    fetch();
    fetch();
    traverse();

    for (int j = 0; j < 10; j++)
    {
        printf("%d\n", fetch());
    }

    return 0;
}
