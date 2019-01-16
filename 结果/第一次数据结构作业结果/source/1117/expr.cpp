
#include "stack"
#include "iostream"
#include"string"

using namespace std;
double pan(double a,char op, double b)  {
    switch(op)
    {
        case '+':
            return
            a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
    }
    return 0;
}



int main(){
freopen("expr.in","r",stdin);
freopen("expr.out","w",stdout);

int i;
    stack<double>num;                       //计算器
    stack<char>ch;
    int len;
    string abc;
    int num1,num2;
   // cout<<"请输入表达式：";
    cin>>abc;
    len=abc.size();
    char ce;
    int k;
    int kk;
    for( i=0;i<len;i++)
    { ce=abc[i];
         kk=0;
        if(ce>='0'&&ce<='9')//num.push(ce-'0');
        {while(i<len&&ce>='0'&&ce<='9')
           {
            k=ce-'0';
            kk=kk*10+k;
            i++;
            ce=abc[i];
            }num.push(kk);
        }

       if(ch.empty())
        {ch.push(ce);
        }
        
        else
        {
        if(ce=='(')
            {ch.push(ce);
            }
          else if(ce=='*'||ce=='/')
          { if(ch.top()=='*'||ch.top()=='/')
                 {num1=num.top();
                   num.pop();
                    num2=num.top();
                      num.pop();
                      num.push(pan(num2,ch.top(),num1));
                      ch.pop();
                      ch.push(ce);
                 }
          else   ch.push(ce);
                  }
            
          else if(ce==')')
            { while(ch.top()!='(')
                { num1=num.top();
                num.pop();
                num2=num.top();
                num.pop();
                num.push(pan(num2,ch.top(),num1));
                ch.pop();
                }
                ch.pop();
            }
            else if(ce=='+'||ce=='-')
            {  if(ch.top()=='*'||ch.top()=='/'||ch.top()=='-'||ch.top()=='+')
                  {num1=num.top();
                   num.pop();
                   num2=num.top();
                   num.pop();
                   num.push(pan(num2,ch.top(),num1));
                   ch.pop();
                   ch.push(ce);
                   }
                else   ch.push(ce);
            }
        
        else if(ce=='=')
        { while(!ch.empty())
          {  num1=num.top();
            num.pop();
            num2=num.top();
            num.pop();
            num.push(pan(num2,ch.top(),num1));
            ch.pop();
          }
           cout<<num.top();
        }
      }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


