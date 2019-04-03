#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct{
    char data[Maxsize];
    int top;
}Sepstack,*pSepstack;
int grade(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x== '/')
        return 2;
}
pSepstack init()
{
    pSepstack S = (pSepstack)malloc(sizeof(Sepstack));
    return S;
}
int push(pSepstack S, char x)
{
    if(S->top == (Maxsize-1))
    {
        printf("栈空间已满");
        return 0;
    }
    else
    {
        S->data[++S->top] = x;
        return 1;
    }

}
int pop(pSepstack S, char *y)
{
    if(S->top == -1)
    {
        printf("栈为空");
        return 0;
    }
    else
    {
        *y = S->data[S->top--];
        return 1;
    }
}
void destroy(pSepstack S)
{
    if(S)
    free(S);
    S = NULL;
}
void char_tran(char *x,int n)
{
    int i = 0;
    char y;
    pSepstack S = init();
    S->top = -1;
    while(i<n)
    {
        if(x[i]>='0'&&x[i]<='9')
           {
               printf("%c",x[i]);
               i++;
           }
        else if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/')
        {
            if(S->top==-1)
               {
                   push(S,x[i]);
                   i++;
               }
            else
            {
                if(grade(x[i])>grade(S->data[S->top]))
                    {
                        push(S,x[i]);
                        i++;
                    }
                else
                {
                    pop(S,&y);
                    printf("%c",y);
                }
            }
        }
    };
    while(S->top>-1)
    {
        pop(S,&y);
        printf("%c",y);
    }
    destroy(S);
}
int main(void)
{
    char str[Maxsize];
    int n;
    printf("Input the expression:\n");
    gets(str);
    printf("输入表达式的位数\n");
    scanf("%d",&n);
    char_tran(str,n);
    return 0;
}
