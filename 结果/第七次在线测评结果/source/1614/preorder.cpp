#include <stdio.h>
#include <string.h>

FILE *out = fopen("preorder.out", "w");

void convertin(char ino[19], char posto[19], int len)
{
	if (len == 0) return;
	fprintf(out, "%c", posto[len - 1]);
	if (len == 1) return;
	int p;
	for (p = 0; p < len; p++)
		if (ino[p] == posto[len - 1])
			break;
	convertin(ino, posto, p);
	convertin(ino + p + 1, posto + p, len - p - 1);
	return;
}

int main()
{
	FILE *in = fopen("preorder.in", "r");
	char ino[19], posto[19];
	fscanf(in, "%s%s", ino, posto);
	convertin(ino, posto, strlen(ino));
	fclose(in);
	fclose(out);
	return 0;
}
