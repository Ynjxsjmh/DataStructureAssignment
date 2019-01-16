#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
template<typename T>
class Num{
	T *a;
	int top;
	int l;
public:
	Num()
	{
		/*cout<<"请输入栈的大小"<<endl;
		cin>>l;*/
		l=100;
		a=new T[l];
		//if(a!=NULL) cout<<"创建成功"<<endl;
		top=-1;
	}
	~Num()
	{
		delete[] a;
	 }
	void push(T x){
		a[++top]=x;
	}

	T pop(){
		return a[top--];
	}

	T peek(){
		return a[top];
	}
	bool empty(){
		return top==-1;
	}

	bool full(){
		return top==l-1;
	}

	void clear(){
		top=-1;
	}
};
bool Fuhao(char op){
    switch(op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
	case '(':
	case ')':
        return true;
    default :
        return false;
    }
}
int priority(char op)
{
    switch(op)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default :
        return -1;
    }
}
int main(void)
{
	Num<int> p;
	Num<char> q;
	ifstream in("expr.in");
	string s,t;
	int j=0,a=0,b=0;
	getline(in,s);
	char e;
    //for(int i=0;s[i]!='\0';i++)
    //    if(Fuhao(s[i])) cout<<s[i];
	for(int i=0;s[i]!='\0';i++){
		if(!Fuhao(s[i]))
		{
			p.push(s[i]);
			t[j]=s[i];
			j++;
			a++;
		}
		else{
		    e=s[i];
			switch(e)
			{
				case'(':{
					q.push(s[i]);
					break;
				}
				case')':{
					while(q.peek()!='('){
                        q.pop();
						t[j]=q.peek();
						cout<<t[j]<<j<<endl;
						j++;
						b++;
					}
                    q.pop();
					break;
				}
				default:{
					while(priority(s[i]) <= priority(q.peek()))
		            {
		                // 当前的操作符小于等于栈顶操作符的优先级时，将栈顶操作符写入到后缀表达式，重复此过程
		                t[j]=q.peek();
		                cout<<t[j]<<j<<endl;
		                q.pop();
		                j++;
		                b++;
		            }
                    q.push(s[i]);
					break;
				   }

		    }
	     }

      }
  while(!q.empty())
  {
      t[j]=q.peek();
      j++;
      b++;
  }
  cout<<j<<" "<<a<<" "<<b;

}
