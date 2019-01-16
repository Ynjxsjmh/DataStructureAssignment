#include <iostream>
#include <string.h>
#include <stack>
#include <assert.h>
using namespace std;
char lineBuffer[2000];
int prior[128];
deque<char> symbol;
deque<long> number;

void init()
{
    memset(lineBuffer,0,sizeof(lineBuffer));
    prior['+']=2;
    prior['-']=2;
    prior['*']=3;
    prior['/']=3;
    prior['(']=4;
    prior[')']=1;
    prior['=']=0;
}
void suan(int newPrior)
{
    long op1,op2;
    while((!symbol.empty())&&prior[symbol.front()]>=newPrior)
    {
        switch (symbol.front())
        {
        case '+':
            op1=number.front();
            number.pop_front();
            op2=number.front();
            number.pop_front();
            symbol.pop_front();
            number.push_front(op2+op1);
            break;
        case '-':
            op1=number.front();
            number.pop_front();
            op2=number.front();
            number.pop_front();
            symbol.pop_front();
            number.push_front(op2-op1);
            break;
        case '*':
            op1=number.front();
            number.pop_front();
            op2=number.front();
            number.pop_front();
            symbol.pop_front();
            number.push_front(op2*op1);
            break;
        case '/':
            op1=number.front();
            number.pop_front();
            op2=number.front();
            number.pop_front();
            symbol.pop_front();
            number.push_front(op2/op1);
            break;
        case '(':
            if(newPrior==prior[')'])
            symbol.pop_front();
            return;
        case ')':
            symbol.pop_front();
            return;
        default:
            //printf("搞毛啊");
            return;
        }
    }
}


int main()
{
    FILE* in=freopen("expr.in","r+",stdin);
    FILE* out=freopen("expr.out","w+",stdout);
    if (in==NULL||out==NULL)
        abort();
    init();
    fgets(lineBuffer,1500,stdin);
    long symbolBuffer;
    for (int i=0;lineBuffer[i]!='='&&lineBuffer[i]!='\0';i++)
    {
        if (lineBuffer[i]>='0'&&lineBuffer[i]<='9')
        {
            sscanf(lineBuffer+i,"%ld",&symbolBuffer);
            number.push_front(symbolBuffer);
            while(lineBuffer[i]>='0'&&lineBuffer[i]<='9') i++;
            i--;
        }
        else
        {
            if ((!symbol.empty())&&prior[symbol.front()]>=prior[lineBuffer[i]])
                suan(prior[lineBuffer[i]]);
            if (lineBuffer[i]!=')')
            symbol.push_front(lineBuffer[i]);
        }
    }
    suan(0);
    printf("%ld",number.front());
}
