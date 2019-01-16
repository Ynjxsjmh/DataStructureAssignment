#include <fstream>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("preorder.in.txt");
ofstream fout("preorder.out.txt");
//char a[10],b[10];
int main(void)
{
    int a=0;
    char k,j,i;
    cin>>k;
    stack<char> s,t,q,r;
    queue<char> m;
    while(k!='\0')
    {
        t.push(k);
        cin>>k;
    }
    cin>>k;
    while(k!='\0')
    {
        s.push(k);
        cin>>k;
    }
    while(!s.empty())
    {
        i=s.top();
        m.push(i);
        while(t.top()!=i)
        {
            q.push(t.top());
            t.pop();
            s.pop();
        }
        m.push(s.top());
        s.pop();
    }
    while(!m.empty())
    {
        cout<<m.top();
        m.pop();
    }
}
