#include <stdio.h>
#include <string.h>
#include <math.h>
#define MaxSize 1000
long long Num[MaxSize];
char Operator[MaxSize];
int numIndex = 0;
int opeIndex = 0;
char in[MaxSize];

void PushNum(long long x){
	Num[numIndex++] = x;
}

void PushOpe(char x){
	Operator[opeIndex++] = x;
}

long long PopNum(){
	return Num[--numIndex];
}

char PopOpe(){
	return Operator[--opeIndex];
}

int Level(char x){
    switch(x){
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case '(':return 0;
        case ')':return 0;
        case '=':return 0;
        default :return 0;
    }
}

void Calculate(){
	if(numIndex == 1)return;
	long long a, b;
	b = PopNum();
	a = PopNum();
	char op = PopOpe();
	switch(op){
		case '+':PushNum(a + b);break;
		case '-':PushNum(a - b);break;
		case '*':PushNum(a * b);break;
		case '/':PushNum(a / b);break;
	}
	return;
}

void Process(){
	for(int i = 0; i < strlen(in) - 1; i++){
		long long temp = 0;
		if(in[i] == '=')break;
		if(in[i] >= '0' && in[i] <= '9'){
			do{
				temp = temp * 10 + in[i++] - '0';
				if(!(in[i] >= '0' && in[i] <= '9')){
					PushNum(temp);
					break;
				}
			}while(1);
		}
		if(in[i] == '=')break;
		if(in[i] == ')'){
			while(Operator[opeIndex - 1] != '('){
				Calculate();
			}
			PopOpe();
		}
		else if(in[i] == '('){
			PushOpe(in[i]);
		}
		else if(Level(in[i]) < Level(Operator[opeIndex - 1])){
			Calculate();
			PushOpe(in[i]);
		}
		else{
			PushOpe(in[i]);
		}
	}
	while(numIndex > 1 || opeIndex > 0){
		Calculate();
	}
	return;
}

int main(void){
	FILE *fpin, *fpout;
	fpin = fopen("expr.in","r");
	if(!feof(fpin)){
		fgets(in,1005,fpin);
	}

	Process();

	fclose(fpin);
	fpout = fopen("expr.out","w");
	fprintf(fpout,"%I64d",Num[0]);
	fclose(fpout);
}
