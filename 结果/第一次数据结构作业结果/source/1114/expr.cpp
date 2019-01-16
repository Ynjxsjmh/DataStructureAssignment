#include<stack>
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

void Input(string &s)
{
    ifstream in("expr.in");
    for(;getline(in,s);){}
}
int compare(const stack<char> &sc, char l)
{
    if(sc.empty() || (sc.top() == '(' && l != ')') || l == '(')
        return 0;
    if((sc.top() == '-'||sc.top() == '+')&&(l == '*'||l == '/'))
        return 0;
    else if(sc.top() == '(' && l == ')')
        return 1;
    else
        return 2;
}
void chuli(stack<char> &sc, stack<int> &si)
{
    int n1 = si.top();
    si.pop();
    int n2 = si.top();
    si.pop();
    char top = sc.top();
    sc.pop();
    if(top == '+')
        si.push(n1 + n2);
    if(top == '-')
        si.push(n1 - n2);
    if(top == '*')
        si.push(n1 * n2);
    if(top == '/')
        si.push(n2 / n1);
}
int main()
{
    stack<int> si;
    stack<char> sc;
    string s;
    char l[1000];
    Input(s);
    strcpy(l,s.c_str());
    int len = strlen(l);
    l[len] = '\0';
    char dest[1024];
    char *temp;
    int i = 0;
    do
    {
        temp = dest;
        while(l[i] >= '0' && l[i] <= '9')
        {
            *temp = l[i];
            i++;
            temp++;
        }
        if(temp != dest)
        {
            *temp = '\0';
            int n = atoi(dest);
            si.push(n);
        }

        else
        {
            while(1)
            {

                int cc = compare(sc,l[i]);

                if(cc == 0)
                {
                    sc.push(l[i]);
                    i++;
                    break;
                }
                if(cc == 1)
                {
                    sc.pop();
                    i++;
                }
                if(cc == 2)
                {
                    chuli(sc,si);
                }
            }
        }
    }while(l[i] != '\0');

    FILE * p = fopen("expr.out","w");
    fprintf(p,"%d",si.top());
}
