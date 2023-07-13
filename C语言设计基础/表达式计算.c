#include<stdio.h>
#include<string.h>

char n[100];

double num(int left, int right)
{
    double ret = 0;
    for(int i = left; i <= right; i++)
        ret = ret * 10 + n[i] - '0';
    return ret;
}

double part(int l, int r)
{
    int par = 0, add = 0, mul = 0,mns = -1;
    for(int i = l; i <= r; i++)
	{
        if(n[i] == '(' )par++;
        else if(n[i] == ')')par--;
        else if(!par)
		{
			if(n[i]=='+')add=i;
			else if(n[i]=='*'||n[i]=='/'||n[i]=='%')mul=i;
			else if(n[i]=='-')
			{
				if(i==0)mns=i;
				else if(n[i-1]=='('||n[i-1]=='*'||n[i-1]=='/'||n[i-1]=='%'||n[i-1]=='+'||n[i-1]=='-')mns=i;
				else add=i;
			}
            
        }
       
    }


    if(!par && !add && !mul)
	{
		if(mns<0)
		{
			if(n[l] == '(' && n[r] == ')')return part(l + 1, r - 1);
       		 else return num(l, r);
		}
        else return -part(l+1,r);
    }
    if(add)
    {
    	if(n[add] == '+')return part(l, add-1) + part(add+1, r);
        else if(n[add]=='-')return part(l, add-1) - part(add+1, r);
    }
    if(mul)
    {
    	if(n[mul] == '*')return part(l, mul-1) * part(mul+1, r);
        else if(n[mul]=='/') return part(l, mul-1) / part(mul+1, r);
        else if(n[mul]== '%')return (int)part(l, mul-1) % (int)part(mul+1, r);
	}
	
	return 0;
}

int main()
{
    gets(n);
    printf("%d",(int)part(0,strlen(n)-1));
    return 0;
}
