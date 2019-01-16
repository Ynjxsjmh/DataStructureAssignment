
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct stack ASTACK;
typedef struct stack * DSTACK;
int compare(char, char);
int cal(int, char, int);
struct stack {
	char num[1000];
	int top;
	stack() { top = -1; }
	void push(char x) { num[++top] = x; }
	char front() { return num[top]; }
	void pop() { top--; }

};
int main()
{
	ASTACK s, m;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char y1, y2;
	char a, b;
	int jishu = 0;
	char cha[1000];
	int weishu[1000] = { 0 };//因为char数组中不能记录两位数即更大的数，所以用位数记录几位数
	scanf("%s", cha);
	int i;
	int def;
	for (i = 0; cha[i] != '='; i++)
	{
		if (cha[i] >= '0'&&cha[i] <= '9')
		{
			while (cha[i] >= '0'&&cha[i] <= '9')
			{
				s.push(cha[i]);
				weishu[jishu]++;
				i++;
			}
			jishu++;
			i--;
		}
		else
		{
			int judge = 0;
			if (m.top == -1)
				judge = 1;
			if (!judge)
			{
				a = m.front();
				judge = compare(a, cha[i]);
			}
		qqq:if (judge == 0)//改
		{
			b = cha[i];

			def = 1;
			while (1)//有问题1+8*(2-4*2)-3=因该如果读入的是（，则不计入
			{
				i++;
				if (cha[i] >= '0'&&cha[i] <= '9'&&def)
				{
					while (cha[i] >= '0'&&cha[i] <= '9')
					{
						s.push(cha[i]);
						i++;
						weishu[jishu]++;
					}
					i--;
					jishu++;
					break;
				}

				else
				{
					m.push(b);
					m.push(cha[i]);
					def = 0;
				}
				if (!def)
					break;

			}
			if (def)
			{
				s.push(b);
			}
		}
			if (judge == 1)//不用改
			{
				m.push(cha[i]);
			}
			if (judge == 2)//改
			{
				b = m.front(); m.pop();
				while (b != '(') {
					s.push(b);
					b = m.front(); m.pop();
				}
				if (m.top >= 0 && cha[i + 1] != '=')
				{
					i++;
					a = m.front();
					judge = compare(a, cha[i]);
					goto qqq;

				}
				if (cha[i + 1] == '=')
				{
					while (m.top + 1)
					{
						b = m.front(); m.pop();
						s.push(b);

					}
				}
				//i--;
			}
			if (judge == 3)//改
			{
				s.push(a); m.pop();
				m.push(cha[i]);//
			}
			if (judge == 4)
			{

			}
		}
	}
	char h;
	int qwe = 0;;
	while (m.top != -1)
	{
		h = m.front(); m.pop();
		s.push(h);
	}
	//printf("%s\n", s.num);
	int cout, h1, h2;
	int qwe1, qwe2;
	char q1, q2, q3;
	int e1, e2, e3, e4, e5;
	int l, r, t = 0;
	char  shuzi[10];
	cout = jishu;
	h2 = s.top + 1;
	char number;
	int pre;
	while (weishu[1] != 0)
	{
		t = 0;
		qwe = 0;
		qwe1 = 0; qwe2 = 0;
		r = weishu[0];
		e1 = 0; e2 = 0;
		i = 0;
		l = 0;
		if (r<0)
			r = r*(-1);

		while (l <= cout)
		{
			if (weishu[l + 1]<0)
				r = (-1 * weishu[l + 1]) + r;
			else
				r = weishu[l + 1] + r;
			if (s.num[r] >= '0'&&s.num[r] <= '9')//649*8378*89746*-+*1724474658/-+-+//6*49*(8*378+8-974*6)+17-2+44-74/658=
				l++;
			else
			{
				break;
			}

		}
		e4 = l - 1;
		while (e4 >= 0)
		{
			if (weishu[e4] >= 0)
			{
				i = i + weishu[e4];
				e4--;
			}
			else
			{
				i = i - weishu[e4];
				e4--;
			}
		}
		int numb;
		numb = i;
		if (weishu[l] >= 0 && weishu[l + 1] >= 0)
			pre = weishu[l] + weishu[l + 1];
		else
		{
			if (weishu[l] >= 0 && weishu[l + 1]<0)
				pre = weishu[l] - weishu[l + 1];
			else
			{
				if (weishu[l]<0 && weishu[l + 1] >= 0)
					pre = weishu[l + 1] - weishu[l];
				else
					pre = -1 * weishu[l + 1] - weishu[l];//(1-2334)+15+44/2=

			}
		}
		if (weishu[l]<0)
		{
			weishu[l] = -1 * weishu[l];
			qwe1 = 1;
		}
		if (weishu[l + 1]<0)
		{
			weishu[l + 1] = -1 * weishu[l + 1];
			qwe2 = 1;
		}
		while (weishu[l]--)
		{
			e1 = s.num[i] - 48 + 10 * e1;
			i++;
		}
		while (weishu[l + 1]--)
		{
			e2 = s.num[i] - 48 + 10 * e2;
			i++;
		}
		if (qwe1)
			e1 = -1 * e1;
		if (qwe2)
			e2 = -1 * e2;
		e5 = cal(e1, s.num[r], e2);
		//将e5转化为字符存储；计算
		if (e5<0)
		{
			qwe = 1;
			e5 = (-1)*e5;
		}
		while ((e5 / 10) != 0)
		{
			shuzi[t++] = e5 % 10 + 48;
			e5 = e5 / 10;
		}
		shuzi[t++] = e5 + 48;//未完成，给字符串重新赋值没有做
		int hhh;
		hhh = pre + 1 - t;
		weishu[l] = t;
		if (qwe)
			weishu[l] = -1 * t;
		int kkk;
		for (kkk = l + 1; kkk <= cout - 1; kkk++)
		{
			weishu[kkk] = weishu[kkk + 1];
		}

		cout--;
		while (t)
		{
			s.num[numb] = shuzi[t - 1];
			numb++;
			t--;
		}
		for (kkk = numb; kkk <= h2 - hhh + 1; kkk++)
			s.num[kkk] = s.num[kkk + hhh];
		h2 = h2 - hhh;
	}
	int u = 0, v = 0, qwe3 = 0;
	if (weishu[0]<0)
	{
		qwe3 = 1;
		weishu[0] = -1 * weishu[0];
	}
	while (weishu[0]--)
		u = 10 * u + (s.num[v++] - 48);
	if (qwe3)
		u = -1 * u;
	printf("%d", u);
	fclose(stdin);
    fclose(stdout);
	return 0;

}
int compare(char x1, char x2) {
	int m;
	if (x1 == '(' || x2 == '(')
		m = 1;
	if (x1 == '+' || x1 == '-')
	{
		if (x2 == '*' || x2 == '/')
			m = 0;
		if (x2 == '+' || x2 == '-')
			m = 3;//
	}
	if (x1 == '*' || x1 == '/')
	{
		if (x2 == '-' || x2 == '+')
			m = 3;
		if (x2 == '*' || x2 == '/')
			m = 3;
	}
	if (x2 == ')')
		m = 2;
	return m;
}
int cal(int a1, char a2, int a3) {
	int z3 = 0;
	if (a2 == '+')
		z3 = a1 + a3;
	if (a2 == '-')
		z3 = a1 - a3;
	if (a2 == '*')
		z3 = a1*a3;
	if (a2 == '/')
		z3 = a1 / a3;
	return z3;
}


