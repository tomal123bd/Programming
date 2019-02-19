#include <stdio.h>
selection_sort(int a[],int n)
{
    int i,j,k,m,temp;
    for (i=0;i<n;i++){
        m=a[i];
        k=i;
        for (j=i;j<n;j++){
            if (m<a[j]){
                m=a[j];
                k=j;
            }
        }
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
}
int main ()
{
    int a[]={9,8,7,4,5,6,3,2,1,0};
    int n=10;
    selection_sort(a,n);
    int i;
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
