#include<stdio.h>
#include<stdlib.h>
typedef struct Node * List;
struct Node{
int data;
List next;
};
List init();
List input(List p,int n);
List _delete(List p,int mink,int maxk);
void print(List p);
int main(void)
{
    List head = init();
    List q = head;
    int mink,maxk;
    int i;
    scanf("%d %d",&mink,&maxk);
    for(i=0;i<10;i++)
    {
        q = input(q,i*i);
    }
    head = _delete(head,mink,maxk);
    print(head);
    return 0;
}
List init()
{
    List L = (List)malloc(sizeof(Node));
    L -> next = NULL;
    return L;
}
List input(List p,int n)
{
    List q = init();
    q -> data = n;
    p -> next = q;
    return q;
}
List _delete(List p,int mink,int maxk)
{
    List q = p;
   while(p->next!=NULL)
  {
    if(p->next->data>mink&&p->next->data<maxk&&p->next!=NULL)
    {
        List q = p->next;
        p->next = q->next;
        free(q);
    }
    else
    {
        p = p->next;
    }
  }
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
}


