#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 5000
#define MAX_NAME_LENGTH 5000
#define MAX_MESSAGE_LENGTH 5000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} ChatMessage;

// Node structure for the map
typedef struct {
    char* key;
    int value;
} MapNode;

// Function to create a new map node
MapNode* createNode(const char* key, int value) {
    MapNode* node = (MapNode*)malloc(sizeof(MapNode));
    node->key = strdup(key);
    node->value = value;
    return node;
}



// Function to get the value associated with a key in the map
int getValue(MapNode** map, const char* key) {
    for (int i = 0; map[i] != NULL; i++) {
        if (strcmp(map[i]->key, key) == 0) {
            return map[i]->value;
        }
    }
    return -1;  // Key not found
}

void changeValue(MapNode** map, const char* key, int newValue) {
    for (int i = 0; map[i] != NULL; i++) {
        if (strcmp(map[i]->key, key) == 0) {
            map[i]->value = newValue;
            return;
        }
    }
}

int main() {
    int n;
    char bannedWord[MAX_MESSAGE_LENGTH];
    ChatMessage messages[MAX_MESSAGES];

    MapNode* map[MAX_MESSAGES];
    int mapSize = 0;

    scanf("%d %s", &n, bannedWord);
    getchar();  // Consume the newline character after reading bannedWord

    for (int i = 0; i < n; i++) {
        char line[MAX_NAME_LENGTH + MAX_MESSAGE_LENGTH + 3];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';  // Remove the trailing newline character

        char* name = strtok(line, ":");
        char* message = strtok(NULL, "\0");
        if (name && message) {
            strcpy(messages[i].name, name);
            strcpy(messages[i].message, message);

            // Check if the name is already in the map
            int existingIndex = -1;
            for (int j = 0; j < mapSize; j++) {
                if (strcmp(map[j]->key, name) == 0) {
                    existingIndex = j;
                    break;
                }
            }

            if (existingIndex == -1) {
                // Name not found in the map, create a new node
                map[mapSize] = createNode(name, 0);
                mapSize++;
            }
        } 
    }

    for (int i = 0; i < n; i++) {
        // Check if the banned word is present in the message
        int flag = 0;
        if (strstr(messages[i].message, bannedWord) != NULL) {
            changeValue(map, messages[i].name, (getValue(map, messages[i].name) + 1));
            flag = 1;
            if (getValue(map, messages[i].name) >= 3) {
                printf("%s is banned.\n", messages[i].name);
                continue;  // Skip printing the message
            }
        }
        if (flag == 0 && getValue(map, messages[i].name) < 3) {
            printf("%s: %s\n", messages[i].name, messages[i].message);
        }
    }



    return 0;
}




