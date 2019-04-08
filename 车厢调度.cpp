#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct
{
    int data[Maxsize];
    int top;
}Sepstack,*pSepstack;
pSepstack init()
{
    pSepstack S = (pSepstack)malloc(sizeof(Sepstack));
    S->top = -1;
    return S;
}
void push(pSepstack S, int x)
{
    if(S->top==Maxsize-1)
      printf("栈已满");
    else
    S->data[++S->top] = x;
}
int pop(pSepstack S)
{
    if(S->top==-1)
        printf("栈已空");
    else
    {
        int x = S->data[S->top--];
        return x;
    }
}
int Empty(pSepstack S)
{
    if(S->top==-1)
        return 1;
    else
        return 0;
}
pSepstack destory(pSepstack S)
{
    free(S);
    return NULL;
}
void process(pSepstack S,int n,int pos,int *path,int court)
{
    int m,i;
   if(pos<n)
   {
       push(S,pos+1);
       process(S,n,pos+1,path,court);
       pop(S);
   }
   if(!Empty(S))
   {
       m = pop(S);
       path[court] = m;
       court++;
       process(S,n,pos,path,court);
       push(S,m);
   }
   if(Empty(S)&&pos==n)
   {
       for(i=0;i<n;i++)
       {
           printf("%d ",path[i]);
       }
       printf("\n");
   }
}
int main(void)
{
    int n;
    printf("请输入n的值：\n");
    scanf("%d",&n);
    int *path = (int *)malloc(sizeof(int)*Maxsize);
    pSepstack S = init();
    push(S,1);
    process(S,n,1,path,0);
    return 0;
}

