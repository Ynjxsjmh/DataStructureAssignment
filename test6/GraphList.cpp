//使用两个dfs的原因是为了避免非连通图的出现 
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

void menu()
{
	printf("\n***********************************\n");
	printf("1.返回图中指定边的权值.\n");
	printf("2.向图中插入一个顶点.\n");
	printf("3.向图中插入一条边.\n");
	printf("4.从图中删除一个顶点.\n");
	printf("5.从图中删除一条边.\n");
	printf("6.查找图中某顶点的第一个邻接顶点.\n");
	printf("7.深度优先遍历.\n");
	printf("8.广度优先遍历.\n");
	printf("9.任意顶点间的最短路.\n");
	printf("10.单源最短路.\n");
	printf("0.退出.\n");
	printf("*************************************\n");
	printf("请输入您的选择:");
}

struct edge{
	friend class GraphList;
	int veradj;
	int cost;
	edge *next;
};

struct vertex{
	friend class GraphList;	
	int vername;
	edge *adjacent;
};

class GraphList{
	private:
		vertex* head;
		int graphsize;
		int vis[10005];
		void dfs(const int v);
		void bfs(const int v);
		
	public:
		GraphList();
		virtual ~GraphList();
		
		void show();
		void Find_Value();
		void insert_vertex();
		void insert_edge();
		void del_vertex();
		void del_edge();
		void Find_First_Neighbor();
		void DFS();
		void BFS();
		void norec_dfs(const int v);
		
		void bellmanford();
		void spfa();                              //SPFA
		void dijkstra();
};

GraphList::GraphList(){
	int e,from,to,value;
	head=new vertex[10005];
	
	printf("请输入顶点个数和边的条数:");
	scanf("%d%d",&graphsize,&e);
	
	for(int i=1;i<=graphsize;i++)
	{
		head[i].vername=i;
		head[i].adjacent=NULL;
	}
	
	for(int i=1;i<=e;i++)
	{
		printf("请输入边的始点，终点和权值:");
		scanf("%d%d%d",&from,&to,&value);
		
		edge *p=new edge;
		
		p->veradj=to;
		p->cost=value;
		p->next=NULL;
		
		edge *q=head[from].adjacent;
		if(q==NULL)
			head[from].adjacent=p;
		else
		{
			while(q->next!=NULL)
				q=q->next;
			q->next=p;
		}
	}
}

void GraphList::show()
{
	for(int i=1;i<=graphsize;i++)
	{
		edge *p=head[i].adjacent;
		if(p!=NULL)
			cout<<head[i].vername<<" -> ";
		else
			cout<<head[i].vername;
		while(p!=NULL)
		{
			if(p->next==NULL)
				printf("(%d,%d)",p->veradj,p->cost);
			else
				printf("(%d,%d) -> ",p->veradj,p->cost);
			p=p->next;
		}
		cout<<endl;
	}
}

GraphList::~GraphList()
{
	for(int i=1;i<=graphsize;i++)
	{
		edge *p=head[i].adjacent;
		while(p!=NULL)
		{
			head[i].adjacent=p->next;
			delete p;
			p=head[i].adjacent;
		}
	}
	delete[] head;
}

void GraphList::Find_Value()
{
	show();
	int node1,node2;
	int weight,loc;
	printf("请输入两个顶点:");
	scanf("%d%d",&node1,&node2);
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==node1)
		{
			loc=i;
			break;
		}
	}
	edge *p=head[loc].adjacent;
	
	while(p!=NULL)
	{
		if(p->veradj==node2)
		{
			weight=p->cost;
			printf("%d,%d这两个顶点之间的边的权值为:%d",node1,node2,weight);
			return ;
		}
		p=p->next;
	}
	
	printf("%d,%d这两个顶点之间不直接连通!",node1,node2);
	
}

void GraphList::Find_First_Neighbor()
{
	show();
	int node1,flag,loc;
	printf("请输入您要查询的顶点:");
	scanf("%d",&node1);
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==node1)
		{
			flag=1;
			loc=i;
			break;
		}
	}
	
	while(node1<1||!flag)
	{
		printf("该顶点不在数据域范围内，请重新输入:");
		scanf("%d",&node1);
		for(int i=1;i<=graphsize;i++)
		{
			if(head[i].vername==node1)
			{
				flag=1;
				loc=i;
				break;
			}
		}
	}
	
	edge *p=head[loc].adjacent;
	if(p==NULL)
		printf("该顶点没有邻接顶点.");
	else
		printf("该顶点的邻接顶点的值为:%d",p->veradj);
}

void GraphList::BFS()
{
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=graphsize;i++)
	{
		if(vis[ head[i].vername ]==0)
			bfs(i);
	}
}

void GraphList::bfs(const int v)
{
	int x;
	queue <int> q;
	edge *p=NULL;
//	memset(vis,0,sizeof(vis));
	
	q.push(v);
	vis[v] = 1;
	
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		cout<<x;
		
		int loc;
		for(int i=1;i<=graphsize;i++)
		{
			if(head[i].vername==x)
			{
				loc=i;
				break;
			}
		}
		
		for(p = head[loc].adjacent ; p ; p = p->next)
			if(vis[p->veradj] == 0)
			{
				q.push(p->veradj);
				vis[p->veradj] = 1;
			}
	}
}

