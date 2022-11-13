#include <stdio.h>
#include <ctype.h>
#include <string.h>
//In this exercise, you will use the type definitions you learned in class to classify character types! An English article will be entered for each test, please count the following: ● Total Bytes of the full text (Equivalent to the size of the article archive) ● Number of lowercase alphabets ● Number of uppercase alphabets ● Number of digits ● Number of whitespace (The definition of blank comes from https://cplusplus.com/reference/cctype/isspace/ ) ● Total number of lines (At least one character per line.) Also, you need to count the number of English alphabets in the article and the frequency of their occurrence in the English alphabets, case-insensitive. Hint: you may want to use EOF to test whether the current input is the end of the English article. Also, you can use the functions in the <ctype.h> to help you finish the program. ● Input Format An English article of length n. ● Output Format Refer to the sample output. ● Technical Specifications ■ 0 ≤  𝑛 ≤ 100000 The table below shows the example input and output. The underscored number is the input from users. Input Output I love Rose. 'cause he is   so warm. Bytes Count: 38 Lowercase Count: 22 Uppercase Count: 2 Digit Count: 0 Whitespace Count: 11 Line Count: 3A/a: 2, 0.083 B/b: 0, 0.000 C/c: 1, 0.042 D/d: 0, 0.000 E/e: 4, 0.167 F/f: 0, 0.000 G/g: 0, 0.000 H/h: 1, 0.042 I/i: 2, 0.083 J/j: 0, 0.000 K/k: 0, 0.000 L/l: 1, 0.042 M/m: 1, 0.042 N/n: 0, 0.000 O/o: 3, 0.125 P/p: 0, 0.000 Q/q: 0, 0.000 R/r: 2, 0.083 S/s: 4, 0.167 T/t: 0, 0.000 U/u: 1, 0.042 V/v: 1, 0.042 W/w: 1, 0.042 X/x: 0, 0.000 Y/y: 0, 0.000 Z/z: 0, 0.000
int main(){

    int bytes;
    char input[100000];

    for (bytes = 0; (input[bytes]=getchar ()) != '\n';bytes++);

    printf("%d", bytes);
}