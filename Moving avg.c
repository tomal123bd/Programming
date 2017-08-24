#include <stdio.h>
int main ()
{
	freopen("input(Moving avg).txt","r",stdin);
	int N,Y_M_A,i,j,count=1,temp;
	printf("Input Total Year:\n");
	scanf ("%d",&N);
	printf("Input Moving Average:\n");
	scanf ("%d",&Y_M_A);
	int years[N],values[N];
	printf("Input Year:\n");
	for (i=1;i<=N;i++){
		scanf("%d",&years[i]);
	}
	printf("Input Value:\n");
	for (i=1;i<=N;i++){
		scanf("%d",&values[i]);
	}
    int n_y_m_a_1[N];float n_y_m_a_2[N], n_y_m_a_3[N],n_y_m_a_4[N];
	for (i=1;i<=N;i++){
		n_y_m_a_1[i]=0;n_y_m_a_2[i]=0;
		n_y_m_a_3[N]=0.0;n_y_m_a_4[N]=0.0;
	}
    for (i=1;i<=N;i++){
        for (j=i;count<=Y_M_A;j++,count++){
            n_y_m_a_1[i]=n_y_m_a_1[i]+values[j];
        }
        count=1;
        if (i+Y_M_A>N)break;
    }
    for (j=1;j<=i;j++){
        printf ("%d ",n_y_m_a_1[j]);
        n_y_m_a_2[j]=(float)n_y_m_a_1[j]/(float)Y_M_A;
    }
    printf ("\n");
    for (j=1;j<=i;j++){
        printf ("%f ",n_y_m_a_2[j]);
    }
    temp=i;count=1;
    if (Y_M_A%2==0){
        for (i=1;i<=temp;i++){
        for (j=i;count<=2;j++,count++){
            n_y_m_a_3[i]=n_y_m_a_3[i]+n_y_m_a_2[j];
        }
        count=1;
        if (i+2>temp)break;
        }
        printf ("\n");
        for (j=1;j<=i;j++){
            n_y_m_a_4[j]=n_y_m_a_3[j]/(float)2;
            printf ("%f ",n_y_m_a_4[j]);
        }
    }
    return 0;
}
