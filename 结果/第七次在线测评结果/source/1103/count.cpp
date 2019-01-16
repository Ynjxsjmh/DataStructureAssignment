#include <fstream>
#include<iostream>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("count.in");
ofstream fout("count.out");
class Element
{
public:
    int GetKey()const{return key;}
    void SetKey(int k){key=k;}
private:
    int key;
    //int Count;
};
void Interchange(Element *tree,int j,int m)
{
    int a=tree[j].GetKey();
    int b=tree[m].GetKey();
    tree[j].SetKey(b);
    tree[m].SetKey(a);//??
}
void Restore(Element *tree,const int root,const int n)
{
    int m;
    int j=root;
    while(j<=(int)(n/2))
    {
        if((2*j<n)&&(tree[2*j].GetKey()<tree[2*j+1].GetKey())) m=2*j+1;
        else m=2*j;
        if(tree[j].GetKey()<tree[m].GetKey())
        {
            Interchange(tree,j,m);//交换tree中下标为j和m的两个记录
            j=m;
        }
        else j=n;
    }
}
void HeapSort(Element *R,const int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        Restore(R,i,n);
    for(i=n;i>1;i--)
    {
        Interchange(R,1,i);
        Restore(R,1,i-1);
    }
}
int main(void)
{
    int n;
    cin>>n;
    int k,Count=0;
    int* a=new int[n];
    Element *p=new Element[n+1];
    p[0].SetKey(500);
    for(int i=1;i<n+1;i++)
    {
        cin>>k;
        p[i].SetKey(k);
    }
    HeapSort(p,10);
    for(int i=1;i<n+1;i++)
        a[i-1]=p[i].GetKey();
    k=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]==k) Count++;
        else
        {
            cout<<k<<" "<<Count<<endl;
            k=a[i];
            Count=1;
        }
    }
    cout<<k<<" "<<Count<<endl;
}
