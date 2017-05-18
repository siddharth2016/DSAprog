/* finding leader from the set of numbers*/
#include <stdio.h>
int main()
{
	int A[10];
	printf("\nEnter the values for the list\n");
	for(int i=0,i<=9,i++)
	{
		scanf("%d",A[i]);
	}
	for(int j=0,j<10,j++)
	{
		if(A[j]<A[int x=j+1])
		{
			for(int y=j,y<n-1,y++)
			{
				A[y]=A[y+1];
			}
		}
		else
		{
			j=j+1;
		}
	}
	printf("%d",A);
	return 0;
}