#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int a[50000],n,i,j,temp,num,flag;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
        for(i=n-1;i>=0;i--){
                flag=i;
            for(j=0;j<i;j++)
            if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            flag=j+1;
            }
            i=flag;
        }
        for(i=0;i<n;i++){
            temp=a[i];
            num=1;
            while((i<n)&&(a[i+1]==temp)){i++;num++;}
            cout<<temp<<" "<<num<<endl;
        }
        fclose(stdin);
        fclose(stdout);
    return 0;
}
