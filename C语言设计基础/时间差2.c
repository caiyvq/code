#include<stdio.h>
int main()
{
	int h,m,H,M;
	scanf("%d %d",&h,&m);
	scanf("%d %d",&H,&M);
	int im,ih;
	im=M-m;
	ih=H-h;
	if(im<0){
		im=60+im;
		ih=ih-1;
	}
	printf("%d %d",ih,im);
}
