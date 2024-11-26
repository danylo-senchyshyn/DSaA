#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"


char *A[]={
     "asd","fgh","jkl","qwe","rty","uio","ppp","zxc","vbn","mmm",
     "www","bbb","eee","ccc","xxx","aaa","ggg","ooo","yyy","kkk",
     "ddd","fff","zzz","ttt","jjj"
     };
     
int main(int argc, char *argv[])
{
  int i;
  PHASHTABLE t;
  t=HTinit(23);
  for(i=0;i<25;i++)HTinsert(t,A[i]);
  HTprint(t);
  
  printf("\nHladam AAA: ");
  if(HTmember(t,"AAA"))printf("V tabulke\n");
  else printf("Nie je v tabulke\n");
  printf("Hladam ppp: ");
  if(HTmember(t,"ppp"))printf("V tabulke\n");
  else printf("Nie je v tabulke\n");
  
  printf("Odstranenie ppp\n");
  HTdelete(t,"ppp");
  printf("Hladam ppp: ");
  if(HTmember(t,"ppp"))printf("V tabulke\n");
  else printf("Nie je v tabulke\n");


  system("PAUSE");	
  return 0;
}
