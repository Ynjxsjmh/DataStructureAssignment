#include<iostream>
#include <fstream>
using namespace std;
#include <memory.h>
#define cin fin
#define cout fout
int main()
{
    ifstream fin("lottery.in");
    ofstream fout("lottery.out");
    int b[8];
    memset(b,0,sizeof(b));
    int a[7];int n;
    cin>>n;int x;int ct;
    for(int i=0;i<7;i++)
        cin>>a[i];
        for(int i=0;i<n;i++)
        {ct=0;
        for(int j=0;j<7;j++)
         {
             cin>>x;
            for(int k=0;k<7;k++)
                if(x==a[k])
                {ct++;break;}

        }
         b[ct]++;

        }

       for(int i=7;i>0;i--)
          {
              if(i==1)
                  cout<<b[i]<<endl;
              else
                  cout<<b[i]<<' ';
          }

           return 0;

}
