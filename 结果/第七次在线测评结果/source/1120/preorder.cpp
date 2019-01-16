#include<iostream>
#include"stdio.h"
#include"stdio.h"
#include<cstring>
#include<vector>
using namespace std;

class node{
    public:
    char data;
    node* l;
    node* r;
};

node* creat(char* in,char* post,int len){
if(len==0) return NULL;
int i=len-1;
while(post[len-1]!=in[i]) --i;
node*h=new node;
h->data=post[len-1];
h->l=creat(in,post,i);
h->r=creat(in+i+1,post+i,len-i-1);
return h;
}
void preorder(node*t,FILE*fp2);


int main(){
  FILE*fp1,*fp2;
char in[20],post[20];
int len=0;
fp1=fopen("preorder.in","r");
fp2=fopen("preorder.out","w");
fscanf(fp1,"%s",in);
fscanf(fp2,"%s",post);
for(int i=0;i<20;i++){
    if(in[i]=='\0') break;
    else{
        len++;
    }
}
node *root=creat(in,post,len);
preorder(root,fp2);

}
  void preorder(node*t,FILE *fp2){
   if(t==NULL)
    return;
    fprintf(fp2,"%c",t->data);
     preorder(t->l);
preorder(t->r);
}