void GraphList::dfs(const int v)
{
	edge *p=NULL;
	cout<<v;
	vis[v]=1;
	
	for(p=head[v].adjacent;p;p=p->next)
		if(vis[p->veradj]!=1)
			dfs(p->veradj);
}

void GraphList::DFS()
{	
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=graphsize;i++)
	{
		if(vis[ head[i].vername ]==0)
			norec_dfs(i);
	}
}

void GraphList::norec_dfs(const int v)
{
	edge *p;
	int u;
	stack <int> s;
	//int vis[graphsize+1];
	
	//memset(vis,0,sizeof(vis));
	
	s.push(v);
	vis[v]=1;
	while(!s.empty())
	{
		u=s.top();
		s.pop();
		
		cout<<u;
		
		int loc;
		for(int i=1;i<=graphsize;i++)
		{
			if(head[i].vername==u)
			{
				loc=i;
				break;
			}
		}
		
		for(p=head[loc].adjacent;p;p=p->next)
			if(vis[p->veradj]==0)
			{
				s.push(p->veradj);
				vis[p->veradj]=1;
			}
	}
}

void GraphList::insert_vertex()
{
	show();
	int flag=0;
	int v;
	printf("请输入要插入顶点的值:");
	scanf("%d",&v);
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==v)
			flag=1;
	}
	while(flag)
	{
		printf("该顶点已经存在,请重新输入:");
		scanf("%d",&v);
		flag=0;
		for(int i=1;i<=graphsize;i++)
		{
			if(head[i].vername==v)
				flag=1;
		}		
	}
	
	head[++graphsize].vername=v;
	head[graphsize].adjacent=NULL;
	
	show();
}

void GraphList::insert_edge()
{
	show();
	int flag1=0,flag2=0;
	int from,to,value;
	printf("请输入要插入两个顶点以及其边的权值:");
	scanf("%d%d%d",&from,&to,&value);
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==from)
		{
			flag1=1;
		}
		if(head[i].vername==to)
		{
			flag2=1;
		}
	}
	
	if(!flag1)
	{
		printf("%d这个点不存在，请重新输入:",from);
		scanf("%d",&from);
		flag1=0;
		for(int i=1;i<=graphsize;i++)
		{
			if(head[i].vername==from)
			{
				flag1=1;
			}
		}
	}
	
	if(!flag2)
	{
		printf("%d这个点不存在，请重新输入:",to);
		scanf("%d",to);
		flag2=0;
		for(int i=1;i<=graphsize;i++)
		{
			if(head[i].vername==from)
			{
				flag2=1;
			}
		}
	}	
	
	edge *p=new edge;
	
	p->veradj=to;
	p->cost=value;
	p->next=NULL;
	
	int loc;
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==from)
		{
			loc=i;
			break;
		}
	}
	
	edge *q=head[loc].adjacent;
	if(q==NULL)
		head[loc].adjacent=p;
	else
	{
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
	
	show();
}

void GraphList::del_vertex()
{
	show();
	
	int judge=0;                       //judge用来表示删除已一行元素 
	int flag=0;                       //flag用来表示head数组中是否存在v值这个点 
	int v;
	printf("请输入您要删除的顶点:");
	scanf("%d",&v);
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==v)
			flag=1;
	}
	
	while(v<1||!flag)
	{
		printf("您输入的顶点不在该图中，请重新输入:");
		scanf("%d",&v);
		flag=0;
		for(int i=0;i<=graphsize;i++)
		{
			if(head[i].vername==v)
				flag=1;
		}
	}
	
	for(int i = 1 ; i <= graphsize ; i++ )
	{
		
		
		if(head[i].vername != v)
		{
			edge *p=head[i].adjacent;
			if(p!=NULL&&p->veradj == v) //处理head[i].adjacent的值为v的情况 
			{                                   
				head[i].adjacent=p->next;
				delete p;
			}
			else
			{
				while(p!=NULL&&p->next!=NULL&&p->next->veradj!=v) //到达边中为值为v的邻接顶点 
					p=p->next;
				if(p!=NULL&&p->next!=NULL&&p->next->veradj==v)
				{
					edge *q=p->next;
					p->next=q->next;
					delete q;
				}
			}
			
			if(judge)
				head[i-1]=head[i];
//			if(head[i].vername>v)
//			{
//				head[i-1]=head[i];
//				head[i-1].vername=head[i].vername;
//				edge* &m=head[i-1].adjacent;
//				edge *n=head[i].adjacent;
//				
//				if(n!=NULL)
//				{
//					m=new edge;
//					m->cost=n->cost;
//					m->veradj=n->veradj;
//					m->next=NULL;
//					n=n->next;
//				}
//				while(n!=NULL)
//				{
//					edge *temp=new edge;
//					temp->cost=n->cost;
//					temp->veradj=n->veradj;
//					temp->next=NULL;
//					
//					m->next=temp;
//					m=m->next;
//					n=n->next;	
//				}
//			
//			}
		}
		else                                           //head[i].vername = v 时 
		{
			edge *p=head[i].adjacent;
			while(p!=NULL)
			{
				head[i].adjacent=p->next;
				delete p;
				p=head[i].adjacent;
			}
			judge=1;
		}
	}
	
