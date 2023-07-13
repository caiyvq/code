#include "a.h"

void comb(int a[], int l, int m, int r)
{
	int temp[r-l+1], i = l, j = m + 1, k = 0;
	while (i < m + 1 && j < r + 1)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= r)
		temp[k++] = a[j++];

	for (int z = l; z <= r; z++)
		a[z] = temp[z - l];
}

void mergesort(int a[], int l, int r)
{

	if (l < r)
	{
		int m = l+ (r - l) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		comb(a, l, m, r);
	}
	else
		return;
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quicksort(int a[], int l, int r) //qsort源代码改
{
	int i, pivot;
	if (l >= r)
	{
		return;
	}

	swap(a, l, l + (r - l) / 2);
	pivot = l;
	for (i = l + 1; i <= r; i++)
	{
		if (a[i] < a[l])
		{
			swap(a, ++pivot, i);
		}
	}

	swap(a, l, pivot);
	quicksort(a, l, pivot - 1);
	quicksort(a, pivot + 1, r);
}

void ptr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}