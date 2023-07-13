#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
void ptr(int *a,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
int main()
{
    int *a,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),comp);
    ptr(a,n);
    printf("\n%d %d %d",sizeof(a),sizeof(a[0]),sizeof(a)/sizeof(a[0]));
} 