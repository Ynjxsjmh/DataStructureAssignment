#include <fstream>
using namespace std;

ifstream fin("Tree.In");
ofstream fout("Tree.out");

struct a
{
	int x,y;
}b[101];

int n,u,v,x=1,m=1,ans1=0,ans2=0,ans3=0;
int wide[100];
bool f[101];

struct Tree
{
	int f,l,r,deep;
}tree[101];

void findc(int m,int deep)
{
	int i;
	tree[m].deep=deep;
    for (i=1;i<=n;i++)
    {
    	if (f[i]) continue;
    	if (b[i].x==m)
    	{
    		if (tree[b[i].x].l==0)
    		{
    		  tree[b[i].x].l=b[i].y;
    		  tree[b[i].y].f=b[i].x;
    		}
   		    else 
		    {
			   tree[b[i].x].r=b[i].y;
			   tree[b[i].y].f=b[i].x;
		    }
   		    f[i]=true;
   		    wide[deep]++;
   		    findc(b[i].y,deep+1);
    	}
    	if (b[i].y==m)
    	{
    		if (tree[b[i].y].l==0)
    		{
    		  tree[b[i].y].l=b[i].x;
    		  tree[b[i].x].f=b[i].y;
    		}
   		    else 
		    {
			tree[b[i].y].r=b[i].x;
		    tree[b[i].x].f=b[i].y;
		    }
   		    f[i]=true;
   		    wide[deep]++;
   		    findc(b[i].x,deep+1);
    	}
    }
    if (deep>ans1) ans1=deep;
}

int main()
{
	int i;
	memset(f,false,sizeof(f));
	memset(wide,0,sizeof(wide));
	for (i=1;i<=100;i++)
	   tree[i].l=tree[i].r=0;
    fin>>n;
	for (i=1;i<n;i++)
    {
    	fin>>b[x].x>>b[x].y;
    	x++;
    }
    x--;
    tree[1].f=0;
    tree[1].deep=1;
    findc(1,1);
    fout<<ans1<<endl;
    for (i=1;i<=ans1;i++)
      if (wide[i]>ans2) ans2=wide[i];
    fout<<ans2<<endl;
    memset(f,false,sizeof(f));
    fin>>u>>v;
    int m=u;
    f[m]=true;
    while (m!=1)
    {
    	f[tree[m].f]=true;
    	m=tree[m].f;
    }
    m=v;
    while (!f[m])
      m=tree[m].f;
    ans3=(tree[u].deep-tree[m].deep)*2+tree[v].deep-tree[m].deep;
    fout<<ans3<<endl;
	return 0;
}
