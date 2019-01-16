//��������ȫ��ɾ��ʱ����ֳ����Զ���ֹ����� 
//�ڵ��ò������ݺ���ʱ  ���������ݲ�Ϊ���Σ��������� 

#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
class slnode{
	public:
		T data;
		slnode<T> *next;
};

template <typename T>
class sllist{
	private:
		slnode<T> *head;
		slnode<T> *tail;
		slnode<T> *cur;
		int length;
	
	public:
		sllist(){
			head=tail=cur=new slnode<T>;
			head->next=NULL;
			length=0;
		}
		void creat();
		void insert();
		void del();
		T find(T item1,T item2);
		void search();
		void output();
		void destroy();
};

void menu();

int main()
{
	sllist<int> l;
	int item1,item2,temp=0,i,len;
	char choice[1000];
	
	menu();
	
	gets(choice);
	len=strlen(choice);
	for(i=0;i<len;i++)
	{
		temp=choice[i]-'0'+temp*10;
	}
	
	while(temp<0||temp>5)
	{
		printf("����ѡ����:%s,ѡ�����������κ�һ��,����������:",choice);
		scanf(" %s",&choice);
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}
	}	
	
	while(temp)
	{	
	    switch(temp)
	    {
		    case 1:l.creat(); break;
		    case 2:l.insert(); break;
		    case 3:l.del(); break;
		    case 4:l.find(item1,item2); break;
		    case 5:l.search();break;
	    }
	    printf("\n\n\n\n");
	    menu();
	    	    
		scanf(" %s",&choice);
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}

		while(temp<0||temp>5)
		{
			printf("����ѡ����:%s,ѡ�����������κ�һ��,����������:",choice);
			scanf(" %s",&choice);
			len=strlen(choice);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=choice[i]-'0'+temp*10;
			}
		}
    }
    
    if(!temp)
    {
    	l.destroy();
	}
    
	return 0;
}

template <typename T>
void sllist<T>::creat()
{
	printf("\n�������ɹ�����ǰ����0��Ԫ�ء�");
	
	output();
}


template <typename T>
void sllist<T>::insert()
{	
	char choice[100];
	int temp,i,len;
	printf("\n\n��ѡ����Ҫ�������ݵķ�ʽ:\n");
	printf("1.�ڱ�ͷ����ָ��.\n");
	printf("2.�ڵ�ǰ�ڵ�����ָ��.\n");
	printf("3.�ڱ�β����ָ��.\n");
	scanf(" %s",&choice);
	
	len=strlen(choice);
	temp=0;
	for(i=0;i<len;i++)
	{
		temp=choice[i]-'0'+temp*10;
	}
	
	while(temp<1||temp>3)
	{
		printf("����ѡ����:%s,ѡ�����������κ�һ��,����������:",choice);
		scanf(" %s",&choice);
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}
	}		
	
	if(temp==1)
	{
		int data;
		printf("����������Ҫ�ӱ�ͷ��������ݣ�����-1����:");
		scanf(" %d",&data);
		while(data!=-1)
		{
			slnode<T> *p;
			p=new slnode<T>;
			p->data=data;
			if(head->next==NULL)
			{
				head->next=p;
				p->next=NULL;
				tail=p;
				cur=p;
				length++;
			}
			else
			{
				p->next=cur;
				head->next=p;
				cur=p;
				length++;
			}
			
			printf("�Ƿ��������ڵ㣬��������ڵ����ݣ�����������-1:");
			scanf(" %d",&data);		
		}		
	}
	
	
	
	if(temp==2)
	{
		int data;
		printf("����������Ҫ�ӵ�ǰ�ڵ���������ݣ�����-1����:");
		scanf("%d",&data);
		while(data!=-1)		
		{
			slnode<T> *p;
			p=new slnode<T>;
			p->data=data;			
			if(cur==tail)
			{
				cur->next=p;
				p->next=NULL;
				cur=p;
				tail=p;
				length++;
			}
			if(cur!=tail)
			{
				p->next=cur->next;
				cur->next=p;
				cur=p;
				length++;
			}
						
			printf("�Ƿ��������ڵ㣬��������ڵ����ݣ�����������-1:");
			scanf("%d",&data);
		}
	}
	
	
	if(temp==3)
	{
		int data;
		printf("����������Ҫ�ӱ�β��������ݣ�����-1����:");
		scanf("%d",&data);
		while(data!=-1)
		{
			slnode<T> *p;
			p=new slnode<T>;
			p->data=data;
			
			tail->next=p;
			p->next=NULL;
			cur=p;
			tail=p;
			length++;
			
			printf("�Ƿ��������ڵ㣬��������ڵ����ݣ�����������-1:");
			scanf("%d",&data);
		}
	}
	
	output();
}

