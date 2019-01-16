//=====================================
//���⣺ʵ��һ���������ࣺ�ɼ�����ʽ
//˵�����˽�һ��Caculat���࣬���ַ�����ֵ
//ʹ��.ans��ɵõ����ʽ�����
//ע�⣺���롢����������ļ���
//=====================================

//-----------����ͷ�ļ�-----------------
#include<iostream>   
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#define cin fin
#define cout fout
using namespace std;

//------------ȫ�ֱ���-----------------
ifstream fin("expr.in");
ofstream fout("expr.out");

//--------------���װ-----------------
class Caculat {
private:
	//----------��Ա����------------------
	stack<char> mystack;                          //STL
	stack<int> mynumstack;
	queue<int> temper;
	char ch;                                     //����
	string str;
	bool flag = false;
	//----------��Ա����-------------------
	void center();                               //CPU
	void calculate();                            //ALU          
	void stua1(char);
	void stua2(char);
	void stua3(char);
	void stua4(char);
	void stua5();
	void creat(int);                            //MEMORY
public:
	Caculat(string temp) { str = temp; };         //����
	~Caculat() {};                               //����

	void ans();
};//------------------------------------
  //-------------��Ա��������--------------
void Caculat::calculate()                      //����
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
inline void Caculat::stua1(char ch)              //�Ӽ�
{
	if (mystack.top() != '(')
	{
		calculate();
		mystack.push(ch);
	}
	else mystack.push(ch);
}//------------------------------------
void Caculat::stua2(char ch)                    //�˳�
{
	if ((mystack.top() == '*') || (mystack.top() == '/'))
	{
		calculate();
		mystack.push(ch);
	}
	else mystack.push(ch);
}//--------------------------------------
inline void Caculat::stua3(char ch)              //������
{
	mystack.push(ch);
}//--------------------------------------
void Caculat::stua4(char)                       //������
{
	while (mystack.top() != '(')
	{
		calculate();
	}
	mystack.pop();
}//--------------------------------------
void Caculat::stua5()                         //�Ⱥ�
{
	while (mystack.top() != '(')
	{
		calculate();
	}
	fout << mynumstack.top() << endl;
	mynumstack.pop();
}//-------------------------------------
void Caculat::creat(int temp)                 //����
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


//----------------������----------------
int main()
{   
	for (string str; getline(fin, str);)
	{
		Caculat a(str);
		a.ans();
	}
}


