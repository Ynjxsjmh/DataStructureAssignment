#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinaryTree
{
    char  elem;
    struct BinaryTree* left;
    struct BinaryTree* right;
}BT, *PBT;

FILE *Out;
int k = 0;

BT* CreatByIA(char* in, char* af, int len)
{
    if(len == 0)
    {
        return NULL;
    }
    BT* node = new BT;
    node->elem = *(af + len - 1);
    fprintf(Out,"%c",node->elem);
    int rid = 0;
    for(;rid < len; rid++)
    {
        if(in[rid] ==  *(af+len-1))
            break;
    }
    node->left = CreatByIA(in, af, rid);
    node->right = CreatByIA(in + rid + 1, af + rid , len - (rid + 1));
    
    return node;
}
int main()
{
	freopen("preorder.in","r",stdin);
	char temp[30];
    char *af, *in;
	scanf("%s",temp);
	//printf("%s",temp);
	fclose(stdin);
    int n = strlen(in);
    int i = 0, j = 0;
    for(i = 0; i < 30; i++){
    	if(temp[i] == ' ')
    		break;
	}
//	printf("%s",temp);
	
	int len;
	len = i;
	af = (char*)malloc(sizeof(char)*len);
	in = (char*)malloc(sizeof(char)*len);
	for(int k = 0; k < len; k++){
		*(in+k) = temp[k];
		*(in+k) = temp[k+len+1];
	}
	Out = fopen("preorder.out","w");
	CreatByIA(in,af,len);
	fclose(Out);
	free(af);
	free(in);
	return 0;
}

