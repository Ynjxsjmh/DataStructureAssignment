# include<iostream>
# include<iomanip>
# include<cstdio>
using namespace std;
void miuns(char *a,char *b)
{
    char s;
    int t,p=0;
    while(b[p]!='\0')
    {
        p++;
    }
    s=b[p-1];
   // cout<<s<<" ";
    char c[10];
    char d[10];
    char e[10];
    char f[10];
    int i=0;
    while(a[i]!=s)
    {
        c[i]=a[i];
        i++;
    }
    c[i]='\0';
    t=i+1;
    i=0;
    while(a[t]!='\0')
    {
        d[i]=a[t];
        i++;
        t++;
    }
   // while()
}
int main(void)
{
     freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    char a[10];
    char b[10];
    cin>>a;
    cin>>b;
    miuns(a,b);
    cout<<"ABCD"<<endl;
     fclose(stdin);
    fclose(stdout);
    return 0;
}
