#include<iostream>
using namespace std;
ifstream fin("lottery.in");
ofstream fout("lottery.out");
int main (void){
	int Count(int *);
	 void judge(int ,int *);
	int prize[7];
	int count[7];
	int m,n;
	int z;
	for(n=0;n<=6;n++){
		count[n]=0;
	}
	int i,j=1;
	int a[7];
	scanf("%d",&i);
	for(m=0;m<=6;m++){
	cin>>prize[m];
    }

	while(j<=i){
	z=Count(prize);
	if(z!=0){
	count[7-z]=count[7-z]+1;}
	j++;	
    }

    for(m=0;m<=6;m++){

    cout<<count[m];
	printf(" ")	;}

    return 0;
}
int Count(int *prize){
	int gukehaoma[7];
	int i,j,count_1;
	int m;
	for(m=0;m<=6;m++){
	cin>>gukehaoma[m];
	}
	for(i=0;i<=6;i++){
		for(j=0;j<=6;j++){
			if(gukehaoma[i]==prize[j])
				count_1++;
		}
		
	}
	return count_1;
}
void judge(int a,int * result){
   result[7-a]=result[7-a]+1;
}


