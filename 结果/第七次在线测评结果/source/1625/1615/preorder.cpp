#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int nmax=20;
int len=1;
char post[nmax],in[nmax];
char a[nmax];
int lef[20],righ[20];
int build(int l1,int r1,int l2,int r2)
{
	if(r2-l2<0) return -1;
	if(r1-l1<0) return -1;
	int root=post[r2];
	a[len]=root;  len++;
	int p=l1;
	while(in[p]!=root) p++;
	int cnt=p-l1;
	int t=len-1;
	lef[t]=build(l1,p-1,l2,l2+cnt-1);
	righ[t]=build(p+1,r1,l2+cnt,r2-1);
	return t;
}
void coutpreorder(int i)
{
	printf("%c",a[i]);
	if(lef[i]!=-1) coutpreorder(lef[i]);
	if(righ[i]!=-1) coutpreorder(righ[i]);
}
int main()
{
	freopen("preorder.in","r",stdin);
	freopen("preorder.out","w",stdout);
	while(~scanf("%s%s",in,post))
	{
	    len=0;
		memset(lef,-1,sizeof lef);
		memset(righ,-1,sizeof righ);
		for(int i=0; i<nmax; i++)
			a[i]='a';
		int n=strlen(in);
		int root=build(0,n-1,0,n-1);
		coutpreorder(1);
		cout<<endl;
	}
	return 0;
}
