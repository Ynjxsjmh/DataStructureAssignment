#include<iostream>
#include"stdlib.h"
#include"stdio.h"
#include<queue>
using namespace std;
struct node{
    int item;
    struct node*left;
    struct node*right;
};
struct node* findp(int f,struct node*t){
	struct node*p;
	if(t==NULL) return NULL;
	if(t->item==f) return t;
	if((p=findp(f,t->left))!=NULL) return p;
	else return findp(f,t->right);
}
int deep(struct node* t){
    int ldeep,rdeep;
    if(t==NULL) return 0;
    else{
        ldeep=deep(t->left);
        rdeep=deep(t->right);
        return ldeep>=rdeep?ldeep+1:rdeep+1;
    }
}
int main(){
    FILE*fp1,*fp2;
    fp1=fopen("tree.in","r");
    fp2=fopen("tree.out","w");
    int n,item,f,d;    struct node*root,*t,*k;
    fscanf(fp1,"%d",&n);
    root=(struct node*)malloc(sizeof(struct node));
    root->item=1;
    root->left=NULL;
    root->right=NULL;
    for(int i=1;i<=n;i++){
        fscanf(fp1,"%d",&f);
        fscanf(fp1,"%d",&item);
        t=(struct node*)malloc(sizeof(struct node));
        t->item=item;
        t->left=t->right=NULL;
        k=findp(f,root);
        if(k->left==NULL) k->left=t;
        else k->right=t;
    }
    d=deep(root);
    fprintf(fp2,"%d",d);
    fprintf(fp2,"\n");
    int visit[100],no=0,no1=0,now=0; queue<struct node*>s;
    t=root;
    for(int i=0;i<100;i++) visit[i]=0;
    if(root!=NULL){
        visit[now]=1;
        no=visit[now];
        s.push(t);
    }
    while(!s.empty()){
            no=visit[now];
            no1=0;
        for(int i=1;i<=no;i++){
             t=s.front();
             s.pop();
             if(t->left!=NULL) {
                s.push(t->left);
                no1++;
             }
             if(t->right!=NULL){
                s.push(t->right);
                no1++;
             }
        }
            now++;
            visit[now]=no1;
    }
    int max1;
    max1=visit[0];
    for(int i=0;i<=d;i++){
        if(visit[i]>max1)
            max1=visit[i];
    }
    fprintf(fp2,"%d",max1);
    fclose(fp1);
    fclose(fp2);
    return 0;
}






