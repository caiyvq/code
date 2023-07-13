#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int l,int m,int r)
{
	int temp[r - l + 1],i = l,j= m + 1,k=0;
	while(i < m + 1 && j < r + 1)
	{
		if(a[i] <= a[j])temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}

	while(i <= m)temp[k++] = a[i++];

	while(j <= r)temp[k++] = a[j++];

	for(int z = l;z <= r;z++)a[z] = temp[z -l];
}

void mergesort(int *a,int l,int r)
{

	if(l < r)
	{
		int m=(l + r) / 2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
	else return ;
}

void ptr(int *a,int n)
{
	for(int i =0;i < n;i++)
	{
		printf ("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	srand(0);
	int n,a[100];
	scanf("%d",&n);
	for(int i = 0;i < n ;i++)
	{
		a[i] = rand()%100;
	}
	//ptr(a,n);
	mergesort(a,0,n-1);
	ptr(a,n);
	return 0;
}