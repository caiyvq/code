#include<stdio.h> 
main(){
	printf("    华氏度摄氏度转换表\n");
	float F,C;
	float L,U,S;
	L=0,U=300,S=-20;
	F=U;
	while(F>=L){
    C=5.0*(F-32.0)/9.0;
	printf("    %-3.0f %-6.2f\n",F,C);
	F=F+S;}
}
