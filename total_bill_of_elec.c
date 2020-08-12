/* Calculating cost of an electricity bill*/
#include <stdio.h>
int main()
{
	float units,total_cost;
	printf("Enter the number of units:");
	scanf("%f",&units);
	
	if(units<101)
	{
		total_cost=units*1.50;
		printf("The total amount to be paid is %0.2f",total_cost);
	}
	else if(units<201)
	{
		total_cost=150+(units-100)*2.50;
		printf("The total amount to be paid is %0.2f",total_cost);
	}
	else if(units<501)
	{
		total_cost=150+250+(units-200)*3.50;
		printf("The total amount to be paid is %0.2f",total_cost);
	}
	else
	{
		printf("Limit reached!!!");
	}
	return 0;
}