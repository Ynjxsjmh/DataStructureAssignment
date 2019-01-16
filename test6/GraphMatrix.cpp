#include <stack>
#include <queue>
#include <cstring>
#include <limits.h>
#include <iostream>
using namespace std;

void menu();

class GraphMatrix{
	private:
		int edge[100][100];
		int graphsize;                        //顶点数目 
		int vis[10005];
		void dfs(int v);
	
	public:
		GraphMatrix();
//		virtual ~GraphMatrix();
		
		void show();
		
//		int NumberOfEdges(void ) const;
		void FindValue();
		void DFS();
		void BFS(int v);
		void GetFirstNeighbor();
		void floyd();  //任意两顶点之间的最短路 
};


GraphMatrix::GraphMatrix()
{
	printf("****创建图****\n");
	int edge_num=0;
	cout<<"请输入顶点数以及边数:";
	cin>>graphsize>>edge_num;
	
	for(int i=1;i<=graphsize;i++)
		for(int j=1;j<=graphsize;j++)
			edge[i][j]=99999999;
			
	for(int i=1;i<=graphsize;i++)
		edge[i][i]=0;
	
	for(int i=1;i<=edge_num;i++)
	{
		int node1,node2,value;
		printf("请输入两个顶点，及其间的边的权值:");
		cin>>node1>>node2>>value;
		
		edge[node1][node2]=value;
		edge[node2][node1]=value;
	}
}

void GraphMatrix::dfs(int v)
{
	cout<<v;
	vis[v]=1;
	for(int k=1;k<=graphsize;k++)
	{
		if(edge[v][k]!=0&&edge[v][k]!=99999999&&vis[k]==0)
			dfs(k);
	}
}

void GraphMatrix::DFS()
{
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=graphsize;i++)
	{
		if(vis[i]==0)
			dfs(i);
	}
}

void GraphMatrix::BFS(int v)
{
	int k;
	queue <int> q;	
	memset(vis,0,sizeof(vis));
	
	cout<<v;
	q.push(v);
	vis[v]=1;
	
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		
		for(int i=1;i<=graphsize;i++)
		{
			if(edge[k][i]!=0&&edge[k][i]!=99999999&&vis[i]==0)
			{
				cout<<i;
				vis[i]=1;
				q.push(i);
			}
		}
	}
}

void GraphMatrix::FindValue()
{
	int node1,node2;
	printf("请输入你要查询的两个顶点:");
	scanf("%d%d",&node1,&node2);
	
	if(node1<1||node1>graphsize||node2<1||node2>graphsize)
	{
		printf("输入的顶点超出数据域范围.");
	}
	else if(edge[node1][node2]==0)
		printf("您输入的两个顶点为同一顶点，其边的权值为0");
	else if(edge[node1][node2]==99999999)
		printf("这%d,%d两个点之间不直接连通",node1,node2);
	else
		printf("这%d,%d两个点之间的边的权值为%d",node1,node2,edge[node1][node2]);
}

void GraphMatrix::GetFirstNeighbor()
{
	int v; 
	printf("请输入顶点:");
	scanf("%d",&v);
	
	while(v<1||v>graphsize)
	{
		printf("您输入的顶点序号不在数据域中，请重新输入:");
		scanf("%d",&v);
	}
	
	for(int i=1;i<=graphsize;i++)
	{
		if(edge[v][i]!=0&&edge[v][i]!=99999999)
		{
			printf("%d的第一个邻接顶点是:%d",v,i);
			return ;
		}
	}
	
	printf("%d没有邻接顶点.",v);
}

void GraphMatrix::show()
{
	printf("  ");
	for(int i=1;i<=graphsize;i++)
		printf("%4d ",i);
	printf("\n");	
	
	for(int i=1;i<=graphsize;i++)
	{
		printf("%-4d ",i);
		for(int j=1;j<=graphsize;j++)
		{
			if(edge[i][j]==99999999)
				printf("∞   ");
			else	
				printf("%-4d ",edge[i][j]);
		}
		printf("\n");
	}
}

void GraphMatrix::floyd()
{
	int a[100][100];
	int path[100][100];
	
	for(int i=1;i<=graphsize;i++)
		for(int j=1;j<=graphsize;j++)
		{
			a[i][j]=edge[i][j];
			if(i!=j&&a[i][j]!=99999999)
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
	
	for(int k=1;k<=graphsize;k++)
		for(int i=1;i<=graphsize;i++)
			for(int j=1;j<=graphsize;j++)
				if(a[i][k]+a[k][j]<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
					path[i][j]=path[k][j];
				}
	
	printf("  ");
	for(int i=1;i<=graphsize;i++)
		printf("%4d ",i);
	printf("\n");	
	
	for(int i=1;i<=graphsize;i++)
	{
		printf("%-4d ",i);
		for(int j=1;j<=graphsize;j++)
		{
			if(a[i][j]==99999999)
				printf("∞   ");
			else	
				printf("%-4d ",a[i][j]);
		}
		printf("\n");
	}
	
	cout<<endl;
	printf("  ");
	for(int i=1;i<=graphsize;i++)
		printf("%4d ",i);
	printf("\n");	
	
	for(int i=1;i<=graphsize;i++)
	{
		printf("%-4d ",i);
		for(int j=1;j<=graphsize;j++)
		{
			if(path[i][j]==99999999)
				printf("∞   ");
			else
				printf("%-4d ",path[i][j]);
		}
		printf("\n");
	}
		
	int node1,node2;
	int how[100];
	int m;
	m=0;
	memset(how,-1,sizeof(how));
	printf("请输入您要查找的两个顶点:");
	scanf("%d%d",&node1,&node2);
	printf("%d和%d之间的最短距离是:%d",node1,node2,a[node1][node2]);
	how[0]=node2;
	while(how[m]!=node1)
	{
		int pre=how[m];
		how[++m]=path[node1][pre];
	}
	
	cout<<endl<<"经过的路径为:";
	while(m>=0)
	{
		cout<<how[m]<<" ";
		m--;
	}
}

int main()
{
	GraphMatrix graph;
	int choice;
	
	graph.show();
	
	menu();
	scanf("%d",&choice);
	
	while(choice<0&&choice>5)
	{
		printf("输入数据错误,请重新输入:");
		scanf("%d",&choice);
	}
	
	while(choice!=0)
	{
		switch(choice)
		{
			case 1: graph.FindValue();break;
			case 2: graph.GetFirstNeighbor(); break; 
			case 3: graph.DFS(); break;
			case 4: graph.BFS(1); break;
			case 5: graph.floyd(); break;
		}
		
		menu();
		scanf("%d",&choice);
		while(choice<0&&choice>5)
		{
			printf("输入数据错误,请重新输入:");
			scanf("%d",&choice);
		}
	}
}


void menu()
{
	printf("\n=========================================\n");
	printf("1.返回图中指定边的权值\n");
	printf("2.查找图中某顶点的第一个邻接顶点\n");
	printf("3.深度优先遍历\n");
	printf("4.广度优先遍历\n");
	printf("5.任意顶点间的最短路径和最短路径长度\n");
	printf("0.退出\n");
	printf("===========================================\n");
	printf("请输入您的选择:");
}
