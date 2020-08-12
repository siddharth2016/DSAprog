/* Alert on a high temperature*/
#include <stdio.h>
void main()
{
	float temp=0;
	printf("Enter the temperture of the furnace:");
	scanf("%f",&temp);
	if(temp>500){
		printf("\a\aAlert too high temperature!!");
	}
	else{
		printf("Moderate conditions no problem!");
	}
}