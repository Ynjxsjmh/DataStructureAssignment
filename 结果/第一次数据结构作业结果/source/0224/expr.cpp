#include <iostream>
#include <stack>
using namespace std;

long long calculate(long long operator1, long long operator2, char operand)
{
	long long ans;
	switch(operand) {
		case '+' : 
			ans = operator1 + operator2;
			break;
		case '-' :
			ans = operator1 - operator2;
			break;
		case '*' :
			ans = operator1 * operator2;
			break;
		case '/' :
			ans = operator1 / operator2;
			break;
		case '%' :
			ans = operator1 % operator2;
			break; 
	}
	return ans;
}
long long doCalculate(stack<long long> &sNum, stack<char> &sOperator)
{
	long long operator1 = sNum.top(); sNum.pop();
	long long operator2 = sNum.top(); sNum.pop();
	char operand = sOperator.top(); sOperator.pop();
	return calculate(operator2, operator1, operand);
}
bool isNum(char c)
{
	if (c <= '9' && c >= '0') return true;
	else return false;
}
bool isOperand(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '(' || c == ')' || c == '=') return true;
	else return false;
}
bool isValid(char c)
{
	if (isOperand(c) || isNum(c)) return true;
	else return false;
}
int getWeigh(char c) 
{
	if (c == '(') return 3;
	if (c == '+' || c == '-') return 1;
	if (c == '/' || c == '*' || c == '%') return 2;
}
int getWeigh(stack<char> &sOperator) 
{
	if (sOperator.top() == '(') return 0;
	if (sOperator.top() == '+' || sOperator.top() == '-') return 1;
	if (sOperator.top() == '/' || sOperator.top() == '*' || sOperator.top() == '%') 
		return 2;
}
int main()
{
	char c;
	long long num = 0;
	int isLastNum = 0;
	stack<long long> sNum;
	stack<char> sOperand;
	while (~scanf("%c",&c)) {
//		cout << c ;
		if (isNum(c)) {
			num = num * 10 + (c - '0');
			isLastNum = 1;
		}
		if (isOperand(c)) {
			if (isLastNum) {
				sNum.push(num);
				num = 0;
			} 
			isLastNum = 0;
			if (c == '=') {
//				while (!sOperand.empty()) {
//					cout << sOperand.top();
//					sOperand.pop();
//				} 
//				cout << endl;
//				while (!sNum.empty()) {
//					cout << sNum.top() << " ";
//					sNum.pop();
//				}
				while (!sOperand.empty()) {
					sNum.push(doCalculate(sNum, sOperand));
				}
				break;
			} else if (c == ')') {
				while (!sOperand.empty() && sOperand.top() != '(') {
					sNum.push(doCalculate(sNum, sOperand));
				}
				sOperand.pop();
			} else {
				int weighNow = getWeigh(c);
				while (!sOperand.empty() && weighNow <= getWeigh(sOperand)) {
					sNum.push(doCalculate(sNum, sOperand));
				}
				sOperand.push(c);
			}
		}
	}
	printf("%lld\n",sNum.top());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
