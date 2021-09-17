#include<stdio.h>
int main()
{   int number,count=0,lastbit;
	printf("Enter the decimal number \n");
	scanf("%d",&number);
	
	while(number!=0)
	{
	lastbit=number & 1;
	if(lastbit==1)
	{
		count++;
	}
	number=number>>1;
	
	}
	if(count==1)
	{
		printf("Enter no is power of 2\n");
	}
	else{
		printf("Enter no is power not of 2\n");
	}  
   
	
}
