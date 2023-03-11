#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int type, num;
    char str[100][101];
    char ans[101];
    
    scanf("%d", &type);
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%s", str[i]);
        
        if (type == 2) {
            for (int j = 0; str[i][j]; j++) {
                str[i][j] = tolower(str[i][j]);
            }
        }
    }
    
    int len = strlen(str[0]);
    for (int i = 1; i < num; i++) {
        int j;
        for (j = 0; j < len && str[0][j] == str[i][j]; j++);
        len = j;
    }
    
    if (len == 0) {
        printf("No longest common prefix\n");
    } else {
        strncpy(ans, str[0], len);
        ans[len] = '\0';
        
        if (type == 2) {
            for (int i = 0; ans[i]; i++) {
                ans[i] = tolower(ans[i]);
            }
        }
        
        printf("%s\n", ans);
    }
    
    return 0;
}







