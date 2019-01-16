#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int target[36];
int n;
int out[8];

void Input(FILE *fpin) {
    while (!feof(fpin)) {
        fscanf(fpin, "%d", &n);

		int k = 0;
        for(int i = 0; i < 7; i++) {
            fscanf(fpin, "%d", &k);
            target[k] = 1;
        }

        for(int i = 0; i < n; i++) {
            int now = 0;
            int num_i = 7;
            for(int j = 0; j < 7; j++) {
                fscanf(fpin, "%d", &now);
                if(target[now]) {
                    num_i--;
                }
            }
            out[num_i]++;
        }
    }
}

int main()
{
	memset(target, 0, sizeof(target));

    FILE *fpin, *fpout;
    fpin = fopen("lottery.in","r");
    Input(fpin);
    fclose(fpin);
    
	fpout = fopen("lottery.out","w");
    for(int i = 0; i < 7; i++) {
        fprintf(fpout, "%d", out[i]);
        if(i != 6)fprintf(fpout, " ");
    }
    fclose(fpout);

    return 0;
}
