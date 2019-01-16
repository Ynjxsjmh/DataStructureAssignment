#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int>num, ope;
char ch[10000];

int Priority(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

void Calc() {
    int x = num.top(); num.pop();
    int y = num.top(); num.pop();
    char c = ope.top(); ope.pop();
    if(c == '+') num.push(x + y);
    else if(c == '-') num.push(y - x);
    else if(c == '*') num.push(x * y);
    else num.push(y / x);
}

int main() {
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    scanf("%s", ch);
    int i = 0;
    while(ch[i]) {
        if(ch[i] >= '0' && ch[i] <= '9') {
            int a = 0;
            while(ch[i] >= '0' && ch[i] <= '9') {
                a = a * 10 + ch[i] - '0', i++;
            }
            num.push(a);
        }
        if(ch[i] == '(') ope.push('(');
        else if(ch[i] == ')' || ch[i] == '=') {
            while(!ope.empty() && ope.top() != '(') Calc();
            if(!ope.empty()) ope.pop();
        } else {
            while(!ope.empty() && Priority(ch[i]) <= Priority(ope.top())) Calc();
            ope.push(ch[i]);
        }
        i++;
    }
    printf("%d\n", num.top());
}
