#include <stdio.h>
#include <ctype.h>    /* for access to the toupper function */

int main(void)
{
 int c;
    while ((c = getchar()) != EOF)
       putchar(c);
}
