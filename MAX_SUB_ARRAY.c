/* MAXIMUM SUB ARRAY PROBLEM */
#include <stdio.h>
int main()
{
    int max_sub(int A[],int i,int n);
    int maximum(int a,int b);
    int n,A[100],i=0,max,B[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",A+i);
    for(i=0;i<n;i++)
        B[i]=max_sub(A,i,n);
    max=B[0];
    for(i=0;i<n;i++)
    {
        if(B[i]>max)
            max=B[i];
    }
    printf("%d",max);
    return 0;
}
int maximum(int a,int b)
{
    if(a>b)
        return a;
    else if(a<b)
        return b;
    else
        return a;
}
int max_sub(int A[],int i,int n)
{
    int ans=0,sum=0;
    int j=0;
    for(j=i;j<n;j++)
    {
        if(sum+A[j]>0)
            sum=sum+A[j];
        else
            sum=0;
        ans=maximum(ans,sum);
    }
    return ans;
}
