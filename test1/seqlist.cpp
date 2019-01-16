#include <stdlib.h>
#include <iostream>
using namespace std;

class seqlist{
	private:
		int maxsize;
		int length;
		int *base;
	public:
		seqlist(){ length=0;	};
		~seqlist(){ if(base==NULL)  delete []base;}
		void creat();
	    void del();
	    void insert();
	    int store();
	    void search();
	    void output();
};

void menu();

int main()
{
	seqlist l;
	int choose,storage;
	menu();
	while(scanf("%d",&choose)&&choose)
	{
	    switch(choose)
	    {
		    case 1:l.creat(); break;
		    case 2:l.insert(); break;
		    case 3:storage=l.store(); break;
		    case 4:l.del(); break;
		    case 5:l.search();
	    }
	    printf("\n\n\n\n");
	    menu();
    }
	return 0;
}

void seqlist::creat()
{
	printf("请输入您想要创建的节点个数:");
	scanf("%d",&maxsize);
	base=new int[maxsize]; 
	printf("顺序表创建成功，可容纳%d个节点！",maxsize);
}

void seqlist::insert()
{
	int data,i,j;
	if(length==maxsize)
	{
		printf("\n该线性表已满，无法继续插入节点！");
		return ;
	}
	printf("请输入您所想插入节点的位置以及值（如果您是第一次调用该函数，建议从0节点处开始插入）：\n");
	printf("输入-1 -1即可结束操作\n");
	scanf("%d%d",&i,&data);
	while(i!=-1&&data!=-1)
	{
		while(i>maxsize||i<-1||(i==-1&&data!=-1))
		{
			if(i>maxsize)
			{
				printf("插入节点位置超出您所建立的顺序表的最大节点数%d,请重新输入您所想插入节点的位置以及值:\n",maxsize);
				scanf("%d%d",&i,&data);
			}
			if(i<-1||(i==-1&&data!=-1))
			{
				printf("插入节点位置小于顺序表第一个节点位置0，请重新输入您所想插入节点的位置以及值:\n");
				scanf("%d%d",&i,&data);
			}
		}	
		
		for(j=length-1;j>i;j--)
		{
			base[j+1]=base[j];
		}
		
		base[i]=data;
		length++;
		
		printf("位置为%d,值为%d的节点插入成功！\n",i,data);
		
		printf("\n");
		printf("现在顺序表中的所有节点为:\n");
		output();
		printf("\n");
		
		
		if(length==maxsize)
		{
			printf("\n该线性表已满，无法继续插入节点！\n");
			return ; 
		}
		else
		{
			printf("请继续输入下一个您想要插入的节点的位置及其值(若您想结束操作，请输入-1 -1):");
			scanf("%d%d",&i,&data);
		}
	}
	
}

void seqlist::output()
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("位置值为%d的节点的值为：%d\n",i,base[i]);
	}	
}

void seqlist::search()
{
	int flag=1;
	int k;

	while(flag)
	{
		printf("请输入您所想要查找的元素值:");
	    scanf("%d",&k);
	    
		int i,count=0;
		for(i=0;i<length-1;i++)
		{
			if(k==base[i])
			{
				printf("您所要查找的元素%d在顺序表中的位置是：%d,即它是第%d个节点。",k,i,i+1);
				count++;
			}
		}
		if(!count)
		{
			printf("您所要查找的元素%d不存在于该顺序表中!\n\n",k);
		}
		else
		{
			printf("\n查找元素成功！\n\n");
		}
		
		printf("请决定是否继续查找（继续查找输入1，退出查找输入0）:");
		scanf("%d",&flag);
		while(flag!=0&&flag!=1)
		{
			printf("选择错误,请重新输入您的选择（继续查找输入1，退出查找输入0）：");
			scanf("%d",&flag);
		}
	}
}

void seqlist::del()
{
	int i,loc;
	int flag=1;
	
	while(flag)
	{
		
		printf("\n");
		printf("现在顺序表中的所有节点为:\n");
		output();
		printf("\n");		
		
		
		
		printf("请输入您所要删除节点的位置:");
		scanf("%d",&loc);
		
		while(loc<0||loc>length-1)
		{
			if(loc>length-1)
			{
				printf("删除节点位置超出线性表已有元素的最大位置值:%d,请重新输入您所想删除节点的位置:\n",length-1);
				scanf("%d",&loc);				
			}
			if(loc<0)
			{
				printf("删除节点位置小于顺序表第一个节点位置0，请重新输入您所想删除节点的位置:\n");
				scanf("%d",&loc);			
			}
		}
		
		if(length==0)
		{
			printf("\n顺序表为空，无法继续进行删除操作!\n");
			return ;
		}
		
		for(i=loc+1;i<length;i++)
		{
			base[i-1]=base[i]; 
		}
		
		length--;
		
		
		printf("\n");
		printf("现在顺序表中的所有节点为:\n");
		output();
		printf("\n");
		
		
		
		if(length==0)
		{
			printf("\n顺序表为空，无法继续进行删除操作!");
			return ;
		}
		
		printf("请决定是否继续删除（继续删除输入1，退出删除输入0）:");
		scanf("%d",&flag);
		printf("\n");
		while(flag!=0&&flag!=1)
		{
			printf("\n选择错误,请重新输入您的选择（继续删除输入1，退出删除输入0）：");
			scanf("%d",&flag);
		}
	}
}

int seqlist::store()
{
	int k;
	printf("请输入您想要存取的节点的位置:");
	scanf("%d",&k);
	return base[k];
}

void menu()
{
	printf("------------------------------------------------\n");
	printf("\t请选择如下您所需要的功能：\n");
	printf("*1.创建可容纳M个节点的顺序表\n");
	printf("*2.在顺序表中第k个结点后插入一个新结点\n");
	printf("*3.存取顺序表中第k个结点的值\n");
	printf("*4.删除顺序表中第k个结点\n");
	printf("*5.顺序查找值为x的元素在顺序表中的位置（下标）\n");
	printf("------------------------------------------------");
	printf("\n请选择您所需要的功能(输入0即可退出):");
}
