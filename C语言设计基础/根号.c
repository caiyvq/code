#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float s,z,p;
	scanf("%d %d %d",&a,&b,&c);
	p=(a+b+c)/2.0;
	if(a+b>c&&b+c>a&&a+c>b){
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		z=a+b+c;
		printf("area = %.2f; perimeter = %.2f",s,z);
	}
	else{
		printf("These sides do not correspond to a valid triangle");
	}
	return 0;
}
