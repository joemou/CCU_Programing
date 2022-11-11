#include <stdio.h>
#include <ctype.h>

struct student{
  int age;
  char name[10];
};


int main(){
  struct student lynn = {23, {'l', 'y', 'n', 'n', '\0'}};
  printf("%d \n", lynn.age);
  printf("%s \n", lynn.name);

  struct student joe = {23, {'j', 'o', 'e'}};
  printf("%d", joe.age);
  return 0;
}