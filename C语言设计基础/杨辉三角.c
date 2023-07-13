#include<stdio.h>

int Yang(int i, int j);
int main()
{
    int n, i, j;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%-4d", Yang(i,j));
        }
        printf("\n");
    }
    return 0;
}

int Yang(int i, int j)
{
	if(j==1)return 1;
	else if(j>i)return 0;
	else
	{
		return Yang(i-1,j-1) + Yang(i-1,j);
	}
	
}