#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct fuhao{
	int top;
	char data[100];
}; 
struct num{
	int top;
	int data[100];
};
int jisuan(fuhao a,num b){
	char ch;
	int m; 
	ch=a.data[a.top];
	switch(ch){
		case'+':m= b.data[b.top-1]+b.data[b.top];break;
		case'-':m= b.data[b.top-1]-b.data[b.top];break;
		case'*':m= b.data[b.top-1]*b.data[b.top];break;
		case'/':m= b.data[b.top-1]/b.data[b.top];break;
	}
	return m;
}
void operate(char str[100],fuhao a,num b){
	char ch;
	int i=0,m;
	ch=str[i];
	while(ch!='='){
		switch(ch){
			case'(':{
				a.top++;
				a.data[a.top]='(';
				i++;
				ch=str[i];
				break;
			}
			case')':{
				while(a.data[a.top]!='('){
				b.data[b.top-1]=jisuan(a,b);
				b.top--;
				a.top--;
			}
			a.top--;//把（也删除 
			i++;
			ch=str[i]; 
			break;
			} 
			case'+':{
				while(a.data[a.top]!=-1&&a.data[a.top]!='('){
				b.data[b.top-1]=jisuan(a,b);
				b.top--;
				a.top--;
			}
			a.top++;
			a.data[a.top]='+';//把加号压入
			i++;
			ch=str[i];
			break;
			}//加减号前面只能有左括号 
			case'-':{
				while(a.data[a.top]!=-1&&a.data[a.top]!='('){
				b.data[b.top-1]=jisuan(a,b);
				b.top--;
				a.top--;
			}
			a.top++;
			a.data[a.top]='-';
			i++;
			ch=str[i];
			break;
			}
			case'*':{
				if(a.data[a.top]=='*'||a.data[a.top]=='/'){
				b.data[b.top-1]=jisuan(a,b);
				b.top--;
				a.top--;
				}
				a.top++;
				a.data[a.top]='*';
				i++;
				ch=str[i];
				break;
			}
			case'/':{
				if(a.data[a.top]=='*'||a.data[a.top]=='/'){
				b.data[b.top-1]=jisuan(a,b);
				b.top--;
				a.top--;
				}
				a.top++;
				a.data[a.top]='/';
				i++;
				ch=str[i];
				break;
			}
			default:{
				m=0;
				while(ch<='9'&&ch>='0'){
					m=m*10+(ch-'0');
					i++;
					ch=str[i];
				}
				b.top++;
				b.data[b.top]=m;
				break;
			}
				
		}
	}
	while(a.data[a.top]!=-1){
		b.data[b.top-1]=jisuan(a,b);
		b.top--;
		a.top--;

	}
	FILE *p;
	p=fopen("expr.out","w");
	if(p==NULL){
		printf("cannot open the file.");
		exit (0);
	}
	fprintf(p,"%d\n",b.data[b.top]);
}	

int main(){
	char str[100];
	int n=0;
	fuhao a;//用来装符号 
   	a.top=-1;
	num b;//用来装数字 
	b.top=-1; 
	FILE *f;
	f=fopen("expr.in","r");
	if(f==NULL){
		printf("cannot open the file.");
		exit (0);
 }
	fscanf(f,"%s",str);
	operate(str,a,b);
	fclose(f);
}
