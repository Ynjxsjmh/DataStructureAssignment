#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;
//#define cin fin
//#define cout fout

class calculateMachine
{
private://���ݳ�Ա
	string readin;
	stack<int> numberstack;
	stack<char> operatorstack;
	int tem,temnumber;
	char temoperator;
	int key;

public://���к�����Ա
	calculateMachine(string readin) : tem(0),temnumber(0),temoperator(),key(0)//num�������op��Ų�����
	{
		this->readin = readin;
	}
	void operation()
	{
		while(1)
		{
			key = get();
			if(key == 0)
				break;
			if(key == 1)//�����
			{
				if(operatorstack.empty() == true)
				{
					operatorstack.push(temoperator);
				}
				else
				{
					if( temoperator == ')')
					{	
						while(operatorstack.top() != '(')
						{
							go(operatorstack.top());
							operatorstack.pop();
						}
						operatorstack.pop();//����'('
					}
				
					else if( temoperator == '(' || priority(temoperator) > priority( operatorstack.top() ) )
					{
						operatorstack.push(temoperator);
					}	
					else
					{
						if(operatorstack.empty() == false)
						{
							while(priority(operatorstack.top()) >= priority(temoperator))
							{
								if(operatorstack.top() == '(')
									break;
								if(numberstack.size() <= 1)
								{
									break;
								}
								go(operatorstack.top());
								operatorstack.pop();
								if(operatorstack.empty() == true)
									break;		
							}
							operatorstack.push(temoperator);
						}	
					}
				}
			}
			if(key == 2)//������
			{
				numberstack.push(temnumber);
			}
			if(key == 3)//������
			{
				while(operatorstack.empty() == false)
				{
					go(operatorstack.top());
					operatorstack.pop();
				}
			}
		}
	}


	int print()
	{
		cout << "Ans = " <<  numberstack.top() << endl;
		return numberstack.top();
	}
		~calculateMachine()
	{
	}

private://˽�к�����Ա
	int priority(char prioritylevel)//�ж����ȼ�
	{
		if(prioritylevel == '+' || prioritylevel == '-')
			return 1;
		else if(prioritylevel == '*' || prioritylevel == '/')
			return 2;
		else if(prioritylevel == '(')
			return 3;
		else
		{
			cout << prioritylevel ;
			cout << "���ȼ�δ֪" << endl;
			system("pause");
			return 0;
		}
	}

	void go(char Operator)//�������
	{
		int numberx,numbery,answerz;
		numberx = numberstack.top();
		numberstack.pop();
		numbery = numberstack.top();
		numberstack.pop();
		if(Operator == '+')
			answerz = numberx + numbery;
		else if(Operator == '-')
			answerz = numbery - numberx;
		else if(Operator == '*')
			answerz = numberx * numbery;
		else if(Operator == '/')
		{
			if(numberx == 0)
			{
				cout << "Input Error!" << endl;
				return;
			}
			answerz = numbery / numberx;
		}
		//cout << "go " << numbery << Operator << numberx << '=' << answerz << endl;
		numberstack.push(answerz);
	}

	int get()
	{	
		while(tem < readin.size())
		{
			temnumber = 0;
			while(tem < readin.size() && (readin[tem] > '9' || readin[tem] < '0'))
			{
				temoperator = readin[tem];//����������������ջ��
				tem++;
				if(temoperator == '=')
					return 3;//������
				else
				{
					return 1;//�����1
				}
			}
			if(readin[tem] <= '9' && readin[tem] >= '0')
			{
				while(readin[tem] <= '9' && readin[tem] >= '0' && tem < readin.size())
				{
					temnumber = temnumber*10+(readin[tem] -'0');//�����ִ�������ջ��
					tem++;
				}
				return 2;//��2
			}
		}
		return 0;//����0
	}

};

int main()
{
	ifstream in("expr.in");
	ofstream out("expr.out");
	string readin;
	in >> readin;

	calculateMachine test(readin);
	test.operation();
	

	out << test.print() << endl;
	in.close();
	out.close();
	
	return 0;
}