#include <stdio.h>
#include <stdlib.h>
#include "traverse.h"

              /* x,v1,v2,v3,v4,v5,v6,v7,v8,v9 */
int t1Value[]={  0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int t1Left[]={   0, 2, 4, 6, 0, 8, 0, 0, 0, 0};
int t1Right[]={  0, 3, 5, 0, 7, 0, 9, 0, 0, 0};

              /* x,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14 */
int t2Value[]={  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14};
int t2Left[]={   0, 2, 4, 7, 9, 0, 0,11, 0, 0, 0, 0, 0, 0, 0};
int t2Middle[]={ 0, 0, 5, 0, 0, 0, 0,12, 0, 0, 0, 0, 0, 0, 0};
int t2Right[]={  0, 3, 6, 8, 0,10, 0,13,14, 0, 0, 0, 0, 0, 0};

int main(int argc, char *argv[])
{
  printf("\n************** Binarny strom - rekurzivne **************\n");
  printf("\n");
  SetBT(t1Value,t1Left,t1Right);
  printf("  INORDER: ");
  inorder(1);
  printf("\n");
  printf(" PREORDER: ");
  preorder(1);
  printf("\n");
  printf("POSTORDER: ");
  postorder(1);
  printf("\n");
  printf("\n************** Binarny strom - level-order **************\n");
  printf("\n");
  printf("LEVEL-ORDER: ");
  levelorder(1);
  printf("\n");
  printf("\n************** Binarny strom - nerekurzivne **************\n");
  printf("\n");
  printf("  INORDER: ");
  inorderNR(1);
  printf("\n");
  printf(" PREORDER: ");
  preorderNR(1);
  printf("\n");
  printf("\n************** Ternarny strom - rekurzivne **************\n");
  SetTT(t2Value,t2Left,t2Middle,t2Right);
  printf("\n");
  printf(" PREORDER: ");
  preorderTT(1);
  printf("\n");
  printf("POSTORDER: ");
  postorderTT(1);
  printf("\n");
  printf("\n");
  //  system("PAUSE");
  return 0;
}
