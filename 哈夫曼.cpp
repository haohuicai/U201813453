#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int weight;
    int parent;
    int Lchild;
    int Rchild;
}HFtree , *pHFtree;
struct word
{
    char ch;
    char code[20];
    int codelength;
};
void select(int *s1, int *s2, pHFtree Hf, int n)
{
    int _min = 9999;
    int i,L1=0,L2=0;
    for(i=0;i<n;i++)
    {
        if(Hf[i].weight<_min&&Hf[i].parent==0)
           {
            _min = Hf[i].weight;
            L1 = i;
           }
    }
    *s1 = L1;
    _min = 9999;
    for(i=0;i<n;i++)
    {
        if(Hf[i].weight<_min&&(i!=*s1)&&Hf[i].parent==0)
           {
               _min = Hf[i].weight;
               L2 = i;
           }
    }
    *s2 = L2;
}
void createHftree(pHFtree Hf, int *w, int n)
{
    int i;
    int s1,s2;
    int m = 2*n - 1;
    for(i=0;i<n;i++)
    {
        Hf[i].weight = w[i];
        Hf[i].parent = 0;
        Hf[i].Lchild = 0;
        Hf[i].Rchild = 0;
    }
    for(i=n;i<m;i++)
    {
        Hf[i].weight = 0;
        Hf[i].parent = 0;
        Hf[i].Lchild = 0;
        Hf[i].Rchild = 0;
    }
    for(i=n;i<m;i++)
    {
        select(&s1,&s2,Hf,i-1);
        Hf[i].weight = Hf[s1].weight+Hf[s2].weight;
        Hf[s1].parent = i;
        Hf[s2].parent = i;
        Hf[i].Lchild = s1;
        Hf[i].Rchild = s2;
    }
    for(i=0;i<m;i++)
    {
        printf("%d %d %d %d\n",Hf[i].weight,Hf[i].parent,Hf[i].Lchild,Hf[i].Rchild);
    }
}
void showHfcode(pHFtree Hf,int n,struct word * pa)
{
    int start;
    int i,j,k,t;
    for(i=0;i<n;i++)
    {
        start = 19;
        k = i;
        t = Hf[k].parent;
        while(t!=0)
        {
           if(Hf[t].Lchild == k)
                pa[i].code[start--] = '0';
           else
                pa[i].code[start--] = '1';
           k = t;
           t = Hf[t].parent;
        }
        pa[i].codelength = 19-start;
    }
    for(i=0;i<n;i++)
    {
        printf("%c",pa[i].ch);
        for(j=20-pa[i].codelength;j<20;j++)
        printf("%c",pa[i].code[j]);
        printf("\n");
    }
}
void Decoding(char c,int n,struct word*pa)
{
    int j;
    for(int i=0;i<n;i++)
    {
        if(c ==pa[i].ch)
         {
             for(int j=20-pa[i].codelength;j<20;j++)
                  printf("%c",pa[i].code[j]);
         }
    }
}
int main(void)
{
    int n=27;
    char str[20];
    struct word * pa = (struct word *)malloc(n*sizeof(word));
    int m = 2*n-1;
    pHFtree Hf = (pHFtree)malloc(m*sizeof(HFtree));
    int *w = (int*)malloc(n*sizeof(int));
    pa[0].ch = ' ',w[0] = 186;
    pa[1].ch = 'A',w[1] = 64;
    pa[2].ch = 'B',w[2] = 13;
    pa[3].ch = 'C',w[3] = 22;
    pa[4].ch = 'D',w[4] = 32;
    pa[5].ch = 'E',w[5] = 103;
    pa[6].ch = 'F',w[6] = 21;
    pa[7].ch = 'G',w[7] = 15;
    pa[8].ch = 'H',w[8] = 47;
    pa[9].ch = 'I',w[9] = 57;
    pa[10].ch = 'J',w[10] = 1;
    pa[11].ch = 'K',w[11] = 5;
    pa[12].ch = 'L',w[12] = 32;
    pa[13].ch = 'M',w[13] = 20;
    pa[14].ch = 'N',w[14] = 57;
    pa[15].ch = 'O',w[15] = 63;
    pa[16].ch = 'P',w[16] = 15;
    pa[17].ch = 'Q',w[17] = 1;
    pa[18].ch = 'R',w[18] = 48;
    pa[19].ch = 'S',w[19] = 51;
    pa[20].ch = 'T',w[20] = 80;
    pa[21].ch = 'U',w[21] = 23;
    pa[22].ch = 'V',w[22] = 8;
    pa[23].ch = 'W',w[23] = 18;
    pa[24].ch = 'X',w[24] = 1;
    pa[25].ch = 'Y',w[25] = 16;
    pa[26].ch = 'Z',w[26] = 1;
    createHftree(Hf,w,n);
    showHfcode(Hf,n,pa);
    printf("Input the sentence:\n");
    scanf("%s",str);
    int N = strlen(str);
    for(int i=0;i<N;i++)
    {
        Decoding(str[i],n,pa);
    }
}






