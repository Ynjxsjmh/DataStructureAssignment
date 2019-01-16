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
		int graphsize;                        //������Ŀ 
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
		void floyd();  //����������֮������· 
};


GraphMatrix::GraphMatrix()
{
	printf("****����ͼ****\n");
	int edge_num=0;
	cout<<"�����붥�����Լ�����:";
	cin>>graphsize>>edge_num;
	
	for(int i=1;i<=graphsize;i++)
		for(int j=1;j<=graphsize;j++)
			edge[i][j]=99999999;
			
	for(int i=1;i<=graphsize;i++)
		edge[i][i]=0;
	
	for(int i=1;i<=edge_num;i++)
	{
		int node1,node2,value;
		printf("�������������㣬�����ıߵ�Ȩֵ:");
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
	printf("��������Ҫ��ѯ����������:");
	scanf("%d%d",&node1,&node2);
	
	if(node1<1||node1>graphsize||node2<1||node2>graphsize)
	{
		printf("����Ķ��㳬��������Χ.");
	}
	else if(edge[node1][node2]==0)
		printf("���������������Ϊͬһ���㣬��ߵ�ȨֵΪ0");
	else if(edge[node1][node2]==99999999)
		printf("��%d,%d������֮�䲻ֱ����ͨ",node1,node2);
	else
		printf("��%d,%d������֮��ıߵ�ȨֵΪ%d",node1,node2,edge[node1][node2]);
}

void GraphMatrix::GetFirstNeighbor()
{
	int v; 
	printf("�����붥��:");
	scanf("%d",&v);
	
	while(v<1||v>graphsize)
	{
		printf("������Ķ�����Ų����������У�����������:");
		scanf("%d",&v);
	}
	
	for(int i=1;i<=graphsize;i++)
	{
		if(edge[v][i]!=0&&edge[v][i]!=99999999)
		{
			printf("%d�ĵ�һ���ڽӶ�����:%d",v,i);
			return ;
		}
	}
	
	printf("%dû���ڽӶ���.",v);
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
				printf("��   ");
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
				printf("��   ");
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
				printf("��   ");
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
	printf("��������Ҫ���ҵ���������:");
	scanf("%d%d",&node1,&node2);
	printf("%d��%d֮�����̾�����:%d",node1,node2,a[node1][node2]);
	how[0]=node2;
	while(how[m]!=node1)
	{
		int pre=how[m];
		how[++m]=path[node1][pre];
	}
	
	cout<<endl<<"������·��Ϊ:";
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
		printf("�������ݴ���,����������:");
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
			printf("�������ݴ���,����������:");
			scanf("%d",&choice);
		}
	}
}


void menu()
{
	printf("\n=========================================\n");
	printf("1.����ͼ��ָ���ߵ�Ȩֵ\n");
	printf("2.����ͼ��ĳ����ĵ�һ���ڽӶ���\n");
	printf("3.������ȱ���\n");
	printf("4.������ȱ���\n");
	printf("5.���ⶥ�������·�������·������\n");
	printf("0.�˳�\n");
	printf("===========================================\n");
	printf("����������ѡ��:");
}
