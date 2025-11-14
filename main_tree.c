// Run this program with: gcc main_tree.c tree.c queue4tree.c && ./a.out

#include <stdio.h>

#include "tree.h"

int main()
{
    // during the additions the nodes will also be printed,
    // which will essentially print Breadth-first search (BFS).
    add('A');
    add('B');
    add('C');
    add('D');
    add('E');
    add('F');
    add('G');
    add('H');

    print_preorder();
    print_inorder();
    print_postorder();

    // We should also free all the allocated memory for the tree
    // before ending the program.

    return 0;
}