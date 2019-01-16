#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define LL long long
using namespace std;

const int Maxn=1000;
const int MaxStackSize=1000;

char str[Maxn+5];

template<class T>
class Stack{
	private:
		T stk[MaxStackSize+5];
		int top;
	public:
		Stack(){top=0;}
		void push(T x){stk[++top]=x;}
		T pop(){return stk[top--];}
		T back(){return stk[top];}
		bool empty(){return top==0;}
		void clear(){top=0;}
};

Stack<char> opt;
Stack<long long>  opn;

int getLevel(char x){
	if (x=='(') return 2;
	if (x=='+' || x=='-') return 3;
	if (x=='*' || x=='/') return 4;
	if (x=='=') return 1;
	return 0;
}

void doCalculate(char op){
	long long num2=opn.back();opn.pop();
	long long num1=opn.back();opn.pop();
	switch(op){
		case '+':
			opn.push(num1+num2);
			break;
		case '-':
			opn.push(num1-num2);
			break;
		case '*':
			opn.push(num1*num2);
			break;
		case '/':
			opn.push(num1/num2);
			break;
	}
	//printf("%d %c %d = %d\n",num1,op,num2,opn.back());
}

long long calculate(char exp[]){
	int len=strlen(exp);
	
	//Init
	opn.clear();
	opt.clear();
	opn.push(0);

	for (int pos=0;pos<len;){
		if ('0'<=str[pos] && str[pos]<='9'){
			long long num=0;
			for (;pos<len && ('0'<=str[pos] && str[pos]<='9');pos++) num=num*10LL+(LL)(str[pos]-'0');
			opn.push(num);
		}else{
			if (str[pos]=='(') 
				opt.push('(');
			else if (str[pos]==')'){
				while(opt.back()!='('){
					doCalculate(opt.back());
					opt.pop();
				}
				opt.pop();
			}else{
				while(!opt.empty() && getLevel(opt.back())>=getLevel(str[pos])){
					doCalculate(opt.back());
					opt.pop();
				}
				opt.push(str[pos]);
			}
			pos++;
		}
	}
	return opn.back();
}

int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",str);
	printf("%I64d\n",calculate(str));
	fclose(stdin);
	fclose(stdout);
	return 0;
}