template <typename T>
void sllist<T>::search()
{
	if(head->next==NULL)
	{
		printf("��ǰ����Ϊ�գ��޷����в��Ҳ���!\n");
	}
	
	else
	{
		slnode<T> *p;
		int judge,flag=1,count;
		char search_data[100];
		int temp,i,len;
		int loc;
	
		while(flag)
		{
			loc=0;
			count=0;
			p=head;
		
			printf("\n\n����������Ҫ��ѯ������:");
			scanf(" %s",&search_data);
		
			len=strlen(search_data);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=search_data[i]-'0'+temp*10;
			}
		
			while(p!=NULL)
			{
				if(p->data==temp)
				{
					printf("��Ҫ���ҵ�����%s�ڸõ������е�λ��Ϊ:%d\n\n",search_data,loc);
					count++;
					loc++;
					
					cur=p;              //��ǰ�ڵ�ָ���ҵ���ָ�� 
				}
				
				p=p->next;
				loc++;
     	   }
			
	 	   if(count==0)
		    {
	 		   	printf("�õ�������û��������Ҫ�ҵĵ�!\n");
	 		   	printf("�Ƿ�������Ҳ���?(0��ʾ�˳�����,1��ʾ��������):");
		 	   	scanf("%d",&judge);
	    	
				while(judge!=0&&judge!=1)
				{
					printf("�������ݴ�������������:(0��ʾ�˳���1��ʾ��������)");
					scanf("%d",&judge);
				}
			
				if(!judge)				
					flag=0;
				
				else
					flag=1;			
			}
			else
			{
				printf("�Ƿ�����������ݣ�(0��ʾ�˳�����,1��ʾ��������)");
				scanf("%d",&judge);
				while(judge!=0&&judge!=1)
				{
					printf("�������ݴ�������������:(0��ʾ�˳���1��ʾ��������)");
					scanf("%d",&judge);
				}
						
				if(!judge)				
					flag=0;
				else			
					flag=1;		
			}		
		}
	}
}

template <typename T>
T sllist<T>::find(T item1,T item2)
{
	if(head->next==NULL)
	{
		printf("��ǰ����Ϊ�գ��޷����в���!\n");
	}
	
	else
	{
		slnode<T> *p=head->next;
		int i,temp,len;
		char k[100];
		printf("\n\n����������Ҫ��ȡ�ڵ���±�:");
		scanf(" %s",&k);
		
		len=strlen(k);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=k[i]-'0'+temp*10;
		}	
	
		while(temp<1||temp>length)
		{
			if(temp<1)
			{
				printf("��������±�%sС�ڸ�������½�1,����������:",k);
				scanf(" %s",&k);
			}
			if(temp>length)
			{
				printf("�������±�%s���ڸ�������Ͻ�%d,����������:",k,length);
				scanf(" %s",&k);
			}
				len=strlen(k);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=k[i]-'0'+temp*10;
			}	
		}
	
		for(i=1;i<temp;i++)
		{
			p=p->next;
		}
	
		item1=p->data;
		item2=cur->data;
		
		printf("Ҫ���ҽڵ��ֵΪ:%d\n",item1);
		printf("��ǰ�ڵ��ֵΪ:%d\n",item2);
	
		printf("Ҫ���ҵ������Ѵ����һ��ʵ���У���ǰ�ڵ�������Ѵ���ڶ���ʵ����.");
    }
}

