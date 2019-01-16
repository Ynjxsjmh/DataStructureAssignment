#include<bits/stdc++.h>
using namespace std;
const long long  M = 123456;
char s[M];
long long  a[M],b[M];//aÕ»ÊÇÊýÕ»,bÕ»ÊÇ·ûºÅÕ»
/*
 0 (
 1 +
 2 -
 3 *
 4 /
*/
long long  work(long long  A,long long  B,long long  C){
	if(C==1) return A+B;
	if(C==2) return A-B;
	if(C==3) return A*B;
	if(C==4) return A/B;
	return -1;
}
long long  cnt(long long  lim){
	while(b[b[0]]>lim){
		long long  A=a[a[0]-1];
		long long  B=a[a[0]];
		a[a[0]-1]=work(A,B,b[b[0]]);
		a[0]--;
		b[0]--;
	}
	return 0;
}


int  main(){
	freopen("espr.in","r",stdin);
	freopen("espr.out","w",stdout);

	cin>>s+1;
	long long  len=strlen(s+1);
	//printf("%s",s+1);
	a[0]=0;
	b[0]=0;
	s[0]='(',s[len]=')',s[len+1]='\0';
	long long  k=0;
	while(k<=len){
		if(s[k]>='0'&&s[k]<='9'){
			long long  num=s[k]-'0';
			while(s[k+1]>='0'&&s[k+1]<=9){
				k++;
				num=num*10+s[k]-'0';
			}
			a[++a[0]]=num;
			cnt(2);
		}
		if(s[k]=='('){
			b[++b[0]]=0;
		}
		if(s[k]==')'){
			cnt(0);
			b[0]--;
		}
		if(s[k]=='+'){
			cnt(0);
			b[++b[0]]=1;
		}
		if(s[k]=='-'){
			cnt(0);
			b[++b[0]]=2;
		}
		if(s[k]=='*'){
			b[++b[0]]=3;
		}
		if(s[k]=='/'){
			b[++b[0]]=4;
		}
		k++;
	}
	printf("%d\n",a[1]);

	return 0;
}
