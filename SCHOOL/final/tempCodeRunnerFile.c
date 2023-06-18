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

    for (int i = 0; i < n; i++) {
        scanf("%s:  %s", messages[i].name, messages[i].message);
        messages[i].warnings = 0;
    }

    for (int i = 0; i < n; i++) {
        // Check if the banned word is present in the message
        if ((messages[i].warnings != -1) && strstr(messages[i].message, bannedWord) != NULL) {
            messages[i].warnings++;
            if (messages[i].warnings >= 3) {
                messages[i].warnings = -1;
                printf("%s is banned.\n", messages[i].name);
            }
        }
        if(messages[i].warnings!=-1){
            printf("%s: %s\n", messages[i].name, messages[i].message);
        }
    }

    return 0;
}
