//MATRIX CHAIN MULTIPLICATION
#include <stdio.h>
#include <limits.h>
int main()
{
    int MatrixChain(int p[],int i,int j);
    int A[100],i,a,x;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
        scanf("%d",&A[i+1]);
    }
    x=MatrixChain(A,1,a);
    printf("%d",x);
    return 0;
}
int MatrixChain(int p[],int i,int j)
{
    if(i==j)
        return 0;
    int k;
    int min=INT_MAX;
    int sum;

    for (k=i;k<j;k++)
    {
        sum=MatrixChain(p,i,k)+MatrixChain(p,k+1,j)+p[i-1]*p[k]*p[j];
        if (sum<min)
            min=sum;
    }

    return min;
}
