//BINOMIAL COEFFICIENT - TOP DOWN APPROACH
#include <stdio.h>
int main()
{
    int ncr(int M[50][50],int n,int r);
    int n,r,M[50][50]={0};
    scanf("%d",&n);
    scanf("%d",&r);
    printf("%d",ncr(M,n,r));
    return 0;
}
int ncr(int M[50][50],int n,int r)
{
    if(n==r || r==0)
        return 1;
    if(M[n][r])
        return M[n][r];
    else
    {
        M[n][r]=ncr(M,n-1,r)+ncr(M,n-1,r-1);
        return M[n][r];
    }
}
