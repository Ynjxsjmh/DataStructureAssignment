# include<iostream>
# include<cstdio>
# include<iomanip>
# include<queue>
using namespace std;
int a[100001];
bool b[100001]={false};
int sear(int, int);
int main(void)
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    int s,n,k;

    cin>>n>>k;
    if(n<k){
    s=sear(n,k);
    cout<<s<<endl;}
    if(n==k)
    {
    	cout<<"0"<<endl;
	}
	if(n>k)
	{
		cout<<(n-k)<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
int sear(int n,int k)
{
    int i;
    int pre,tail;
    queue<int> s;
    a[n]=0;
    b[n]=1;
    s.push(n);
    while(!s.empty())
    {
        pre=s.front();
        s.pop();
        for(i=0;i<3;i++)
        {
            if(i==0)
            {
                tail=pre+1;
            }
            if(i==1)
            {
                tail=pre-1;
            }
            if(i==2)
            {
                tail=pre*2;
            }
             if(tail<=0||tail>=100001)
            {
               continue;
            }
              if(!b[tail])
            {
                s.push(tail);
                a[tail]=a[pre]+1;
                b[tail]=true;
            }
            if(tail==k)
            {
                return a[tail];
            }
        }

    }
}
