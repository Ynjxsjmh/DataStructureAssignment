#include <iostream>
#include <stdio.h>
#define non -200000
using namespace std;
struct node
{
    int father;
    int lever;
    node()
    {father=non;
    lever=non;}
};
    node T[101];
int path(int i)
{
    int num=0;
    while(i!=1)
    {
        i=T[i].father;
        num++;
    }
    return num;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int num,a,b,c;
    cin>>num;
    T[1].father=0;
    T[1].lever=1;
    for(int i=1;i<num;i++)
    {
        scanf("%d %d",&a,&b);
        T[b].father=a;
        T[b].lever=T[a].lever+1;
    }
    int x=0,y,z;
    for(int i=1;i<101;i++)
        if(T[i].lever>x)
        x=T[i].lever;
    cout<<x<<endl;
    int lv[101]={0};
    for(x=1;x<101;x++)
        if(T[x].father>=0)
        lv[T[x].lever]++;
    x=0;
    for(int i=1;i<101;i++)
        if(lv[i]>x)
        x=i+1;
    cout<<x<<endl;
    scanf("%d %d",&y,&z);
    cout<<path(z)+2*path(y)<<endl;
}
