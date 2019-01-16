#include <stdio.h>

struct queue{
	int rear, front, num;
	node* el[50];
	queue(){rear = 0; front = 0; num = 0;}
	void in(node* n){el[front++] = n; num++; return;}
	node* out(void){num--; return el[rear++];}
};

struct node{
	int data, depth;
	node *ls, *rs;
};

struct tree{
	node* root;
	int width, depth;
	tree(){
		width = 1; depth = 1;
		root = (node*)malloc(sizeof(node));
		root->data = 1; root->depth = 1;
		root->ls = NULL; root->rs = NULL;
	}
} t;

void getdata(int* fr, int* to){
	FILE *in = fopen("tree.in", "r");
	int num; fscanf(in, "%d", &num);
	for (int i = 0; i < num - 1; i++){
	}
	return;
}

int main()
{
	int fr, to;
	//getdata(&fr, &to);
	//int s = t.search(fr, to);
	//outpurdata(s);
	return 0;
}
