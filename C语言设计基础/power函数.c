#include<stdio.h>
int power(int m,int n);
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
    printf("%d",power(m,n));
}
int power(int base,int n)
{
	int i,p;
	p=1;
	for(i=1;i<=n;++i)p=p*base;
	return p;
}
