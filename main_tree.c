// Run this program with: gcc main_tree.c tree.c queue4tree.c && ./a.out

#include <stdio.h>

#include "tree.h"

int main()
{
    add('A');
    add('B');
    add('C');
    add('D');
    add('E');
    add('F');
    add('G');
    add('H');

    // We should also free all the allocated memory for the tree
    // before ending the program.

    return 0;
}