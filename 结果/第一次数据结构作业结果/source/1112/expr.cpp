#include<stdio.h>
#include<stdlib.h>
#define N 1000
FILE*ff;
struct stack1{
	char a;
	struct stack1*next;
}*top;
struct stack2{
	int b;
	char c;
	struct stack2*link;
}*head,*p;
void conver(char*);
void push1(char);
void push2(int);
void push3(char);
char pop1(struct stack1*);
void compare(char);
int priority(char);
void calculate();
void print();
int main(){
	char z[N];
	FILE*fp;
	if((fp=fopen("expr.in","r"))==NULL){
		printf("can't open file expr.in");
		exit(0);
	}
	if((ff=fopen("expr.out","w"))==NULL){
		printf("can't open file expr.cut");
		exit(0);
	}
	while(fgets(z,N,fp)!=NULL){
	top=(struct stack1*)malloc(sizeof(struct stack1));
	head=(struct stack2*)malloc(sizeof(struct stack2));
	p=head;
	top->a='=';
	head->link=NULL;
	conver(z);
	calculate();
	}
	fclose(fp);
	fclose(ff);
	printf("OK\n");
	return 0;
}
void conver(char *z){
	struct stack1*r;
	int i,j,number;
	i=0;
	while(z[i]){
		if(z[i]>='0'&&z[i]<='9'){
			j=10;
		    number=0;
		while(z[i]>='0'&&z[i]<='9'){
			number=number*j+z[i]-'0';
			i++;
		}
		push2(number);
		}
		if(z[i]=='\0') break;

		switch(z[i]){
		case '(':push1(z[i]);break;
		case ')':while(pop1(top)!='(');
			     r=top;
				 top=top->next;
				 free(r);
			     break;
		case '+':
		case '-':
		case '*':
		case '/':compare(z[i]);break;
		}
		i++;
	}
	while(top->a!='='){
		r=top;
		push3(top->a);
		top=top->next;
		free(r);
	}

}
void push1(char k){
	struct stack1*p;
	p=(struct stack1*)malloc(sizeof(struct stack1));
	p->a=k;
	p->next=top;
	top=p;
}
void push2(int k){
	struct stack2*y;
	y=(struct stack2*)malloc(sizeof(struct stack2));
	y->b=k;
	y->c=0;
	p->link=y;
	p=y;
	p->link=NULL;
}
void push3(char k){
	struct stack2*y;
	y=(struct stack2*)malloc(sizeof(struct stack2));
	y->b=0;
	y->c=k;
	p->link=y;
	p=y;
	p->link=NULL;
}

char pop1(struct stack1*p){
	push3(p->a);
	top=top->next;
	free(p);
	return top->a;
}
void compare(char k){
	if(top->a=='='){
		push1(k);
		return;
	}
	while(priority(k)<=priority(top->a)){
		pop1(top);
	}
	push1(k);


}
int priority(char k){
	switch(k){
	case '*':
	case '/':return 2;break;
	case '+':
	case '-':return 1;break;
	case '(':
	case '=':return 0;
	}
}
void calculate(){
	struct stack2*u,*v,*q,*h;
	h=head;
	u=head->link;
	v=u->link;
	q=v->link;
	while(q){
		switch(q->c){
		case '+':v->b=u->b+v->b;
			     h->link=v;
				 free(u);
				 v->link=q->link;
				 free(q);
				 if(v->link==NULL){
					 q=NULL;
					 break;
				 }
				 h=head;
				 u=head->link;
				 v=u->link;
				 q=v->link;
				 break;
		case '-':v->b=u->b-v->b;
			     h->link=v;
				 free(u);
				 v->link=q->link;
				 free(q);
				 if(v->link==NULL){
					 q=NULL;
					 break;
				 }
				 h=head;
				 u=head->link;
				 v=u->link;
				 q=v->link;
				 break;
		case '*':v->b=u->b*v->b;
			     h->link=v;
				 free(u);
				 v->link=q->link;
				 free(q);
				 if(v->link==NULL){
					 q=NULL;
					 break;
				 }
				 h=head;
				 u=head->link;
				 v=u->link;
				 q=v->link;
				 break;
		case '/':v->b=u->b/v->b;
			     h->link=v;
				 free(u);
				 v->link=q->link;
				 free(q);
				 if(v->link==NULL){
					 q=NULL;
					 break;
				 }
				 h=head;
				 u=head->link;
				 v=u->link;
				 q=v->link;
				 break;
		default:h=h->link;
			    u=u->link;
				v=v->link;
				q=q->link;
		}
	}
	head=head->link;
	fprintf(ff,"%d\n",head->b);
}





