#include<stdio.h>
int main()
{
	int n,count=0;
	printf("enter any number\n");
	scanf("%d",&n);
	while(n>0)
	{
		if(n&1)
		count++;
		n=n>>1;
	}
	printf("%d",count);
}
