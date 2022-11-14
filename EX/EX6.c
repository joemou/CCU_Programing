#include <stdio.h>
#include <ctype.h>
#include <string.h>
//In this exercise, you will use the type definitions you learned in class to classify character types! An English article will be entered for each test, please count the following: ● Total Bytes of the full text (Equivalent to the size of the article archive) ● Number of lowercase alphabets ● Number of uppercase alphabets ● Number of digits ● Number of whitespace (The definition of blank comes from https://cplusplus.com/reference/cctype/isspace/ ) ● Total number of lines (At least one character per line.) Also, you need to count the number of English alphabets in the article and the frequency of their occurrence in the English alphabets, case-insensitive. Hint: you may want to use EOF to test whether the current input is the end of the English article. Also, you can use the functions in the <ctype.h> to help you finish the program. ● Input Format An English article of length n. ● Output Format Refer to the sample output. ● Technical Specifications ■ 0 ≤  𝑛 ≤ 100000 The table below shows the example input and output. The underscored number is the input from users. Input Output I love Rose. 'cause he is   so warm. Bytes Count: 38 Lowercase Count: 22 Uppercase Count: 2 Digit Count: 0 Whitespace Count: 11 Line Count: 3A/a: 2, 0.083 B/b: 0, 0.000 C/c: 1, 0.042 D/d: 0, 0.000 E/e: 4, 0.167 F/f: 0, 0.000 G/g: 0, 0.000 H/h: 1, 0.042 I/i: 2, 0.083 J/j: 0, 0.000 K/k: 0, 0.000 L/l: 1, 0.042 M/m: 1, 0.042 N/n: 0, 0.000 O/o: 3, 0.125 P/p: 0, 0.000 Q/q: 0, 0.000 R/r: 2, 0.083 S/s: 4, 0.167 T/t: 0, 0.000 U/u: 1, 0.042 V/v: 1, 0.042 W/w: 1, 0.042 X/x: 0, 0.000 Y/y: 0, 0.000 Z/z: 0, 0.000


void byte_counts(int x);
void Lowercase_Count(char ar[],int x);
void Uppercase_Count(char ar[], int x);
void Digit_Count(char ar[], int x);
void Whitespace_count(char ar[], int x);
void Lines_count(char ar[], int x);
void English_alphabets_count(char ar[], int x);


int main(){


char input[100000]={0};
int i=0;

for (i = 0; (input[i]=getchar ()) != EOF;i++);


byte_counts(i);
Lowercase_Count(input,i);
Uppercase_Count(input,i);
Digit_Count(input,i);
Whitespace_count(input, i);
Lines_count(input, i);
English_alphabets_count(input, i);

}

//String大小
void byte_counts(int x){
    printf("Bytes Count: %d\n", x);
}

//數小寫
void Lowercase_Count(char ar[],int x){
    int Lowercase_Count=0;
    for (int i = 0; i <= x;i++){
        if('a'<=ar[i]&&ar[i]<='z')
            Lowercase_Count ++;
    }
    printf("Lowercase Count: %d\n", Lowercase_Count);
}

//數大寫
//不懂為啥不行 if(toupper(ar[i])==ar[i]&&ar[i]!='\n'&&ar[i]!=' ') 
void Uppercase_Count(char ar[],int x){
    int Uppercase_Count=0;
    for (int i = 0; i <= x;i++){
        if('A'<=ar[i]&&ar[i]<='Z')
            Uppercase_Count ++;
    }
    printf("Uppercase Count: %d\n", Uppercase_Count);
}

//算數
void Digit_Count(char ar[], int x){
    int Digit_Count=0;
    for (int i = 0; i <= x;i++){
        if('0'<=ar[i]&&ar[i]<='9')
            Digit_Count ++;
    }
    printf("Digit Count: %d\n", Digit_Count);

}

//算空白
void Whitespace_count(char ar[], int x){
     int Whitespace_Count=0;
     for (int i = 0; i <= x;i++){
        if(isspace(ar[i]))
            Whitespace_Count ++;
    }
    printf("Whitespace Count: %d\n", Whitespace_Count);
}

//算行
void Lines_count(char ar[], int x){
    int Line_Count = 0;

    for (int i = 0; i <= x; i++)
    {
        if(ar[i]=='\n'&&ar[i]!=EOF)
            Line_Count ++;
        
    }
    if(Line_Count==0){
        if(ar[0]!=EOF){
            Line_Count = 1;
        }
    }
    printf("Line Count: %d\n", Line_Count);
}

//算字母和比例
void English_alphabets_count(char ar[], int x){
    int alphabet = 0, count_num[26] = {0},sum=0,i=0,k=0,j=0;
    float freq = 0;

    //次數
    for (i = 0; i <= x;i++){

        if('A'<=toupper(ar[i])&&toupper(ar[i])<='Z'){
        alphabet = toupper(ar[i]) - 'A' ;
        count_num[alphabet]++;
        }
    }

    //總和
    for (j = 0; j <=25;j++){
        sum += count_num[j];
    }
    
    //輸出
    freq = (float)count_num[k] / sum;
    
    for (k = 0; k <= 25; k++){
        freq = (float)count_num[k] / sum;

        if(sum==0){
        freq=0;
        }

        printf("%c/%c: %d, %.3f\n", k + 'A', k + 'a', count_num[k],freq);
    }
}