//	edge *m=head[graphsize].adjacent;
//	while(m!=NULL)
//	{
//		head[graphsize].adjacent=m->next;
//		delete m;
//		m=head[graphsize].adjacent;
//	}
	graphsize--;
	show();
}

void GraphList::del_edge()
{
	show();
	
	int node1,node2;
	printf("请输入您要删除的边的两个顶点:");
	scanf("%d%d",&node1,&node2);
	
	edge *p=head[node1].adjacent;
	edge *pre=p;
	
	while(p&&p->veradj!=node2)
	{
		pre=p;
		p=p->next;
	}
	if(p&&pre==p)
		head[node1].adjacent=p->next;
	else if(p)
		pre->next=p->next;
	
	show();
}

void GraphList::bellmanford()
{
	show();
	int u,v,loc;
	int dist[100];
	edge *p;
	printf("请输入您要查询的起点和终点:");
	scanf("%d%d",&u,&v);
	
	for(int i = 0 ; i < 100 ; i++)
		dist[i] = 99999999;
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==u)
		{
			loc=i;
			break;
		}
	}
	
	dist[loc] = 0;
	
	for(int i = 1 ; i <= graphsize-1 ; i++)
	{		
		for(int j = 1 ;  j <= graphsize ; j++)
		{
//			for(int k=1;k<=graphsize;k++)
//			{
//				if(head[k].vername==j)
//				{
//					loc=k;
//					break;
//				}
//			}
			for(p = head[j].adjacent ; p ; p = p->next)
			{
				if(dist[head[j].vername] + p->cost < dist[p->veradj])
				{
					dist[p->veradj] = dist[head[j].vername] + p->cost;
				}
			}
		}
	}
	
	for(int i=1;i<=graphsize;i++)
	{
		if(head[i].vername==v)
		{
			loc=i;
			break;
		}
	}
	
	if(dist[head[loc].vername] == 99999999)
		printf("%d,%d这两个点不连通!",u,v);
	else
		printf("%d,%d这两个点的最短路为%d",u,v,dist[head[loc].vername]);
}

void GraphList::spfa()
{
	int loc;
	int v,u,inf=99999999;
	int dist[100000];
	int mark[100000];
	edge *p;
	
	show();
	
	for(int i=0;i<99999999;i++)
		dist[i]=99999999;
	memset(mark,0,sizeof(mark));
	
	printf("请输入顶点:");
	scanf("%d",&v);
	
	dist[v]=0;
	queue <int> q;
	q.push(v);
	mark[v]=1;
	
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		mark[u]=0;
		
		for(int i = 1 ; i <= graphsize ; i++)
		{
			if(head[i].vername == u)
			{
				loc = i ;
				break ;
			}
		}
		
		for(p = head[loc].adjacent ; p ; p = p->next)
		{
			if(dist[head[loc].vername] + p->cost < dist[p->veradj])
			{
				dist[p->veradj] = dist[head[loc].vername] + p->cost ;
				if(!mark[p->veradj])
				{
					q.push(p->veradj) ;
					mark[p->veradj] = 1 ;
				}
			}
		}
	}
	
	for(int i=1;i<=graphsize;i++)
	{
		if(dist[head[i].vername] == inf)
			printf("%d到%d之间不连通.\n",v,head[i].vername);
		else
		{
			printf("%d到%d的最短路径为:%d",v,head[i].vername,dist[head[i].vername]);
			printf("\n");
		}
	}
}

void GraphList::dijkstra()
{
	int path[1000],dist[1000];
	int max=9999999,u;
	memset(vis,0,sizeof(vis));
	memset(path,-1,sizeof(path));
	memset(dist,9999999,sizeof(dist));
	
	dist[1]=0;
	
	for(int j=1;j<graphsize;j++)
	{
		int idist=max;
		for(int i=1;i<=graphsize;i++)
			if(dist[i]<idist&&!vis[i])
			{
				u=i;
				idist=dist[i];
			}
		
		vis[u]=1;
		
		for(edge *p=head[u].adjacent;p;p=p->next)
		{
			int k=p->veradj;
			if(dist[u]+p->cost<dist[k])
			{
				dist[k]=dist[u]+p->cost;	
				path[k]=u;
			}
		}
	}
}


int main()
{
	GraphList graph;
	
	int choice;
	
	menu();

	while(scanf("%d",&choice)&&choice)
	{
		switch(choice)
		{
			case 1: graph.Find_Value();  break;
			case 2: graph.insert_vertex(); break;
			case 3: graph.insert_edge(); break;
			case 4: graph.del_vertex(); break;
			case 5: graph.del_edge(); break;
			case 6: graph.Find_First_Neighbor(); break;
			case 7: graph.DFS(); break;
			case 8: graph.BFS(); break; 
			case 9: graph.bellmanford(); break;
			case 10: graph.spfa(); break;
		}
		menu();
	}
}
