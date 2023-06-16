#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m); // Read the length of the number a
    
    char a[101]; // Since a can have up to 100 digits, plus 1 for null terminator
    scanf("%s", a); // Read the number a as a string
    
    unsigned int b;
    scanf("%u", &b); // Read the number b
    
    // Perform division of a by b using long division algorithm
    unsigned int remainder = 0;
    
    for (int i = 0; i < m; i++) {
        remainder = (remainder * 10 + (a[i] - '0')) % b;
    }
    
    printf("%u\n", remainder); // Output the remainder
    
    return 0;
}
