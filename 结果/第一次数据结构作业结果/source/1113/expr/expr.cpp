#include <cstdio>
#include <cmath>
const int maxlen = 1024;
//------------------------------------------------------------------------------
/*读取字符数组，暂时用不上*/
void getstring(char a[])
{
	scanf("%s",a);
}
//------------------------------------------------------------------------------
/*读取运算符符号进行相应运算*/
int docal(char a,int right,int left)
{
	switch(a)
	{
		case 42 :return left*right;
		case 43 :return left+right;
		case 45 :return left-right;
		case 47 :return left/right;
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------------
/*从字符数组中读取完整的数字*/
void getnum(char** p,int* num)
{
	int n[20],count = 0,sum = 0;
	while((**p) != '\0'&&(**p) != '+' && (**p) != '-' &&(**p) != '*' &&(**p) != '/'&&(**p) != '('&&(**p) != ')'&&(**p) != '=')
	{
		switch(**p)
		{
			//0~9
			case 48 :n[count++] = 0;break;
			case 49 :n[count++] = 1;break;
			case 50 :n[count++] = 2;break;
			case 51 :n[count++] = 3;break;
			case 52 :n[count++] = 4;break;
			case 53 :n[count++] = 5;break;
			case 54 :n[count++] = 6;break;
			case 55 :n[count++] = 7;break;
			case 56 :n[count++] = 8;break;
			case 57 :n[count++] = 9;break;
		}
		(*p)++;
	}
	(*p)--;
	count--;
	for(int i = count;i>=0;i--)
	{
		sum += n[i]*pow(10,count-i);
	}
	*num = sum;
}
//------------------------------------------------------------------------------------------------------------
int cal(char a[])
{
	int num[maxlen];
	char op[maxlen];
	int topn = -1;
	int topo = -1;
	char *p = a;
	int result = 0;
	while(*p != '\0')
	{
		switch(*p)
		{


		    //'='
		    case 61 : break;


			//0~9
			case 48 :
			case 49 :
			case 50 :
			case 51 :
			case 52 :
			case 53 :
			case 54 :
			case 55 :
			case 56 :
			case 57 :getnum(&p,&num[++topn]);break;


            //'('
			case 40 :op[++topo] = '(';break;


            //')'
			case 41 :while(op[topo] != '(')
				 {
					 num[topn] = docal(op[topo--],num[topn--],num[topn-1]);
				 }
				 topo--;
				 break;


            // '+'
			case 43 :
				 if(topo == -1||op[topo] == '(')
				 {
					 op[++topo] = '+';break;
				 }
				 else
				 {
					num[topn] =  docal(op[topo],num[topn--],num[topn-1]);
					op[topo] = '+';
					break;
				 }


			//'-'
			case 45 :
				 if(topo == -1||op[topo] == '(')
				 {
					 op[++topo] = '-';break;
				 }
				 else
				 {
					 num[topn] = docal(op[topo],num[topn--],num[topn-1]);
					 op[topo] = '-';
					 break;
				 }


            //'/'
			case 47 :
			    if(topo == -1||op[topo] == '+' ||op[topo] == '-'||op[topo] == '(')
				 {
					 op[++topo] = '/';break;
				 }
				 else
				 {
					 num[topn] = docal(op[topo],num[topn--],num[topn-1]);
					 op[topo] = '/';
					 break;
				 }


			//'*'
			case 42 :
			    if(topo == -1||op[topo] == '+' ||op[topo] == '-' ||op[topo] == '(')
				 {
					 op[++topo] = '*';break;
				 }
				 else
				 {
					 num[topn] = docal(op[topo],num[topn--],num[topn-1]);
					 op[topo] = '*';
					 break;
				 }


		}
		p++;
	}
	while(topo != -1)
	{
		num[topn] = docal(op[topo--],num[topn--],num[topn-1]);
	}
	result = num[0];
	return result;
}
//---------------------------------------------------------------------------------------------------







//-----------------------------------------------------------------------------------------------------
int main()
{
    FILE*in;
    FILE*out;
    in = fopen("expr.in","r");
    out = fopen("expr.out","w");
    char fur[10000];
    while((fscanf(in,"%s",fur)) != EOF)
    {
        fprintf(out,"%d\n",cal(fur));
    }
	fclose(in);
	fclose(out);
	return 0;
}
//不知为何在函数执行参数传递时好像不是从左到右执行的
