/* Helping Rama for measuring the distance in standard metrics*/
#include <stdio.h>
#define MILE 1.602
int main()
{
	float kilometer,miles;
	printf("Enter the miles for to travel:");
	scanf("%f",&miles);
	
	kilometer=miles*MILE;
	
	printf("The distance in the standard metrics is %0.2f",kilometer);
	return 0;
}