// Run this program with: gcc main_stacks.c stacks.c && ./a.out

#include <stdio.h>

#include "stacks.h"

int main()
{
    push(1);
    push(2);
    push(4);
    push(7);
    push(8);

    print_stack();

    return 0;
}