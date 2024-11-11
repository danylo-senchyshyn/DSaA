#include "fibonacci.h"

int FibDnC(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    else return FibDnC(n-1)+FibDnC(n-2);
}

int FibDP(int n){
    int fib[n+1];
    int i;
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<=n;i++)fib[i]=fib[i-1]+fib[i-2];
    return fib[n];
}

int FibDP2(int n){
    int i1,i2,z;
    int i;
    i1=1;
    i2=0;
    z=0;
    if(n==1)return 1;
    for(i=2;i<=n;i++){
        z=i1+i2;
        i2=i1;
        i1=z;
        }
    return z;
}
