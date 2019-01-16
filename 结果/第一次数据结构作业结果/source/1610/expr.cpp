#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <cstdlib>

using namespace std;

stack<double> s;
stack<string> s2;

inline int precedence(string op1, string op2) {
    if (op1 == "(") {
        return -1;
    } else if (op1 == "+" || op1 == "-") {
        if (op2 == "*" || op2 == "/") {
            return -1;
        } else {
            return 0;
        }
    } else if (op1 == "*" || op1 == "/") {
        if (op2 == "+" || op2 == "-") {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

inline bool isNumber(string ch){
    return ch != "+" && ch != "-" && ch != "*" && ch != "/" && ch != "(" && ch != ")";
}

inline bool isNumber(char ch){
    return '0' <= ch && ch <= '9';
}

inline bool isBinaryOperator(string ch) {
    return ch == "+" || ch == "-" || ch == "*" || ch == "/";
}
inline bool isDifferentType(char a, char b) {
    if (!isNumber(b)) {
        return true;
    } else {
        return !isNumber(a);
    }
}

string transform(string line) {
    string line2;
    string ch;
    stringstream ss(line);
    while (ss >> ch) {
        if (ch == "(") {
            s2.push(ch);
        } else if (ch == ")") {
            while (s2.top() != "(") {
                line2 += s2.top() + " ";
                s2.pop();
            }
            s2.pop();
        } else if (isNumber(ch)){
            s2.push(ch);
        } else {
            while (!s2.empty() && precedence(s2.top(), ch) >= 0) {
                line2 += s2.top() + " ";
                s2.pop();
            }
            s2.push(ch);
        }
    }
    while(!s2.empty()){
        line2 += s2.top() + " ";
        s2.pop();
    }
    return line2;
}

double calculate(string line) {
    string ch;
    stringstream ss(line);
    double op1, op2, ans = 0;
    while (ss >> ch) {
        if (isBinaryOperator(ch)) {
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            if (ch == "+") {
                ans = op1 + op2;
            } else if (ch == "-") {
                ans = op1 - op2;
            } else if (ch == "*") {
                ans = op1 * op2;
            } else if (ch == "/") {
                ans = op1 / op2;
            }
            s.push(ans);
        }else {
            s.push(atof(ch.c_str()));
        }
    }
    ans = s.top();
    s.pop();
    return ans;
}

int main() {
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    string line;
    getline(cin, line, '=');
    for (int i = 0; i < line.length() - 1; ++i) {
        if (isDifferentType(line[i], line[i+1])) {
            line.insert((unsigned long long int) i+1, " ");
            i++;
        }
    }
    line = transform(line);
    cout << (int) calculate(line);
    return 0;
}
