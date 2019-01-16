#include <stdio.h>

void sort(int a[7]){
	int flag = 1;
	while (flag){
		flag = 0;
		for (int i = 0; i < 6; i++){
			if (a[i] > a[i + 1]){
				int r = a[i];
				a[i] = a[i + 1];
				a[i + 1] = r;
				flag++;
			}
		}
	}
	return;
}

void readone(FILE* in, int a[7]){
	for (int i = 0; i < 7; i++)
		fscanf(in, "%d", &a[i]);
	return;
}

int search(int hit[7], int buy[7]){
	int k = 0;
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if (buy[i] < hit[j])
				break;
			if (buy[i] == hit[j]){
				k++;
				break;
			}
		}
	}
	return k;
}

void wresult(FILE* out, int goal[8]){
	for (int i = 7; i > 1; i--)
		fprintf(out, "%d ", goal[i]);
	fprintf(out, "%d\n", goal[1]);
	return;
}

int main()
{
	int goal[8], hit[7], buy[7], n;
	FILE* fi;
	fi = fopen("lottery.in", "r");
	fscanf(fi, "%d", &n);
	readone(fi, hit);
	sort(hit);
	for (int i = 0; i < n; i++){
		readone(fi, buy);
		int k = search(hit, buy);
		goal[k]++;
	}
	fclose(fi);
	fi = fopen("lottery.out", "w");
	wresult(fi, goal);
	fclose(fi);
	return 0;
}
