#include <iostream> 
#include <cstdio>
using namespace std;  
  
const int maxlen = 1000;                          //栈的最大存储量  
  
template <typename T>  
class stack 
{  
public:  
    stack();                                  //初始化函数  
    int  isempty();                          //判断空栈
    int  isfull();                          //判断满栈  
    int  peek(T &x);                       //取栈顶元素  
    int  push(T x);                       //元素入栈  
    int  pop();                          //删除栈顶  
private:  
    int count;                         //元素的计数器  
    T data[maxlen];                   //顺序存储结构  
};  
  
template <typename T>  
stack<T>::stack() 
{  
    count = 0;  
}  
  
template <typename T>  
int stack<T>::isempty() 
{  
    if (count == 0)  
        return 1;  
    return 0;  
}  
  
template <typename T>  
int stack<T>::isfull() 
{  
    if (count == maxlen)  
        return 1;  
    return 0;  
}  
  
template <typename T>  
int stack<T>::peek(T &x) 
{  
    if (!isempty()) 
    {  
        x = data[count - 1];  
        return 1;  
    }  
    return 0;  
}  
  
template <typename T>  
int stack<T>::push(T x) 
{  
    if (!isfull()) 
    {  
        data[count++] = x;  
        return 1;  
    }  
    return 0;  
}  
  
template <typename T>  
int stack<T>::pop() 
{  
    if (!isempty()) 
    {  
        count--;  
        return 1;  
    }  
    return 0;  
}  



//扫描数字的函数  
int judge(char x) {  
    if ('0' <= x && x <= '9')  
        return 1;  
    return 0;  
}  
  
//判断运算符优先级的函数  
int dj(char x) {  
    if (x == '+' || x == '-')  
        return 1;  
    else if (x == '*' || x == '/')  
        return 2;  
    else if (x == '(' || x == ')')  
        return 0;  
    else if (x == '#'||x=='=')  
        return -1;  
}  
  
int calculate(string s) 
{  
    stack<int> num;  
    stack<char> c;  
    char top;  
    int a , b;  
    for ( int i = 0; i < s.size() ; ++i) 
    {  
        if (judge(s[i]) ) 
        {  
            int Temp = 0;  
            string temp;  
            temp += s[i];  
            while ( judge(s[++i]) )  
                temp += s[i];  
            for ( int j = 0; j < temp.size(); ++j)
            {  
                Temp = Temp * 10 + temp[j] - 48;  
            }  
            num.push(Temp);  
            temp.clear();  
        }                                  
        if (!isnumber(s[i])) 
        {  
            if ( c.isempty() )   //加入‘#’来代替栈底
            {  
                c.push( '#' );
                c.push( s[i] );
            }                             
            else 
            {  
                c.peek( top );  
                if (dj( s[i] )>dj( top ) || s[i] == '(') 
                {  
                    c.push( s[i] );  
                } 
                else {  
                    while (dj( s[i] ) <= dj( top )) 
                    {  
                        if (top == '#'&&s[i] == '=') 
                        {  
                            int answer;  
                            c.pop();  
                            num.peek(answer);  
                            cout  << answer << endl;  
                            num.pop();  
                            return 0;  
                        }
                        else if (top == '('&&s[i] == ')') 
                        {  
                            ++i;  
                        }  
                        else 
                        {  
                            num.peek(a);  
                            num.pop();  
                            num.peek(b);  
                            num.pop();  
                        }  
                        if (top == '+') 
                        {  
                            b += a;  
                            num.push(b);  
                        }  
                        else if (top == '-')
                        {  
                            b -= a;  
                            num.push(b);  
                        }  
                        else if (top == '*') 
                        {  
                            b *= a;  
                            num.push(b);  
                        }  
                        else if (top == '/') 
                        {  
                            b /= a;  
                            num.push(b);  
                        }  
                        c.pop();  
                        c.peek(top);            
                     }                                
                    c.push(s[i]);                
                }  
            }  
        }
    }
}

int main() 
{  
    string expression;
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    while(cin>>expression)
    {
        calculate(expression);
    }  
    return 0;
}  
