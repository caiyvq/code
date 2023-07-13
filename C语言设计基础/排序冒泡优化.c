#include<stdio.h>
void bubble(int arr[], int n)
{
	int i=0;
	int tmp=0;
	int flag=0;
	int pos=0;
	int k=n-1;
	for (i=0; i<n-1;i++)
	{
		pos=0;
		int j=0;
		flag=0;
		for (j=0;j<k;j++)
		{
			if (arr[j]<arr[j+1])
			{
				tmp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=1;
				pos=j;
			}
		}
		if (flag==0)
		{
			return;
		}
		k=pos;
	}
}
int main()
{
    int n,a[500000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble(a,n);
    for(int i=0;i<n;i++)
    {
        if(i==0)printf("%d",a[i]);
        else printf(" %d",a[i]);
       
    }
}
