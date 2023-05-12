#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 20
#define MAX_LINE_LEN 60

typedef struct node {
  char *word;
  struct node *next;
} Node;

Node *head = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp->word);
    free(temp);
  }
  head = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  Node *new_node = malloc(sizeof(Node));
  if(strlen(word) + 1<=21){
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
  }
  else{
    new_node->word = malloc(strlen(word) + 2);
    strncpy(new_node->word, word,20);
    new_node->word[20] = '*';
    new_node->word[21] = '\0';
  }
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    Node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }

  if (num_words > 0) {
    line_len++;
  }
  line_len += strlen(new_node->word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  if (num_words == 1) {
    printf("%s\n", head->word);
    return;
  }
  for (Node *current = head; current != NULL; current = current->next) {
    printf("%s", current->word);
    if (current->next != NULL) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  for (Node *current = head; current != NULL; current = current->next) {
    printf("%s ", current->word);
  }
  putchar('\n');
}
