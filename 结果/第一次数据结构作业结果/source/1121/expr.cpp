# include<stdio.h>
# include<stdlib.h>
# include<iostream>
# include<iomanip>
# include<stack>
# include<string>
//# include<fstream>
using namespace std;
float calculate(char *);
float compute(float,float,char);
int main(void)
{
	int i,c;
	float s;
	char b[1000];
	//string a;
	char a[1000];
	char *p;
	p=a;
	FILE *fp;
	printf("�����Ƿ���ļ�¼�룬������ 1��������2\n");
	cin>>c;
	if(c==1)
    {
        if((fp=fopen("expr.in.txt","r"))==NULL)
        {
            printf("�ļ��޷���\n");
        }
//while(!feof(fp))
//		{
			 	 fscanf(fp,"%s",a);
            cout<<a;
  // ifstream fin("exprin.txt");
        //ofstream fout("exprout.txt");
        //getline(fin,a);
        s=calculate(a);
        cout<<s;
        if((fp=fopen("expr.out.txt","a+"))==NULL)
        {
        	printf("�Բ����޷����ļ�\n");
		}
        fprintf(fp,"%f",s);
//		fscanf(fp,"\n");
//		}
    }
    else{
	do{

	 printf("                                                                                                      \n");
		    printf("                                                                                                      \n");
            printf("                                             ������  ���׼�����  ������                                                              \n");
		    printf("         ************************************************************************************************\n");
	        printf("         **                                                                                            **\n");
	        printf("         **         * *      *      *        * *  *     * *          *     ******   * *   * * *        **\n");
	        printf("         **       *         * *     *      *      *     * *         * *       *    *   *  *    *       **\n");
	        printf("         **       *        *   *    *      *      *     * *        *   *      *    *   *  *  *         **\n");
	        printf("         **       *       * * * *   *      *      *     * *       * * * *     *    *   *  *  *         **\n");
	        printf("         **         * *  *       *  ******   * *    * *   ****** *       *    *     * *   *    *       **\n");
          	printf("         **                                                                                            **\n");
	        printf("         ************************************************************************************************\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                             please input expression E��press the Enter will get the result                                                  \n");
			printf("\n");
			printf("\n");
			printf("                             ");

//	char a[1000];
	cin>>a;
	if((fp=fopen("exprout.txt","a+"))==NULL)
    {
        printf("���ļ��޷���\n");
    }
    fprintf(fp,"%s",a);
	s=calculate(a);
	fprintf(fp,"%f",s);
	fprintf(fp,"\n");
	fclose(fp);
	printf("                                                     %.1f\n",s);
	printf("\n");printf("\n");
	printf("                                     continue compute��yes press 1��no press any key         \n");
	cin>>i;
	system("cls");
	}while(i==1);}
	printf("\n");
	printf("\n");
	printf("                                               ллʹ�ã�\n");
	printf("\n");
	printf("\n");
	return 0;
}
float calculate(char *p)
{
	float result,num1,num2;
	char opreate;
	int i=0;
	int x;
	char c[10];//����һ���ַ�����洢���������� ���ں�������string����ȥֱ��ת��Ϊ����
	stack<float> s;
	stack<char> t;
	while(*p!='=')
	{
	//	cout<<*p<<"\n";
		if((*p>='0')&&(*p<='9'))
		{
		//	cout<<(*p)<<"\n";;
			c[i]=*p;p++;//cout<<(*p);
			while((*p>='0')&&(*p<='9'))
			{
				i++;c[i]=*p;
				p++;
			}
			c[i+1]='\0';
			x=atoi(c);
			s.push(x);
			c[0]='\0';
			i=0;

		}
		if((*p=='+')||(*p=='-')||(*p=='*')||(*p=='/'))
		{

			if(t.empty())
			{//cout<<"����\n";

				t.push(*p);
				p++;
			}
			else
			{
			//	cout<<"����hhhh\n";
				while(((*p=='+')||(*p=='-')))
				{
					if(t.top()=='(')
					{
						t.push(*p);
						p++;
						break;
					}
					num1=s.top();s.pop();
					num2=s.top();s.pop();
					opreate=t.top();t.pop();
					result=compute(num1,num2,opreate);
					s.push(result);
					if(t.empty())
					{
						t.push(*p);
						p++;
					}
				}
				while(((*p=='*')||(*p=='/')))
				{

					if(t.top()=='(')
					{
						t.push(*p);
						p++;
						break;
					}
					if((t.top()=='*')||(t.top()=='/'))
					{
						num1=s.top();s.pop();
						num2=s.top();s.pop();
						opreate=t.top();t.pop();
						result=compute(num1,num2,opreate);
						s.push(result);
					}
					if((t.top()=='+')||(t.top()=='-'))
					{
						t.push(*p);
						p++;break;
					}
					if(t.empty())
					{//cout<<*p<<"ha\n";
						t.push(*p);
						p++;
					}
				}

			}
		}
		if(*p=='(')
				{
					t.push(*p);
					p++;
				//	cout<<"�ٺ�\n";
				}
		if(*p==')')
				{
			//	cout<<"heihei\n";
				    while((*p==')')&&(t.top()!='('))
					{
					    num1=s.top();s.pop();
						num2=s.top();s.pop();
						opreate=t.top();t.pop();
						result=compute(num1,num2,opreate);
						s.push(result);
					}
					t.pop();p++;
				}
		//
	}
	while(1)
	{
	//	cout<<t.top()<<"\n";
	    num1=s.top();s.pop();
		num2=s.top();s.pop();
	    opreate=t.top();t.pop();
		result=compute(num1,num2,opreate);
		//cout<<result<<"\n";
		s.push(result);
		if(t.empty())
			break;
	}
	return s.top();
}
float compute(float num1,float num2,char opreate)
{
	//cout<<opreate;
	if(opreate=='+')
		return (num1+num2);
	else if(opreate=='-')
		return (num2-num1);
	else if(opreate=='*')
		return (num1*num2);
	else if(opreate=='/')
		return ((num2*1.0)/num1);
	else
		cout<<"����Ĳ���������\n";
}

