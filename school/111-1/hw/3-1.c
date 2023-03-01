#include <stdio.h>

int main (){

    int i, j, gcd, k;
    scanf("%d %d", &i, &j);
    

  if(i==0&&j==0){
      printf("%d", i);
      return 0;
  }
  
  if(i==0){
      printf("%d", j);
      return 0;
  }
  
  if(j==0){
      printf("%d", i);
      return 0;
  }



else{
  for (k = 1; i >= k && j >= k; k++)
  {

      if (i % k == 0 && j % k == 0)
      {

          gcd = k;
      }
    }

    printf("%d\n", gcd);
}
    return 0;
}