#include <stdio.h>

void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-1;j++)
		{
			if (a[j]<a[j+1]){
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main ()
{
	int a[]={7,8,9,4,5,6,3,2,1,0},n=10;
	bubble_sort(a,n);
	int i;
	for (i=0;i<n;i++)
	{
		printf ("%d ",a[i]);
	}
	return 0;
}
