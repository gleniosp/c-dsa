// Run this program with: gcc main_stacks.c stacks.c && ./a.out

#include <stdio.h>

#include "stacks.h"

int main()
{
    peek();

    push(1);
    push(2);
    push(4);

    peek();

    push(7);
    push(8);

    peek();

    print_stack();

    pop();
    pop();
    print_stack();

    pop();
    pop();
    pop();
    pop();

    print_stack();

    return 0;
}