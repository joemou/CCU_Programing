#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int warnings;
} ChatMessage;

int main() {
    int n;
    char bannedWord[MAX_MESSAGE_LENGTH];
    ChatMessage messages[MAX_MESSAGES];

    scanf("%d %s", &n, bannedWord);
    getchar(); // Consume the newline character after reading bannedWord

    for (int i = 0; i < n; i++) {
        char line[MAX_NAME_LENGTH + MAX_MESSAGE_LENGTH + 3];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0'; // Remove the trailing newline character

        char *name = strtok(line, ":");
        char *message = strtok(NULL, "\0");
        if (name && message) {
            strcpy(messages[i].name, name);
            strcpy(messages[i].message, message);
            messages[i].warnings = 0;
        } else {
            printf("Invalid input format for message %d\n", i + 1);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        // Check if the banned word is present in the message
        int flag = 0;
        if (messages[i].warnings != -1 && strstr(messages[i].message, bannedWord) != NULL) {
            messages[i].warnings++;
            flag = 1;
            if (messages[i].warnings >= 3) {
                messages[i].warnings = -1;
                printf("%s is banned.\n", messages[i].name);
                flag = 1;
                continue;  // Skip printing the message
            }
        }
        if (flag!=0||messages[i].warnings != -1) {
            printf("%s: %s\n", "", messages[i].message);
        }
    }

    return 0;
}


