#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *p,*q;
    int a[7],b[1000001][7],k,i,j,y;
    long long n,w[7]={0};
    if((p=fopen("lottery.in","r"))==NULL){
        printf("文件打开失败\n");
        exit(0);
    }
    if((q=fopen("lottery.out","w"))==NULL){
        printf("打开文件失败\n");
        exit(0);
    }
    fscanf(p,"%d",&n);
    for(i=0;i<7;i++)
        fscanf(p,"%d",&(a[i]));
    for(i=0;i<n;i++)
        for(j=0;j<7;j++)
            fscanf(p,"%d",&(b[i][j]));
    for(k=0;k<n;k++){
            y=0;
      for(i=0;i<7;i++)
        for(j=0;j<7;j++)
            if(a[i]==b[k][j])  y++;
      switch(y){
      case 7:w[0]++;break;
      case 6:w[1]++;break;
      case 5:w[2]++;break;
      case 4:w[3]++;break;
      case 3:w[4]++;break;
      case 2:w[5]++;break;
      case 1:w[6]++;break;
      }
    }
    for(i=0;i<7;i++)
        fprintf(q,"%8d",w[i]);

    fclose(p);
    fclose(q);
    return 0;

}

