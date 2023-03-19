#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For memory allocation functions
#include <string.h>     // For string manipulation functions
#include <stdbool.h>    // For boolean data type

// External variables
extern int global_int;
extern char global_char;

// Identifiers
#define TRUE 1
#define FALSE 0
typedef int Bool;

#define PI 3.14159
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#endif /* BASIC_H */
