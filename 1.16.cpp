#include<stdio.h>
# define N 3
void sort(int*a,int n);
int main(void)
{
    int num[3];
    printf("Input three numbers:\n");
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    sort(num,N);
    printf("%d %d %d",num[0],num[1],num[2]);
    return 0;
}
void sort(int*a,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
}
