#include<stdio.h>

//a stack that use to store numbers
struct stackn{
	int number[1000];
	int top;
	stackn(){top = -1;}
	int seek(void){return number[top];}
	void push(int k){number[++top]=k;return;}
	int pop(void){return number[top--];}
	void cl(void){top=-1;return;}
};
//a stack that use to store operators
struct stackc{
	int operators[1000];
	int top;
	stackc(){top = -1;}
	int seek(void){return operators[top];}
	void push(int k){operators[++top]=k;return;}
	int pop(void){return operators[top--];}
	void cl(void){top=-1;return;}
};
stackn num;              //number stack
stackc ope;              //operator stack

//when input a number and the operator before is * or /, we can do it at once
int doatonce(int n){
	char o = ope.pop();
	int nb = num.pop();
	if(o == '*')
		return nb * n;
	else
		return nb / n;
}

//do one operation
int doone(int n){
	char o = ope.pop();
	int nb = num.pop();
	if(o == '+')
		return nb + n;
	else
		return nb - n;
}

//do all the operations in the ( and )
int doblock(void){
	int n = num.pop();
	while(ope.seek() != '(')
		n = doone(n);
	ope.pop();
	return n;
}

//do all the operations
int dotoend(){
	int n = num.pop();
	while(num.top != -1)
		n = doone(n);
	return n;
}

//calculate one line
int cal(char a[1001]){
	int point = 0;
	ope.cl(); num.cl();
	while(a[point] != '='){
		if(a[point] >= '0' && a[point] <= '9'){
			int n = a[point++] - '0';
			while(a[point] >= '0' && a[point] <= '9')
				n = n * 10 + a[point++] - '0';
			if(ope.top != -1 &&(ope.seek() == '*' || ope.seek() == '/'))
				num.push(doatonce(n));
			else
				num.push(n);
		}else{
			if(a[point] == ')'){
				int n = doblock();
				if(ope.top != -1 &&(ope.seek() == '*' || ope.seek() == '/'))
					num.push(doatonce(n));
				else
					num.push(n);
				point++;
			}else{
				if(a[point] != ' ')
					ope.push(a[point++]);
				else
					point++;
			}
		}
	}
	return dotoend();
}

void calculate(FILE *in, FILE *out){
	char a[1001];
	int r;
	fgets(a, 1001, in);
	if(a[1]=='\0')return;
	r = cal(a);
	fprintf(out, "%d\n", r);
	return;
}

int main()
{
	FILE *in, *out;
	in = fopen("expr.in", "a+");
	fprintf(in, "\n");
	fclose(in);
	in = fopen("expr.in", "r");
	out = fopen("expr.out", "w");
	while(!feof(in))
		calculate(in, out);
	fclose(in);
	fclose(out);
	return 0;
}
