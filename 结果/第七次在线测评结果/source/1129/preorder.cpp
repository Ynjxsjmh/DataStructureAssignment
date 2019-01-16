#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

typedef struct Node{
    char ch;
    struct Node *left;
    struct Node *right;
}Node;

char mid[10];
char bac[10];
int n=-1;

void make_tree(int i,int j)
{
  int k;
  if(i>j) return;
  n--;
  for(k=i;k<=j;k++){
    if(mid[k]==bac[n])break;
  }
  make_tree(i,k-1);
  make_tree(k+1,j);
  printf("%c",bac[k]);
}

int main(void)
{

    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int i,j,k;
    scanf("%s%s",mid,bac);
    {
        make_tree(0,strlen(mid)-1);
        printf("\n");
        n=11;
    }


    return 0;
}

