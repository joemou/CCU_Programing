#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For memory allocation functions
#include <string.h>     // For string manipulation functions
#include <ctype.h>


#define isAddOrMinus(oper) (((*oper)=='+')||((*oper)=='-') ?1:0)

#define MAXBUF 1000

#define TRUE 1
#define FALSE 0

#define SAME 1
#define LOWER 0
#define HIGHER 2

#define Rev 1
#define Nor 0

#define TooMany 1
#define TooLess 2
#define Unknown 0
#define Duplicate 3

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2



#endif /* BASIC_H */
