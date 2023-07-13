#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	int t=c*60+d-a*60-b;
	printf("%d %d",t/60,t%60);
}
