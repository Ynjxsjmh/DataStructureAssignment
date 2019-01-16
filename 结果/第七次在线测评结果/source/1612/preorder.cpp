#include<stdio.h>
#include<string.h>
void InPostToPre(char *in, char *post, int len);
int main()
{
	freopen("preorder.in", "r", stdin);
	freopen("preorder.out", "w", stdout);
	char in[11], post[11];
	int len;
	scanf("%s%s", in, post);
	len = strlen(in);
	InPostToPre(in, post, len);
	return 0;
    fclose(stdin);
	fclose(stdout);
}
void InPostToPre(char *in, char *post, int len)
{                                                           //in和post是字符数组，分别存储中根序列和后根序列，在这里，它们代表着第一个字符的地址
	int m;
	char *t;
	if(len <= 0)
		return;
    for(t = in; t < in + len; t++)
	{						/*在中序序列in中找到根节点所在的位置*/
		if(*(len - 1 + post) == *t)
		{
			m = t - in;  /*k为根结点在中序序列中的下标*/
			printf("%c", in[m]);
            break;
        }
    }
   	InPostToPre(in, post, m); /*打印左子树*/
    InPostToPre(in + m + 1, post + m, len - m - 1); /*打印右子树*/
}
