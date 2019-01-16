#include<stdio.h>
#include<stdlib.h>
#define N 1000
int m[1000][1000];
int n;
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,-1,1,1,-1};
void change(int x,int y,int r)
{
    m[x][y]=1;
    for(int i=-r;i<=r;i++)
        for(int j=-r;j<=r;j++)
            if(x+i>=0&&x+i<N&&y+j>=0&&y+j<N&&i*i+j*j<=r*r)
            m[i+x][j+y]=1;
}
void dfs(int a,int b)
{
    if(a<0||b>=N||a<0||b>=N) return;
    m[a][b]=0;
    for(int i=0;i<8;i++)
    {
        int x=a+dx[i],y=b+dy[i];
        if(m[x][y]==1)
            dfs(x,y);
    }
}
int main()
{
    int x,y,r,sum=0;
    FILE *fp1,*fp2;
    fp1=fopen("circle.in","r");
    fp2=fopen("circle.out","w");
    fscanf(fp1,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&r);
        change(x,y,r);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        if(m[i][j]==1)
        {
            sum++;
            dfs(i,j);
        }
    fprintf(fp2,"%d\n",sum);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
