#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"
#include "binkoef.h"
#include "maxmin.h"
#include "matrix.h"

int main(int argc, char *argv[])
{
    int i,n,k;
    pair ret;
    n=42;
    printf("Fibonacciho cislo - REKURZIVNE (DnC) [CAKAJTE POCITAM...]\n");
    printf("Fib(%d)=%d\n",n,FibDnC(n));
    printf("Fibonacciho cislo - DYNAMICKE PROGRAMOVANIE\n");
    printf("Fib(%d)=%d\n",n,FibDP(n));
    printf("Fib(%d)=%d\n",n,FibDP2(n));
    n=32;k=12;

    printf("\nBinomicky koeficient - REKURZIVNE (DnC) [CAKAJTE POCITAM...]\n");
    printf("BinKoef(%d,%d)=%d\n",n,k,BinKoefDnC(n,k));
    printf("Binomicky koeficient - DYNAMICKE PROGRAMOVANIE\n");
    printf("BinKoef(%d,%d)=%d\n",n,k,BinKoefDP(n,k));

    printf("\nDnC MaxMin:");
	int hodnoty[]={10,-15,8,13,6,12,11,9,25};
    for(i=0;i<=8;i++)printf(" %d",hodnoty[i]);
    ret = MaxMin(hodnoty,0,8);
    printf("\nMax: %d Min: %d", ret.max, ret.min);

    printf("\n\nMINIMALNY POCET OPERACII PRI NASOBENI MATIC:\n");
    int rozmery[]={ 10, 20, 50, 1 ,100 };
    for(i=1;i<=4;i++)printf("    M%d (%3d,%3d)\n",i,rozmery[i-1],rozmery[i]);
    printf("Vysledok: %d\n\n",chainMatrixMultiplication(rozmery,4));

    printf("\n");
    system("PAUSE");
    return 0;
}
