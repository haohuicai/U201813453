#include<stdio.h>
#include<stdlib.h>
typedef struct Node *List;
struct Node{
int data;
List next;
};
List init();
List input(List p,int n);
void _delete(List p,List q,List L);
void print(List p);
int main(void)
{
    List L1,L2,L3;
    L1 = init();
    L2 = init();
    L3 = init();
    int i;
    List p=L1;
    List q=L2;
    List L=L3;
    for(i=0;i<5;i++)
    {
        p = input(p,i*2+1);
    }
    for(i=0;i<8;i++)
    {
        q = input(q,i*3-3);
    }
    for(i=0;i<9;i++)
    {
        L = input(L,i+2);
    }
    print(L1);
    print(L2);
    print(L3);
     _delete(L1,L2,L3);
    print(L1);
    return 0;
}
List init()
{
    List L = (List)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}
List input(List p,int n)
{
    List q = init();
    q->data = n;
    p->next = q;
    return q;
}
void print(List p)
{
    List q = p->next;
    while(q!=NULL)
   {
        if(q->next==NULL)
        {
            printf("%d",q->data);
        }
        else
        {
            printf("%d->",q->data);
        }
        q = q->next;
   }
   printf("\n");
}
void _delete(List p,List q,List L)
{
    List pa = p->next;
    List _L = p;
    List pb,pc;

    while(pa!=NULL)
    {
        pb = q->next;
        pc = L->next;
        while(pb!=NULL&&(pb->data)!=(pa->data)) pb = pb->next;
        while(pc!=NULL&&pc->data!=pa->data) pc = pc->next;
        if(pb!=NULL&&pc!=NULL)
        {
            _L->next = pa->next;
            List m = pa;
            pa = pa->next;
            free(m);
        }
        else
        {
            _L = _L->next;
            pa = pa->next;
        }
    }
}
