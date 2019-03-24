//¾ÍµØÄæÖÃ
#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000
typedef struct Seplist* List;
struct Seplist
{
    int data[maxsize];
    int last;
};
List create_list();
void input(List p,int n);
List inverse(List p);
void print(List p);
int main(void)
{
    int i;
    List L = create_list();
    L->last = -1;
    for(i=0;i<10;i++)
   {
    input(L,i*i);
   }
   print(L);
    L = inverse(L);
    print(L);
}
List create_list()
{
    List L = (List)malloc(sizeof(Seplist));
    return L;
}
void input(List p,int n)
{
    int q = p->last+1;
    p->data[q] = n;
    ++p->last;
}
List inverse(List p)
{
    int i = 0;
    int j = p->last;
    while(j-i>0)
    {
        int temp;
        temp = p->data[i];
        p->data[i] = p->data[j];
        p->data[j] = temp;
        i++;
        j--;
    }
    return p;
}
void print(List p)
{
    int j = p->last;
    int i;
    for(i=0;i<=j;i++)
    {
        printf("%d ",p->data[i]);
    }
    printf("\n");
}
