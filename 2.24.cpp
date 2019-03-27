//重排两个表并合并
#include<stdio.h>
#include<stdlib.h>
typedef struct Node * List;
struct Node{
int data;
List next;
};
List init();
List input(List p,int n);
void print(List p);
List _union(List p,List q);
List reverse(List p);
List init()
{
    List L = (List)malloc(sizeof(Node));
    L -> next = NULL;
    return L;
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
   }printf("\n");
}
List input(List p,int n)
{
    List q = init();
    q -> data = n;
    p -> next = q;
    return q;
}
List reverse(List p)
{
    List q = p->next->next;
    List L = p;
    p = p->next;
    p->next = NULL;
    free(L);
    while(q!=NULL)
    {
        List pa = q->next;
        q->next = p;
        p = q;
        q = pa;
    }
    List m = init();
    m -> next = p;
    return m;

}
List _union(List p,List q)
{
  List pa = p->next;
  List pb = q->next;
  List pc;
  List m;
  List pre = NULL;
  while(pb!=NULL&&pa!=NULL)
  {
      if(pa->data<=pb->data)
      {
          pc = pa;
          m = pa->next;
          pa->next = pre;
          pa = m;
      }
      else if(pa->data>pb->data)
      {
          pc = pb;
          m  = pb->next;
          pb->next = pre;
          pb = m;
      }
      pre = pc;
  }
        if(pa)
         {
             pb = pa;
         }
        m = pb;
        List k = init();
        k->next = pb;
        List pm = reverse(k);
        m->next = pre;
        free(q);
        free(p);
        return pm;
}
int main(void)
{
    int i;
    List L = init();
    List _L = init();
    List m;
    List p = L;
    List q = _L;
    for(i=0;i<5;i++)
    {
        p = input(p,i*i);
    }
    for(i=0;i<9;i++)
    {
        q = input(q,2*i);
    }
    m = _union(_L,L);
    print(m);
    return 0;
}
