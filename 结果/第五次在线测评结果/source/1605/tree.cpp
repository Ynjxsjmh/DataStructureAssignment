#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fc[101][5];

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
} 

void deepth(int deep, int k){
	if(fc[k][4] != -1){
		return;
	}
	
	fc[k][4] = deep + 1;
	for(int i = 0; i <= fc[k][3]; i++){
		deepth(fc[k][4], fc[k][i]);
	}
}

int main(void){
	FILE * fileIn, * fileOut;
	fileIn = fopen("tree.in", "r");
	fileOut = fopen("tree.out", "w");
	int deep = 0;
	int width[101];
	int maxWidth = 0;
	int n;
	int pre, aft;
	fscanf(fileIn, "%d", &n);
	
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 5; j++){
			fc[i][j] = -1;
		}
		width[i] = 0;
	}
	
	for(int i = 0 ; i < n - 1; i++){
		fscanf(fileIn, "%d", &pre);
		fscanf(fileIn, "%d", &aft);
		fc[pre][++fc[pre][3]] = aft;
		fc[aft][++fc[aft][3]] = pre;
	}
	
	
	deepth(0, 1);
	
	
	for(int i = 1; i <= n; i++){
		if(deep < fc[i][4]){
			deep = fc[i][4];
		}
		width[fc[i][4]]++;
	}
	
	for(int i = 1; i <= deep; i++){
		if(maxWidth < width[i]){
			maxWidth = width[i];
		}
	}
	
	
	int u, v;
	fscanf(fileIn, "%d", &u);
	fscanf(fileIn, "%d", &v);
	
	int dis = 0;

	
	int faud = fc[u][4], favd = fc[v][4];
	int fau = u, fav = v;
	int maxuvdeep = max(fc[u][4], fc[v][4]);
	int nowflag = 0;
	while(u != v){
		if(faud > favd){
			for(int i = 0; i <= fc[u][3]; i++){
				if(fc[fc[u][i]][4] < faud){
					u = fc[u][i];
					break;
				}
			}
			faud --;
			dis += 2;
			if(fau == fav){
				nowflag = 1;
			}
		}
		if(faud < favd){
			for(int i = 0; i <= fc[v][3]; i++){
				if(fc[fc[v][i]][4] < favd){
					v = fc[v][i];
					break;
				}
			}
			favd --;
			dis += 1;
			if(u == v){
				nowflag = 1;
			}
		}
		for(int i = 0; i <= fc[u][3]; i++){
				if(fc[fc[u][i]][4] < faud){
					u = fc[u][i];
					break;
				}
			}
			faud --;
			dis += 2;
			if(fau == fav){
				nowflag = 1;
			}
			for(int i = 0; i <= fc[v][3]; i++){
				if(fc[fc[v][i]][4] < favd){
					v = fc[v][i];
					break;
				}
			}
			favd --;
			dis += 1;
			if(u == v){
				nowflag = 1;
			}
			
	}	
	fprintf(fileOut, "%d\n%d\n%d\n", deep, maxWidth, dis);
	
	fclose(fileIn);
	fclose(fileOut);
}
