#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node* List;
struct Node{
int data;
int number;
List next;
};
List init()
{
    List L =(List)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int i,j,t,k,m;
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
       p->next = L;
       p = L;
   }
   p->next = head;
   head->number = 1;
   printf("Input the first data\n");
   scanf("%d",&head->data);
   printf("Input the m\n");
   scanf("%d",&m);
   i = 0;
   while(head->next!=head)
   {
       for(k=0;k<abs(m-2);k++)
        head = head->next;
       a[i]=head->next->number;
        m = head->next->data;
        _L = head->next;
        head->next = head->next->next;
        head = head->next;
        i++;
        free(_L);
   }
  a[n-1] = head->number;
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }

}
