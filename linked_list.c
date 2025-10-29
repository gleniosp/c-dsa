/*
If you move the sll.c file out of the sll-lib folder and put it
at the same level as the ssl.h file, you can simple compile and
run this code with: `gcc linked_list.c sll.c && ./a.out`.
However, with the sll.c file inside the sll-lib folder, we can
compile sll.c to a static library and share this library and the
header file with other people without sharing the actual
implementation within sll.c. For this, we do:
- `cd sll-lib`
- `gcc -c sll.c`
- `ar -rc libsll.a sll.o`
- `mv libsll.a ../`
- `cd ..`
- `gcc linked_list.c libsll.a && ./a.out`

I left both approaches available, so you can choose which one to use.
*/

#include <stdio.h>
#include "sll.h"

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

    delete(5);
    traverse();

    delete(101);
    traverse();

    insert(0, 101);
    traverse();
    insert(101, 1024);
    traverse();

    // should print key not found
    insert(1023, 4098);
    traverse();

    return 0;
}
