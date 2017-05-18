/* BINOMIAL COEFFICIENT */
#include <stdio.h>
int main()
{
    int fact(int n);
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    nCr=fact(n)/(fact(k)*fact(n-k));
    printf("%d",nCr);
    return 0;
}

int fact(int n)                    //Dividing the given problem into sub problem of factorial and then conquering it
{
    if(n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}
