#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <stack>
using namespace std;
typedef long long LL;
const int SIZE=1010;
char str[SIZE];
stack<char> OPTR;
stack<LL> OPND;
inline int get_priority(char ch) {
    switch (ch) {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case ')':
        return 3;
    }
}
inline LL calc() {
    LL b=OPND.top(); OPND.pop();
    LL a=OPND.top(); OPND.pop();
    char ch=OPTR.top(); OPTR.pop();
    switch (ch) {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
}
int main() {
    cin>>str;
    int priority_top,priority_cur;
    LL x;
    int i=0,len=strlen(str)-1;
    while (i<len) {
        if (isdigit(str[i])) {
            x=0;
            while (i<len && isdigit(str[i])) {
                x=x*10+str[i]-'0';
                i++;
            }
            OPND.push(x);
        }
        else {
            if (OPTR.empty()) {
                OPTR.push(str[i]);
                i++;
                continue;
            }
            priority_top=get_priority(OPTR.top());
            priority_cur=get_priority(str[i]);
            if (priority_cur==0) {
                OPTR.push(str[i]);
                i++;
            }
            else if (priority_cur==3) {
                while (OPTR.top()!='(') {
                    x=calc();
                    OPND.push(x);
                }
                OPTR.pop();
                i++;
            }
            else {
                while (!OPTR.empty() && priority_cur<=priority_top) {
                    x=calc();
                    OPND.push(x);
                    if (!OPTR.empty()) priority_top=get_priority(OPTR.top());
                }
                OPTR.push(str[i]);
                i++;
            }
        }
    }
    while (!OPTR.empty()) {
        x=calc();
        OPND.push(x);
    }
    cout<<OPND.top()<<endl;
    return 0;
}
