/* finding code for the password in digits*/
#include <stdio.h>
#include <math.h>
int main(){
	int digit=0;
	int digit1;
	int digit2;
	int digit3;
	int pass;
	printf("Enter the digit:");
	scanf("%d",&digit);
	digit1=digit;
	digit2=digit;
	digit3=digit;
	int count=0;
	while(digit!=0){
		int r=digit%10;
		digit=digit/10;
		count=count+1;
	}
	
	if(count==2){
		int r1=digit1%10;
		digit1=digit1/10;
		pass=r1+digit1;
		printf("The required code is %d",pass);
	}
	else if(count==3){
		pass=sqrt(digit2);
		printf("The required code is %d",pass);
	}
	else if(count==4){
		int r2=digit3%10;
		digit3=digit3/1000;
		pass=r2+digit3;
		printf("The required code is %d",pass);
	}
	else{
		printf("Entered wrong passcode to modify!!!\a\a\a");
	}
	return 0;
}