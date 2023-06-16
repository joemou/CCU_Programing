#include <stdio.h>

int canGiveAwayDessert(int a, int b) {
    // Check if it's possible to give away all desserts
    if ((a + b) % 3 == 0 && a >= (a + b) / 3 && b >= (a + b) / 3) {
        return 1; // YES
    } else {
        return 0; // NO
    }
}

int main() {
    int t;
    scanf("%d", &t); // Read the number of test cases
    
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b); // Read the number of candy and cookies
        
        if (canGiveAwayDessert(a, b)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
