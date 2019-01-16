# include<iostream>
# include<iomanip>
# include<cstdio>
using namespace std;
int main(void)
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n,i,flag,t,swaps;
    long int a[50001];
    int s[50001];
   long int b[50001];
    cin>>n;
    for(i=0;i<n;i++)
    {
        s[i]=1;
    }

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    flag=n;
    while(flag>0)
    {//cout<<"hah\n";
        t=0;
        for(i=0;i<n-1;i++)
            if(a[i]>a[i+1])
        {
            swaps=a[i];
            a[i]=a[i+1];
            a[i+1]=swaps;
            t=i;
        }
        flag=t;
    }
    int m=0;
   // int k=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
        {
           // if(a[i]!=a[i-1])
               b[m]=a[i];

        }
        //if(a[n-1]!=a[n])
        while(a[i]==a[i+1])
        {
            s[m]++;
            b[m]=a[i];
            i++;
           // k++;
        }
        m++;
    }
    if(a[n-2]!=a[n-1])
    {
        b[m]=a[n-1];
        m++;
    }
    for(i=0;i<m;i++)
    {
        cout<<b[i]<<" ";
        cout<<s[i];
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
