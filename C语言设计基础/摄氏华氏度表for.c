#include<stdio.h> 
main(){
	int F;
	for(F=0;F<=300;F=F+20)
	printf("%3d %6.1f\n",F,(5.0/9.0)*(F-32));
}
