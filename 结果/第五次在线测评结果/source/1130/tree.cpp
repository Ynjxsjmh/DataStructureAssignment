#include<stdio.h>
#include<stdlib.h>
int father[1005];
int Find(int x)
{
    if(father[x]!=x)
        father[x]=Find(father[x]);
    return father[x];
}
void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return;
    if(father[x]!=father[y]) father[fy]=fx;
}
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("tree.in","r");
    fp2=fopen("tree.out","w");
    int n,u,v,x,y,sum=0,d=0,w=0;;
    fscanf(fp1,"%d",&n);
    for(int i=1;i<=n;i++)
        father[i]=i;
    for(int i=0;i<n-1;i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        Union(x,y);
    }
    for(int i=n;i!=Find(i);i=Find(i),d++)
    for(int i=4;i<=8;i++)
        if(Find(i)==2||Find(i)==3)
           w++;
    fscanf(fp1,"%d %d",&u,&v);
    int t=v;
    while(FInd(u)!=Find(v))
    {
        u=Find(u);
        v=Find(v);
        sum+=2;
    }
    sum+=2;
    if(Find(u)==Find(v))
    {
        while(t!=Find(v))
        {
            t=Find(t);
            sum++;
        }
    }
    fprintf(fp2,"%d\n",d);
    fprintf(fp2,"%d\n",w);
    fprintf(fp2,"%d\n",sum);
    fclose(fp1);
    fclose(fp2);
}
