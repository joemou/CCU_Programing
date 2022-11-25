#include <stdio.h>

int main(){

    int marks[10], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        printf("Enter number%d: ", i + 1);
        scanf("%d", &marks[i]);     
  }

  for(int i=0; i < n; ++i) {
      printf("%d", marks[i]);
 }


}
