#include<iostream>
#include"stdlib.h"
#include"stdio.h"
using namespace std;

int part(long long* a,int l,int h){
long long x=a[l];   //
int i=l;
int j=h+1;
long long t;    //
while(i<j){
    while(a[++i]<x&&i<j);
    while(a[--j]>x);
    if(i<j){
        t=a[j];
        a[i]=a[j];
        a[j]=t;
    }
}
a[l]=a[j];
a[j]=x;
return j;
}

void qsort(long long *a,int l,int h){
if(l>h) return;
int s[50001];
int p=0;
s[p++]=l;
s[p++]=h;
int low,high,q;
while(p>0){
    high=s[--p];
    low=s[--p];
    if(low>=high) break;
    q=part(a,low,high);
    if(q-low>high-p){
        s[p++]=low;
        s[p++]=q-1;
        if(high>q){
            s[p++]=q+1;
            s[p++]=high;
        }
        }else{
            s[p++]=q+1;
            s[p++]=high;
            if(q>low){
                s[p++]=low;
                s[p++]=q-1;
            }
    }
}
}

void bubble(long long *a,int n){
    int t;
    for(int i=n-1;i>=2;i--){
        for(int j=0;j<=i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int main(){
    FILE*fp1,*fp2;
    fp1=fopen("count.in","r");
    fp2=fopen("count.out","w");
    long long x[50001],tar;  //
    int n,no,j;
    fscanf(fp1,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp1,"%d",&x[i]);
    }

    /*qsort(x,0,n-1);
    for(int i=0;i<n;i++){
        cout<<x[i];
    }*/

    bubble(x,n);
    for(int i=0;i<n;i++){
        cout<<x[i];
    }
    x[n]=-1;
    tar=x[0];
    no=0;
    for(int i=0;i<=n;i++){
        if(x[i]==tar){
            no++;
        }
        else{
            fprintf(fp2,"%d ",tar);
            fprintf(fp2,"%d\n",no);
            no=1;
            tar=x[i];
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}














