#include <stdio.h>
#include <stdlib.h>
#include "tree_arr.h"
#include "err.h"

int main()
{
  Tree T;
  int maxlevel,level,index;
  int i;

  printf("\nEnter max. level of a tree (1...n):");
  i = scanf("%d", &maxlevel);
  if(i != 1) Error("Enter Number 1...n!");

  T = CreateTree( maxlevel );

  for(i = 1; i<pow(2,maxlevel+1);i++)
        {
        Insert(T,i,4+i);
        printf("\n Inserting: element %02d at index [%d]",4+i,i);
        }

  printf("\n\nBinary tree:\n");
  PrintTree( T );

  printf("\n\n(PrintRow) Enter binary tree level: ");
  scanf("%d",&level);
  putchar(32);
  //PrintRow( T, level );

  printf("\n\n(PrintSubtree) Enter the root (index) of subtree: ");
  scanf("%d",&index);
  putchar(32);
  //PrintSubtree( T, index );

  DisposeTree( T );
  putchar('\n');

  return 0;
}
