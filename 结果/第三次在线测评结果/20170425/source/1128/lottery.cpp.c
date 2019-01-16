#include <stdio.h>
#include <stdlib.h>
int main(){
freopen("lottery.in","r",stdin);
freopen("lottery.out","w",stdout);
int n,i,j,k,p,q,f,num;
int in[7];
int st[8];
int award[8]={0,0,0,0,0,0,0,0};
scanf("%d",&n);
for(i=0;i<7;i++)
    scanf("%d",&in[i]);
for(j=0;j<7;j++)
{   f=0;
    for(k=0;k<7;k++)
        if(in[j]>in[k])
        f++;
    switch (f)
    {case 0:st[4]=in[j];break;
     case 1:st[2]=in[j];break;
     case 2:st[5]=in[j];break;
     case 3:st[1]=in[j];break;
     case 4:st[6]=in[j];break;
     case 5:st[3]=in[j];break;
     case 6:st[7]=in[j];break;
    };
}///奖池
/// /////////////////////////
for(k=0;k<n;k++)
{       ///读入彩票部分
        num=7;
    for(j=0;j<7;j++)///内联了search
        {scanf("%d",&p);
        i=1;
        f=0;
        while(i<=7)
            {
    if(p<st[i])///左边
        i=i<<1;
    else if(st[i]==p)
        {f=1;
        break;}
    else
        i=(i<<1)+1;
            }
        num=num-f;
        }
    award[num]++;
}
/// ////////////////
for(j=0;j<7;j++)///输出结果部分
    printf("%d ",award[j]);
/// //////////////
return 0;
}





















/*int search(int n)
{
    int st[8]={0,8,4,12,2,6,10,14};
    int i=1;
    while(i<=7){
    if(n<st[i])///左边
        i=i<<1;
    else if(st[i]==n)
        return 1;
    else
        i=(i<<1)+1;
    }
    return 0;
}

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
//qsort(st,8,sizeof(int),cmp);////////////////////////////////////////
*/
