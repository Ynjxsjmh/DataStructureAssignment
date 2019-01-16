#include <stdio.h>
#include <stdlib.h>

struct queue{
	int front, rear, num, el[7000];
	queue(){front = 0; rear = 0; num = 0;}
	void in(int e){el[front++] = e; num++; return;}
	int out(void){num--; return el[rear++];}
};

struct circle{
	int x, y, r;
};

struct plane{
	int num; circle* ci; int now, *visit;
} p;

void getdata(void){
	FILE *in = fopen("circle.in", "r");
	fscanf(in, "%d", &p.num);
	p.ci = (circle*)malloc(sizeof(circle) * p.num);
	p.now = 0; p.visit = (int*)malloc(sizeof(int) * p.num);
	for (int i = 0; i < p.num; i++){
		fscanf(in, "%d%d%d", &p.ci[i].x, &p.ci[i].y, &p.ci[i].r);
		p.visit[i] = 0;
	}
	fclose(in); return;
}

int check(int i, int k){
	if ((p.ci[i].x - p.ci[k].x) * (p.ci[i].x - p.ci[k].x) + (p.ci[i].y - p.ci[k].y) * (p.ci[i].y - p.ci[k].y) <= (p.ci[i].r + p.ci[k].r) * (p.ci[i].r + p.ci[k].r)) return 1;
	return 0;
}

int checkb(int blockn){
	int i;
	for (i = p.now; p.visit[i] == 1 && i < p.num; i++);
	if (i == p.num) return 0 - blockn;
	queue q; q.in(i); p.visit[i] = 1;
	p.now = i + 1;
	while (q.num){
		int k = q.out();
		for (i = p.now; i < p.num; i++)
			if (p.visit[i] == 0 && check(i, k) == 1)
			{q.in(i); p.visit[i] = 1;}
	}
	return blockn - 1;
}

void outputdata(int n){
	FILE *out = fopen("circle.out", "w");
	fprintf(out, "%d", n);
	fclose(out); return;
}

int main()
{
	getdata();
	int blockn = 0;
	while (blockn <= 0){blockn = checkb(blockn);}
	free(p.ci); free(p.visit);
	outputdata(blockn);
	return 0;
}
