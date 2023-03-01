#include <stdlib.h>
#include <stdio.h>

int main ()
{

  int b, s, l;			//b:blood,s:strength,l:level
  int monster_type, ms, bl;	//ms:monster strength,bl:blood loose
  int power;

  printf ("Welcome, Adventurer!\n");
  printf ("Please enter blood, strength, level:\n");
  scanf ("%d %d %d", &b, &s, &l);
  printf("You have %d blood and %d strength.\n",b,s);
  
do{  
  printf ("Please choose which monster (1 to 4) you want to fight:\n");
  scanf ("%d", &monster_type);

    while(monster_type > 4 || monster_type < 0){
    
     printf("No such monster, please enter 1 to 4 to choose the monster.\n");    
     printf("Do you want to go on your adventure (1: Yes; 0: No) ?:\n");
     scanf ("%d", &power);
     
     if(power==1){
         printf("You have %d blood and %d strength.\n",b,s);  
         printf ("Please choose which monster (1 to 4) you want to fight:\n");
         scanf ("%d", &monster_type);
     }
     else{
         printf("We will miss you. Bye!\n");
         exit(0);
     }
    }
  
  switch (monster_type)
    {

    case 1:
      ms = l;
      bl = 1 + l;
      break;

    case 2:
      ms = (l % 2) + 2;
      bl = 2 + l;
      break;

    case 3:
      if (l > 3)
	{
	  ms = l;
	}
      else
	{
	  ms = 3;
	}
      bl = 3 + l;
      break;

    case 4:
      ms = l * 4;
      bl = 4 + l;
      break;
    }
  printf ("You are fighting Monster %d!\n", monster_type);
  
  if(s>ms){
      printf("You Win!\n");
      s += 1;
  }
  else{
      printf("You Lose!\n");
      b = b-bl;
  }
  
  printf("Do you want to go on your adventure (1: Yes; 0: No) ?:\n");
  scanf ("%d", &power);
     if(power==1){
         printf("You have %d blood and %d strength.\n",b,s);
     }
     else{
         printf("We will miss you. Bye!\n");
         exit(0);
     }
     
     if(b<1){
         printf("You Dead. Bye!\n");
         exit(0);
     }
}while(power==1);
  return 0;
}
