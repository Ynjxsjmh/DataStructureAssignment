#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct circle{
    int x;
    int y;
    int r;
};
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n,now;
    int num=0;
    circle c[7000];
    queue<int> q;
    int sign[7000]={0};
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>c[i].x;
            cin>>c[i].y;
            cin>>c[i].r;
        }
    for(int i=0;i<n;i++){
        if(sign[i]==0){q.push(i);sign[i]=1;num++;}
        while(!q.empty()){
            now=q.front();
            q.pop();
            for(int j=0;j<n;j++)
                {
                  if(sign[j]==1)
                        continue;
                  if((c[i].r+c[j].r)*(c[i].r+c[j].r)>=((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y)))
                  {
                      q.push(j);
                      sign[j]=1;
                  }
                }
            }

    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
