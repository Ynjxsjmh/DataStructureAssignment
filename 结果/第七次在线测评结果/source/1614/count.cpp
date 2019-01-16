#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x, times;
	node* next;
};

struct cou
{
	node* head;
	cou(){
		head = (node*)malloc(sizeof(node));
		head->x = 0; head->times = 0;
		head->next = NULL;
	}
	void add(int n)
	{
		node* now = NULL;
		for (now = head; now->next; now = now->next){
			if (now->next->x == n){
				now->next->times++;
				return;
			}
			if (now->next->x > n) break;
		}
		node* nn = (node*)malloc(sizeof(node));
		nn->x = n; nn->times = 1;
		nn->next = now->next;
		now->next = nn;
		return;
	}
	void release(node* k)
	{
		if (k->next != NULL) release(k->next);
		free(k);
		return;
	}
} c;

void output(void);

int main()
{
	int num = 0;
	FILE *in = fopen("count.in", "r");
	fscanf(in, "%d", &num);
	for (int i = 0; i < num; i++)
	{
		int n;
		fscanf(in, "%d", &n);
		c.add(n);
	}
	fclose(in);
	output();
	c.release(c.head);
	return 0;
}

void output(void)
{
	FILE *out = fopen("count.out", "w");
	for (node* now = c.head->next; now; now = now->next)
		fprintf(out, "%d %d\n", now->x, now->times);
	fclose(out);
	return;
}
