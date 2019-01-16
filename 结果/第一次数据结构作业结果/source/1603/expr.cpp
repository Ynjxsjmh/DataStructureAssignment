#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<char> sym;
stack<int> num;
void _calculate(void)
{
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char _symbol = sym.top();
    sym.pop();
    if(_symbol == '+')
        num.push(b + a);
    if(_symbol == '-')
        num.push(b - a);
    if(_symbol == '*')
        num.push(b * a);
    if(_symbol == '/')
        num.push(b / a);
    return;
}
int main()
{
	FILE *putin, *putout;
	char shizi[1010];
	putin = fopen("expr.in", "r");
	putout = fopen("expr.out", "w");
    fgets(shizi, 1010, putin);
    int n = 0, ok = 0;
    for(int i = 0;i < strlen(shizi);i++)
    {
        if(shizi[i] >= '0' && shizi[i] <= '9')
        {
            n = n * 10 + shizi[i] - '0';
            ok = 1;
        }
        else
        {
            if(ok)
                num.push(n);
            n = 0;
            ok = 0;
            if(shizi[i] == '=')
                while(sym.empty() != 1)
                    _calculate();
            if(shizi[i] == '(')
                sym.push(shizi[i]);
            if(shizi[i] == ')')
            {
                while(sym.top() != '(')
                      _calculate();
                sym.pop();
            }
            if(shizi[i] == '+' || shizi[i] == '-')
            {
                while(!sym.empty() && sym.top() != '(')
                    _calculate();
                sym.push(shizi[i]);
            }
            if(shizi[i] == '*' || shizi[i] == '/')
            {
                while(sym.empty() != 1 && (sym.top() == '*' || sym.top() == '/'))
                    _calculate();
                sym.push(shizi[i]);
            }
        }
    }
    fprintf(putout, "%d\n", num.top());
    return 0;
}