template <typename T>
void sllist<T>::output()
{
	int i=1;
	slnode<T> *p=head->next;
	
	while(p!=NULL)
	{
		if(p->next==NULL)
			printf("%d",p->data);
		else
			printf("%d  ->",p->data);
		p=p->next;
		i++;
	}
	
	printf("\n��ǰ������Ϊ:%d",length);
}

template <typename T>
void sllist<T>::destroy()
{
	slnode<T> *p=head->next;
	
	while(p!=NULL)
	{
		delete head;
		head=p;
		p=p->next;
	}
	
	printf("\n��������ɹ���");
}

template <typename T>
void sllist<T>::del()
{
	
	if(head->next==NULL)
	{
		printf("��ǰ�ڵ�Ϊ�գ��޷�����ɾ��������");		
	}
	
	else
	{	
		char choice[100];
		int temp,i,len;
		printf("\n\n��ѡ����Ҫɾ���ڵ�ķ�ʽ:\n");
		printf("1.ɾ����ͷ�ڵ�.\n");
		printf("2.ɾ����β�ڵ�.\n");
		printf("3.ɾ����ǰ�ڵ�ĺ�̽ڵ�.\n");
		scanf(" %s",&choice);
		
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}
	
		while(temp<1||temp>3)
		{
			printf("����ѡ����:%s,ѡ�����������κ�һ��,����������:",choice);
			scanf(" %s",&choice);
			len=strlen(choice);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=choice[i]-'0'+temp*10;
			}
		}
	
		if(temp==1)
		{			
			slnode<T> *p;
			if(head->next==cur&&head->next==tail)
			{		
				p=head->next;	
				head=tail;
				head=cur;
				head->next=NULL;
				delete p;
				length--;
				printf("ɾ���ڵ�ɹ���");
			}
		
			if(head->next==cur&&head->next!=tail)
			{
				p=cur;
				cur=cur->next;
			
				head->next=cur;
				delete p;
			
				length--;
				printf("ɾ���ڵ�ɹ���");
			}
		
			if(head->next!=cur)
			{
				p=head->next;
				head->next=p->next;
			
				delete p;
				length--;
			
				printf("ɾ���ڵ�ɹ���");
			}
			

		}
	
		if(temp==2)
		{
			slnode <T> *p=head;
		
			while(p->next!=tail)
			{
				p=p->next;
			}
		
			if(cur==tail)
			{
				tail=p;
				cur=p;
				p=p->next;
				delete p;
				tail->next=NULL;
				length--;
				printf("ɾ���ڵ�ɹ���");
			}
		
			if(cur!=tail)
			{
				tail=p;
				p=p->next;
				delete p;
	 	        tail->next=NULL;
				length--;
				printf("ɾ���ڵ�ɹ���");
			}		
		}	
	
		if(temp==3)
		{
			slnode<T> *p=head;
		
			if(cur==tail)
			{
				printf("��ǰ�ڵ�Ϊβ�ڵ㣬�޺�̽ڵ�!");
			//	return ;
			}
		
			if(cur->next==tail)
			{
				p=cur->next;
				tail=cur;
				delete p;
				tail->next==NULL;
				length--;
				printf("ɾ���ڵ�ɹ���");			
			}
		
			else
			{
				p=cur->next;
				cur->next=p->next;
				delete p;
				length--;
				printf("ɾ���ڵ�ɹ���");
			}
		}
		printf("\n");
		output();
    }
}

void menu()
{
	printf("-----------------------------------------------------------------------------\n");
	printf("\t��ѡ������������Ҫ�Ĺ��ܣ�\n");
	printf("* 1.����������\n");
	printf("* 2.����������ֱ��ڵ�ǰ���󡢱�ͷ����β����ֵΪx�Ľ��\n");
	printf("* 3.ɾ���������ֱ�ɾ����ͷ��㡢��β���͵�ǰ���ĺ�̽��\n");
	printf("* 4.��ȡ�������ֱ��ȡ��ǰ����ֵ�͵������е�k������ֵ\n");
	printf("* 5.���Ҳ���������ֵΪx��Ԫ���ڵ������г��ֵ�λ�ã��������еĵڼ���Ԫ�أ�\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n��ѡ��������Ҫ�Ĺ���(����0�����˳�):");
}
