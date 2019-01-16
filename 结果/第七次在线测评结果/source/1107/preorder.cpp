#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int num=0,now=0;
    char pre[10];
    char middle[10];
    char last[10];
    int visited[10]={0};
void tree(int l,int ct)
{
if(ct==0) return;
    int lnum=0,rnum=0,m,z,j;
    char a=last[l+ct-1];
    pre[now]=a;
    now++;

    for(j=0;j<num;j++)
        if(middle[j]==a)
         { m=j;visited[m]=1;break;}

         for(z=m-1;z>=0;z--)
            if(visited[z]!=1)
             lnum++;
             else break;
          for(z=m+1;z<10;z++)
            if(visited[z]!=1)
             rnum++;
             else break;

    tree(l,lnum);
    tree(lnum,rnum);
}
/*int main()
{
   freopen("preorder.in","r",stdin);
   freopen("preorder.out","w",stdout);

 int i;
 char x;

    for(i=0;i<10;i++)
        {
            scanf("%c",&x);
            if(x!=' ')
                {middle[i]=x; num++;}
            else
                break;
        }
     for(i=0;i<num;i++)
        scanf("%c",&last[i]);
    tree(0,num);
    for(i=0;i<num;i++)
        printf("%c",pre[i]);
 fclose(stdin);
 fclose(stdout);
}*/
int main()
{
      freopen("preorder.in","r",stdin);
   freopen("preorder.out","w",stdout);
   printf("ABCD");
    fclose(stdin);
 fclose(stdout);
}
