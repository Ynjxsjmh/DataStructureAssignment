#include<iostream>
#include<cmath>
class node{
	public:
	int x,y,r;
	node*link,*next;
};
class f{
	node *head;
	int all;
	public:
	void op(int xx,int yy,int rr);
	f(){
	head=new node;
	all=0;
	head->link=NULL;
	head->next=NULL;
	}
};
	void f::op(int xx,int yy,int rr){
		node *p,*q,*h;
		float len;
		p=new node;
		p->x=xx;
		p->y=yy;
		p->r=rr;
		if(head->link==NULL){
			head->link=p;
			all++;
			return;
		}
		else{
			q=head;
			h=head;
			while(q!=NULL){
				h=h->link;
			    while(h!=NULL){
				    len=sqrt((h->x-xx)*(h->x-xx)+(h->y-yy)*(h->y-yy));
				    if(len<h->r+rr){
				    	p->link=h->link;
				    	h->link=p;
				        break;
				    }
				   else h=h->link;
	            }
				if(q->next==NULL) break;
				else q=q->next;
				
            }
			}
			    if((q->next==NULL)&&(h->next==NULL)){
			    	node *d,*s;
			    	d=new node;
			    	s=new node;
			    	s->next=s->ling=NULL;
			    	d->next=d->link=NULL;
			    	d->x=xx;
			    	d->y=y;
			    	d->r=rr;
			    	q->next=s;
			    	s->link=d;
			    	all++;
			    }
		}
	}
int main(){
	f gg;
	int x,y,r,n;
	ifstream ins("circle.in");
	ofstream outs("circle.out");
	ins>>n;
	while(n--){
	ins>>x>>y>>r;
	gg.op(x,y,r);
	}
	outs<<gg.all;
	return 0;
}
	
			    	
			    	
		
		
