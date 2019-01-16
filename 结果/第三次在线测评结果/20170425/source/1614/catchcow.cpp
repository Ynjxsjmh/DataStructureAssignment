#include <stdio.h>

struct queue{
	int q[50000], size, front, rear;
	queue(){size = 0; front = 0; rear = 0;}
	void in(int pos){q[rear++] = pos; return;}
	int out(void){return q[front++];}
	int seek(void){return q[front];}
};

int main()
{
	queue po;
	int n, k, p[100001];
	for (int i = 0; i < 100001; i++)
		p[i] = -1;
	FILE *fi = fopen("catchcow.in", "r");
	fscanf(fi, "%d%d", &n, &k);
	fclose(fi);
	p[n] = 0;
	po.in(n);
	while (p[k] == -1){
		n = po.out();
		if (p[n + 1] == -1){p[n + 1] = p[n] + 1; po.in(n + 1);}
		if (p[n - 1] == -1){p[n - 1] = p[n] + 1; po.in(n - 1);}
		if (p[2 * n] == -1){p[2 * n] = p[n] + 1; po.in(2 * n);}
	}
	fi = fopen("catchcow.out", "w");
	fprintf(fi, "%d", p[k]);
	fclose(fi);
	return 0;
}
