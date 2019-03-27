#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node* List;
struct Node{
int data;
int number;
List next;
int * Joseph(List p,int *a,int n);
};
List init()
{
    List L =(List)malloc(sizeof(Node));
    if(L==NULL)
    {
        printf("ÄÚ´æ²»×ã");
    }
    L->next = NULL;
    return L;
}
int *Joseph(List p,int *a,int n)
{
    List head,_L,t,q;
    head  = p;
    int k,m;
    int i;
   printf("Input the m\n");
   scanf("%d",&m);
   i = 0;
   while(head->next!=head)
   {

        for(k=0;k<m-1;k++)
        head = head->next;
       a[i]=head->number;
        m = head->data;
       t = head;
        while(t->next!=head) t = t->next;
        t->next = t->next->next;
        head = t->next;
        i++;

   }
  a[n-1] = head->number;
  return a;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    if(n>20||n<0)
    {
        printf("Input error");
        return 0;
    }
    int i,j,k,m;
    j = n;
    int *a = (int*)malloc(n*sizeof(int));
   List p,head,L,_L;
   p = init();
   head = p;
   for(i=2;i<=n;i++)
   {
       L = init();
       L->number = i;
       scanf("%d",&L->data);
       if(L->data<0)
        printf("error");
       p->next = L;
       p = L;
   }
    p->next = head;
   head->number = 1;
   printf("Input the first data\n");
   scanf("%d",&head->data);
  a = Joseph(head,a,n);
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }

}
