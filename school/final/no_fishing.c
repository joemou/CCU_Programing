#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 1000
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 4096
#define MAX_BANNED_LENGTH 129
#define MAX_WARNINGS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Message;

int main() {
    int n;
    char banned_word[MAX_BANNED_LENGTH];
    scanf("%d %s", &n, banned_word);
    
    int warning_count[MAX_MESSAGES] = {0};
    int ban_count = 0;
    Message messages[MAX_MESSAGES];
    
    for (int i = 0; i < n; i++) {
        scanf("%s: %[^\n]", messages[i].name, messages[i].message);
        
        // Check if the name has already received three warnings
        if (warning_count[i] >= MAX_WARNINGS) {
            printf("%s is banned.\n", messages[i].name);
            continue;
        }
        
        // Check if the banned word is present in the message
        if (strstr(messages[i].message, banned_word) != NULL) {
            // Add a warning to the name
            warning_count[i]++;
            
            // Check if the name has reached three warnings
            if (warning_count[i] >= MAX_WARNINGS) {
                printf("%s is banned.\n", messages[i].name);
                ban_count++;
                continue;
            }
        }
        
        // Print the line if no filtering is required
        printf("%s: %s\n", messages[i].name, messages[i].message);
    }
    
    return 0;
}
