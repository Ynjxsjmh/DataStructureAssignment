# include<iostream>
# include<iomanip>
# include<cstdio>
using namespace std;
int main(void)
{//cout<<"haha"<<endl;
     freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,c,d,i,m,o,p,j,maxed=0;
    int a[100][100]={0};
    int b[100][100]={0};
    for(i=0;i<100;i++)
       {

       for(j=0;j<100;j++)
        b[i][j]=2;}

    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        cin>>c>>d;
        a[c][d]=1;
    }
    cin>>c;
    cin>>d;
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                o=i;p=j;
                a[o][p]=1;
                while(a[o][p]==1)
                {
                  // b[o][p]++;
                   for(m=1;m<=n;m++)
                   {
                       if(a[m][o]==1)
                        b[m][o]=b[o][p]+1;
                   }
                   p=o;o=m;

                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(b[i][j]>maxed)
                maxed=b[i][j]+1;
        }
    }
    cout<<maxed<<endl;
      fclose(stdin);
    fclose(stdout);
    return 0;
}
