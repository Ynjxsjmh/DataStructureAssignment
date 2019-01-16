#include<iostream>
#include<cstdio>
using namespace std;
int x[100],y[100],n;
int len(int temp){
    int i,num=0;
    while(temp!=1){
        for(i=0;i<n-1;i++)
            if(y[i]==temp){
                temp=x[i];
                num++;
            }
    }
    return num;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int i,taru,tarv,num,temp,length,depth;
    int leng[100]={0};
    num=0;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x[i];
        cin>>y[i];
    }
    cin>>taru;cin>>tarv;
    num=len(taru)*2+len(tarv);
    depth=len(y[n-2])+1;
    for(i=0;i<n-1;i++)
        leng[len(y[i])]++;
    length=leng[1];
    for(i=1;i<=n-i;i++)
    {
        if(leng[i]>length)
        length=leng[i];
    }
    cout<<depth<<endl;
    cout<<length<<endl;
    cout<<num<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
