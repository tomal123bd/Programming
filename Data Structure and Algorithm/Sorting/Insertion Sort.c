#include <stdio.h>

void insertion_sort(int a[],int n)
{
	int i,j,k,temp;
	for (i=0;i<n;i++){
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]<temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
	}
}

int main ()
{
	int a[]={7,8,9,6,5,4,1,2,3,0},n=10,i;
	insertion_sort(a,n);
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	return 0;
}
