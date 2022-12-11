#include<stdio.h>
int main()
{
  for (int i = 0; i < 20;i++){
    printf("%d\n", ((rand() % 9)+1));
  }
    return 0;
}