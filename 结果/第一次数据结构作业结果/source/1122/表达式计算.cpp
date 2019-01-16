#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<class T>
class stack{
	private:
		int size;
		T * stackarray;
		int top;
	public:
		stack(int maxstacksize){
			size=maxstacksize;
			stackarray=new T[maxstacksize];
			top=-1;
		}
		~stack(){
			delete[] stackarray;
		}
		bool push(const T& item){
			if(isfull()){cout<<"pushing into a full stack"<<endl;return false;}
			stackarray[++top]=item;return true;
		}
		bool pop(){
			if(isempty()){cout<<"poping from a empty stack"<<endl;return false;}
			top--;return true;
		}
		bool peek(T& item)const{
			if(isempty()){cout<<"peeking from a empty stack"<<endl;return false;}
			item=stackarray[top];return true;
		}
		int isempty(void)const{return top==-1;}
		int isfull(void)const{return top==size-1;}
		void clear(void){top=-1;}
};
stack<int> num(1000);
stack<char> cha(1000);
int priority(char x){
	if(x=='+'||x=='-')
		return 0;
	if(x=='*'||x=='/')
		return 1;
	if(x=='(')
		return -1;
	if(x==')')
		return -1;
}
bool isnum(char x){
	if(x>='0'&&x<='9')
		return true;
	return false;
}
int main(){
	ifstream inf("expr.in");
	ofstream outf("expr.out");
	string str;
	char top;
	int a,b;
	getline(inf,str);
	for(int i=0;i<str.size();i++){
		if(isnum(str[i])){
			int temp=0;
			while(isnum(str[i])){
				temp=temp*10+str[i]-48;
				i++;
			}
			num.push(temp);
		}
		else{
			if(str[i]=='='){
                num.peek(b);
				outf<<b;
				num.pop();
				return 0;
			}
			else if(cha.isempty()){cha.push(str[i]);}
			else{
				cha.peek(top);
				if(priority(str[i])>priority(top)||str[i]=='('){cha.push(str[i]);}
				else{
					while(priority(str[i])<=(priority(top))){
						if(top=='('&&str[i]==')'){
                                i++;
						}
						else{
							num.peek(a);
							num.pop();
							num.peek(b);
							num.pop();
						}
						if(top=='+'){
                            b=a+b;
							num.push(b);
						}
						else if(top=='-'){
							b=a-b;
							num.push(b);
						}
						else if(top=='*'){
							b=a*b;
							num.push(b);
						}
						else if(top=='/'){
							b=a/b;
							num.push(b);
						}
						cha.pop();
						if(cha.isempty()){i--;break;}
						cha.peek(top);
					}
				}
			}
		}
	}
}
