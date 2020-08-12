// BINOMIAL COEFFICIENT BOTTOM UP APPROACH
#include <stdio.h>
int main()
{
    int ncr(int M[50][50],int n,int r);
    int val(int M[50][50],int n,int r);
    int n,r,M[50][50]={0};
    scanf("%d",&n);
    scanf("%d",&r);
    printf("%d",ncr(M,n,r));
    return 0;
}
int ncr(int M[50][50],int n,int r)
{
    int i,j,x;
    for(j=0;j<=r;j++)
    {
        for(i=1;i<=n;i++)
            x=val(M,i,j);
    }
    return x;
}
int val(int M[50][50],int n,int r)
{
    if(n==r || r==0)
        return 1;
    else if(M[n][r])
        return M[n][r];
    else
    {
        M[n][r]=val(M,n-1,r)+val(M,n-1,r-1);
        return M[n][r];
    }
}
