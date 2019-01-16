#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(int x1, int x2, int y1, int y2, int r1, int r2){
	long int dis;
	dis = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	if(dis <= (r1 + r2)*(r1*r2)){
		return 1;
	}
	return 0;
}

int main(void){
	FILE * fileIn, * fileOut;
	fileIn = fopen("circle.in", "r");
	fileOut = fopen("circle.out", "w");
	int n;
	int r1, r2, x1, x2, y1, y2;
	int location[7000][4];
	int division[70][50];
	int divide = 0;
	fscanf(fileIn, "%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++)
			fscanf(fileIn,"%d", &location[i][j]);
		if(i == 0){
			divide += 1;
			division[0][1] = 0;
			division[0][0] = 1;
			location[0][3] = 0;
		}
		else{
			int flag = 0;
			for(int k = 0; k < divide; k++){
				for(int t = 1; t <= division[k][0]; t++){
					int To = division[k][t];
					x1 = location[i][0];
					x2 = location[To][0];
					y1 = location[i][1];
					y2 = location[To][1];
					r1 = location[i][2];
					r2 = location[To][2];
					if(judge(x1,x2,y1,y2,r1,r2) == 1){
						flag = 1;
						location[i][3] = k;
						division[k][0] += 1;
						division[k][To+1] = i;
						break;
					}	
				}
				if(flag)break;
			}
			if(flag == 0){
				divide += 1;
				division[divide][0] = 1;
				division[divide][1] = i;
				location[i][4] = divide;
			}
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++)
			printf("%d ",location[i][j]);
		printf("\n");
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 5; j++)
			printf("%d ", division[i][j]);
		printf("\n");
	}
	*/
	fprintf(fileOut, "%d", divide);	
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++)
			fprintf(fileOut,"%d", location[i][j]);
	}
	*/
	fclose(fileIn);
	fclose(fileOut);
}
