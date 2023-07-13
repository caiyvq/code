#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

void ptr(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void swap(int *v, int i, int j)
{
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void q_sort(int *v, int left, int right)
{
  int i, last;
  if (left >= right)
  {
    return;
  }

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
  {
    if (v[i] < v[left])
    {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  q_sort(v, left, last - 1);
  q_sort(v, last + 1, right);
}

int main()
{
  srand(0);
  int n, a[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    //scanf("%d",&a[i]);
    a[i] = rand() % 10000;
  }
  ptr(a, n);
  q_sort(a, 0, n - 1);
  //qsort(a,n,4,comp);
  ptr(a, n);
  return 0;
}