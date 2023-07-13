#include<stdio.h>
int fact(int n);
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fact(n));
	return 0;
} 
int fact(int n)
{
	int s=1;
	while(n!=1){
	if(n!=0){s=s*n;n=n-1;}
	else {s=1;n=1;}
	}
	return s;
}
