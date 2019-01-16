#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    long num;
    char l;
    int i,j,m,left,x;
    long count[7]={0};
    int cor[7];
    int now[7];
    scanf("%ld",&num);
    for(i=0;i<7;i++)
        scanf("%d",&cor[i]);
    sort(cor,cor+7);//对已有中奖彩票排序

    for(x=0;x<num;x++){
    m=left=0;
    //now[7]={0};
        for(i=0;i<7;i++)
        scanf("%d",&now[i]);
    sort(now,now+7);//对手中彩票进行排序

    for(i=0;i<7;i++)
        for(j=0;j<7;j++){
        if(cor[i]<now[j]){
            left=j;
            break;}
        if(cor[i]==now[j]){
            m++;
            left=j;
            break;
        }
            }
    if(m!=0)
        count[7-m]++;
    }

    for(i=0;i<7;i++){
        printf("%ld",count[i]);
        printf(" ");}
    fclose(stdin);
	fclose(stdout);

}
