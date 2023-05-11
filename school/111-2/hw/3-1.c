#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_LINE_LEN 60

struct word_node {
    char word[MAX_WORD_LEN + 1];
    struct word_node *next;
};

struct word_node *line_start = NULL;
struct word_node *line_end = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct word_node *current = line_start;
    while (current != NULL) {
        struct word_node *temp = current;
        current = current->next;
        free(temp);
    }
    line_start = NULL;
    line_end = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0) {
        line_end->next = (struct word_node*) malloc(sizeof(struct word_node));
        line_end = line_end->next;
        line_end->next = NULL;
        strcpy(line_end->word, " ");
        line_len++;
    }

    struct word_node *new_node = (struct word_node*) malloc(sizeof(struct word_node));
    new_node->next = NULL;
    strcpy(new_node->word, word);
    if (line_start == NULL) {
        line_start = new_node;
        line_end = new_node;
    } else {
        line_end->next = new_node;
        line_end = new_node;
    }
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    struct word_node *current = line_start;

    extra_spaces = MAX_LINE_LEN - line_len;
    while (current != NULL) {
        printf("%s", current->word);
        if (current->next != NULL) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
        current = current->next;
    }
    putchar('\n');
}

void flush_line(void)
{
    struct word_node *current = line_start;
    while (current != NULL) {
        printf("%s", current->word);
        current = current->next;
    }
    putchar('\n');
}
int main(void)
{
  char word[MAX_WORD_LEN+2];  // Maximum word length + newline + null terminator
  int word_len;

  clear_line();

  while (scanf("%s", word) != EOF) {
    word_len = strlen(word);
    if (word_len > MAX_WORD_LEN) {
      fprintf(stderr, "Word too long\n");
      exit(EXIT_FAILURE);
    }
    if (space_remaining() < word_len) {
      add_word("\n");
      write_line();
      clear_line();
    }
    add_word(word);
  }

  write_line();
  return 0;
}







