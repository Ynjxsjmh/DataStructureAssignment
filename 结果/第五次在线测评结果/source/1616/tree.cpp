#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
const int M = 12345;
int fa[M][20];
int deep[M];
vector<int> G[M];
int ans1=1,ans2=1;
int s[M];
int dfs(int num){
    for(int i=0;i<G[num].size();i++){
        int to=G[num][i];
        if(to==fa[num][0]) continue;
        fa[to][0]=num;
        deep[to]=deep[num]+1;
        s[deep[to]]++;
        ans1=max(ans1,deep[to]);
        ans2=max(ans2,s[deep[to]]);
        dfs(to);
    }
    return 0;
}
int bin[20];
int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    int t=deep[x]-deep[y];
    for(int i=9;i>=0;i--){
        if(t&bin[i]) x=fa[x][i];
    }
    for(int i=9;i>=0;i--){
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    if(x==y) return x;
    else return fa[x][0];
    return 0;
}

int main(){
    bin[0]=1;
    for(int i=1;i<=9;i++) bin[i]=bin[i-1]*2;
    freopen("tree.in","r",stdin);
   freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    deep[1]=1;
    dfs(1);
    for(int j=1;j<=9;j++){
        for(int i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
    /*for(int i=1;i<=n;i++)
        printf("%d ",fa[i][0]);
    printf("\n");
    */int x,y;
    cin>>x>>y;
    printf("%d\n%d\n",ans1,ans2);
    int father=lca(x,y);
    //printf("%d %d %d %d %d %d\n",x,deep[x],y,deep[y],father,deep[father]);
    printf("%d\n",(deep[x]-deep[father])*2+(deep[y]-deep[father]));
    return 0;
}
