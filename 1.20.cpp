#include<stdio.h>
#include<stdlib.h>
double qinjiushao(double *pa,double x,int n);
int main(void)
{
    int n,i;
    double x;
    double sum;
    double *a;
    printf("Input n and x:\n");
    scanf("%d %lf",&n,&x);
    a=(double *)malloc(n*sizeof(double));
    printf("Input the string:\n");
    for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
    sum = qinjiushao(a,x,n);
    printf("%lf",sum);
    free(a);
}
double qinjiushao(double *pa,double x,int n)
{
    int i;
    double sum = 0;
    for(i=0;i<n;i++)
    {
        sum = x*sum+pa[i];
    }
    return sum;
}
