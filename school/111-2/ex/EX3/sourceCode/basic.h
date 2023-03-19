#ifndef BASIC_H
#define BASIC_H
#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For memory allocation functions
#include <string.h>     // For string manipulation functions
#include <ctype.h>

int isAddOrMinus(char *op);

#define MAXBUF 10000
#define TRUE 1
#define FALSE 0
#define SAME 0
#define LOWER -1
#define HIGHER 1
#define Rev 2
#define Nor 1
#define TooMany 1
#define TooLess -1
#define INFIX 1
#define PREFIX 2
#define POSTFIX 3
#define Unknown 2
#define Duplicate 3



#endif /* BASIC_H */
