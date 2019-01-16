//
//  main.cpp
//  数的统计
//
//  Created by Rachel on 2017/5/23.
//  Copyright © 2017年 Rachel. All rights reserved.
//

#include <iostream>
#include <fstream>

#define cin fin
#define cout fout
using namespace std;
ifstream fin("count.in");
ofstream fout("count.out");

#define M 50000
#define Max 2000000001

class Article{
private:
    int size;
    int *data;
    int *weight;
public:
    Article(){
        data =new int[M];
        weight =new int[M];
    }
    ~Article(){
        delete[] data;
        delete[] weight;
    }
    void Read();
    void QSort(int*,int,int);
    int Getsize(){return size;}
    int * GetData(){return data;}
    int Getdata(int i){return data[i];}
    int Getweight(int i){return weight[i];}
    void Out(){
        for(int i=0;i<size;i++) cout<<data[i]<<weight[i]<<endl;
    }
};

void Article::Read(){//完成读入与按权排序
    int Size,i,flag,Input;
    cin>>Size>>Input;
    data[0]=Input;
    weight[0]=1;
    size=1;
    Size--;
    while(Size>0){
        flag=0;
        cin>>Input;
        for(i=0;i<size;i++) if(data[i]==Input){flag=1;weight[i]++;break;}
        if(flag==0){
                size++;
                data[size-1]=Input;
                weight[size-1]=1;
        }
        Size--;
    }//读入size，data，weight
    data[size]=Max;
    weight[size]=1;
}

void Article::QSort(int * data, int m, int n){
    if(m<n){
        int key = data [m];
        int key1= weight[m];
        int low = m;
        int high = n;
        while(low < high){
            while(low<high && data[high]>key) high--;
            data[low]=data[high];
            weight[low]=weight[high];
            while(low<high && data[low]<key) low++;
            data[high]=data[low];
            weight[high]=weight[low];
        }
        data[low]=key;
        weight[low]=key1;
        QSort(data,m,low-1);
        QSort(data,low+1,n);
    }
}

int main() {
    Article a;
    a.Read();
    a.QSort(a.GetData(), 0, a.Getsize());
    a.Out();
    return 0;
}
