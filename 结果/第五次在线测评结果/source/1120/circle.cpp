#include<iostream>
#include"stdio.h"
#include"math.h"
using namespace std;
struct node{
     int x;
     int y;
     int r;
     int flag;
};
int main(){
    FILE* fp1,*fp2;
    fp1=fopen("circle.in","r");
    fp2=fopen("circle.out","w");
    int no=0,n,x,y,r;
    float t;
    struct node s[70001];
    fscanf(fp1,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(fp1,"%d",&s[i].x);
        fscanf(fp1,"%d",&s[i].y);
        fscanf(fp1,"%d",&s[i].r);
        s[i].flag=i;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=2;j<=n;j++){
                t=sqrt((s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y));
            if(t<=float(s[i].r+s[j].r)&&s[i].flag!=s[j].flag){
                s[j].flag=s[i].flag;
            }
        }

    }
    int no1[7000],flag1;
    for(int i=0;i<7000;i++) no1[i]=0;
    for(int i=1;i<=n;i++){
        flag1=0;
        for(int j=0;j<7000;j++){
            if(no1[j]==s[i].flag){
                flag1=1;
                break;
            }
        }
        if(flag1==1){}
        else {
            no1[no]=s[i].flag;
            no++;
        }

    }
    fprintf(fp2,"%d",no);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
