#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For memory allocation functions
#include <string.h>     // For string manipulation functions
#include <ctype.h>
#include "basic.h"


int isAddOrMinus(char *op)
{
    if(strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 1;  // true
    else
        return 0;  // false
}
