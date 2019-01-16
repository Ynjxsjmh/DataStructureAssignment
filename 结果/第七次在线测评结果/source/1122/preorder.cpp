#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
struct tree{
    char val;
    tree* left;
    tree* right;
};
tree *rec(char *in,char *post,int len,tree*t){
    if(len==0)return NULL;
    char temp;
    int i=0;
    t=new tree;
    t->val=post[len-1];
    cout<<post[len-1];
    t->right=NULL;
    t->left=NULL;
    while(in[i]!=t->val){i++;}
    rec(in,post,i,t->left);
    rec(in+i+1,post+i,len-i-1,t->right);
    return t;
}
void DGDLR(tree* t){
	if(t!=NULL)
	{
		cout<<t->val;
		DGDLR(t->left);
		DGDLR(t->right);
	}
}
int main(){
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    int i=0;
    string in,post;
    cin>>in>>post;
    char *p,*q;
    i=sizeof(in);
    p=&in[0];
    q=&post[0];
    tree*t=NULL;
    t=rec(p,q,i,t);
//    DGDLR(t);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
