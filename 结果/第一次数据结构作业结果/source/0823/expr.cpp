//=====================================
//标题：实现一个计算器类：可计算表达式
//说明：兴建一个Caculat的类，用字符串赋值
//使用.ans便可得到表达式结果；
//注意：输入、结果生成在文件中
//=====================================

//-----------扩入头文件-----------------
#include<iostream>   
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#define cin fin
#define cout fout
using namespace std;

//------------全局变量-----------------
ifstream fin("expr.in");
ofstream fout("expr.out");

//--------------类封装-----------------
class Caculat {
private:
	//----------成员变量------------------
	stack<char> mystack;                          //STL
	stack<int> mynumstack;
	queue<int> temper;
	char ch;                                     //变量
	string str;
	bool flag = false;
	//----------成员函数-------------------
	void center();                               //CPU
	void calculate();                            //ALU          
	void stua1(char);
	void stua2(char);
	void stua3(char);
	void stua4(char);
	void stua5();
	void creat(int);                            //MEMORY
public:
	Caculat(string temp) { str = temp; };         //构造
	~Caculat() {};                               //析构

	void ans();
};//------------------------------------
  //-------------成员函数定义--------------
void Caculat::calculate()                      //计算
{
	int a1, a2;
	char opr = mystack.top();
	mystack.pop();
	a1 = mynumstack.top();
	mynumstack.pop();
	a2 = mynumstack.top();
	mynumstack.pop();
	if (opr == '+')
		mynumstack.push(a2 + a1);
	else if (opr == '-')
		mynumstack.push(a2 - a1);
	else if (opr == '*')
		mynumstack.push(a2 * a1);
	else if (opr == '/')
		mynumstack.push(a2 / a1);
}//-------------------------------------
inline void Caculat::stua1(char ch)              //加减
{
	if (mystack.top() != '(')
	{
		calculate();
		mystack.push(ch);
	}
	else mystack.push(ch);
}//------------------------------------
void Caculat::stua2(char ch)                    //乘除
{
	if ((mystack.top() == '*') || (mystack.top() == '/'))
	{
		calculate();
		mystack.push(ch);
	}
	else mystack.push(ch);
}//--------------------------------------
inline void Caculat::stua3(char ch)              //左括号
{
	mystack.push(ch);
}//--------------------------------------
void Caculat::stua4(char)                       //右括号
{
	while (mystack.top() != '(')
	{
		calculate();
	}
	mystack.pop();
}//--------------------------------------
void Caculat::stua5()                         //等号
{
	while (mystack.top() != '(')
	{
		calculate();
	}
	fout << mynumstack.top() << endl;
	mynumstack.pop();
}//-------------------------------------
void Caculat::creat(int temp)                 //加数
{
	int a1, an = 0;
	bool flager = false;
	if (flag)
	{
		temper.push(temp);
	}
	else
	{
		while (!temper.empty())
		{
			a1 = temper.front();
			an = 10 * an + a1;
			temper.pop();
			flager = true;
		}
		if (flager)
			mynumstack.push(an);
	}
}
inline void Caculat::ans()
{
	center();
}
//------------------------------------
void Caculat::center() {
	mystack.push('(');
	char ch;
	for (istringstream sin(str); sin >> ch;)
	{
		if (int('0') <= int(ch) && int(ch) <= int('9'))
			flag = true;
		else  flag = false;
		creat(int(ch) - int('0'));
		switch (int(ch))
		{
		case 43: stua1(ch); break; //jiafa
		case 45: stua1(ch); break; //jianfa
		case 42: stua2(ch); break; //chengfa
		case 47: stua2(ch); break; //chufa
		case 40: stua3(ch); break; //zuo
		case 41: stua4(ch); break; //you
		case 61: stua5();
		}
	}
}//------------------------------------


//----------------主函数----------------
int main()
{   
	for (string str; getline(fin, str);)
	{
		Caculat a(str);
		a.ans();
	}
}


