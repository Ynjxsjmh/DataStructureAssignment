#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char in[27],post[27];
int n;
void tree(int a, int b)
{
  if(a>b) return;
  int i;
  n--;
  for(i=a;i<=b;i++)
    if(post[n]==in[i])
      break;
  tree(i+1,b);
  tree(a,i-1);
  printf("%c",in[a]);
}
int main(void)
{
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    scanf("%s %s",in,post);
    n=strlen(post)-1;
    tree(0, strlen(post)-1);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
