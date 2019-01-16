#include<cstdio>
#include<iostream>
using namespace std;
int result[7]={0};
int award[7]={0};
void save(int i){
    i=7-i;
    result[i]++;
}
void pr(){
    for(int i=0;i<7;i++)
        printf("%d ",result[i]);
    }
int main(){
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<7;i++)
        scanf("%d",&award[i]);
    for(int i=0;i<n;i++){
        int temp[7],counts=0;
        for(int i=0;i<7;i++)
            scanf("%d",&temp[i]);
        for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(temp[i]==award[j])
                counts++;
            }
        }
        save(counts);
    }
    pr();
    fclose(stdin);
    fclose(stdout);
}
