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
{                                                           //in��post���ַ����飬�ֱ�洢�и����кͺ�����У���������Ǵ����ŵ�һ���ַ��ĵ�ַ
	int m;
	char *t;
	if(len <= 0)
		return;
    for(t = in; t < in + len; t++)
	{						/*����������in���ҵ����ڵ����ڵ�λ��*/
		if(*(len - 1 + post) == *t)
		{
			m = t - in;  /*kΪ����������������е��±�*/
			printf("%c", in[m]);
            break;
        }
    }
   	InPostToPre(in, post, m); /*��ӡ������*/
    InPostToPre(in + m + 1, post + m, len - m - 1); /*��ӡ������*/
}
