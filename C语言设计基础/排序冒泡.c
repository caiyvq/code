#include <stdio.h>
void bubble (int a[ ], int n);
void ptr(int *a,int n)
{
	for (int i=0; i<n; i++)
        printf("%d ",a[i]);
		printf("\n");
}
int main(void)
{    
  int n, a[10];
    int i;
    scanf("%d", &n);
    for (i=0; i<n;i++)
        scanf("%d",&a[i]);
    bubble(a,n);
    ptr(a,n);
  
    return 0;
}

/* 请在这里填写答案 */
void bubble (int a[ ], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
		ptr(a,n);
    }
}