#include<stdio.h>
int main()
{
	int number,pos,b,c;
	printf("Enter the number ");  
	scanf("%d",&number);
	printf("Enter the position at which to toggle the bit "); 
	scanf("%d",&pos);
	b=1<<pos-1;    
	c=number^b;
	printf("The result is %d",c);	
	
}
	

