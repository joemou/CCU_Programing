#include <stdio.h>
#include <ctype.h>    /* for access to the toupper function */

int main(void)
{
 char input[100000]={0};
 int i=0;

for (i = 0; (input[i]=getchar ()) != EOF;i++);

for (int k = 0; k <= i;k++){
   printf("%c", input[k]);
}
}
