#include <iostream>
#include <cstdio>
#include <cstring>
//----------------------------------------
using namespace std;
FILE *in , *out;
void preorder(char inorder[] , char postorder[] , int length);
//----------------------------------------
int main()
{
    char inorder[100] , postorder[100];
    in = fopen("preorder.in" , "r");
    out = fopen("preorder.out" , "w");
    fscanf(in , "%s%s" , inorder , postorder);
    preorder(inorder , postorder , strlen(postorder));
    //cout << inorder << postorder;
    //cout << "Hello world!" << endl;
    fclose(in);
    fclose(out);
    return 0;
}
//----------------------------------------
void preorder(char inorder[] , char postorder[] , int length)
{
    if (length <= 0)
    {
        return;
    }
    if (length == 1)
    {
        fprintf(out , "%c" , postorder[length - 1]);
        return;
    }
    int leftlength = 0 , rightlength = 0;
    for (int i = 0 ; i < length ; i++)
    {
        if (postorder[length - 1] == inorder[i])
        {
            leftlength = i;
        }
    }
    rightlength = length - leftlength - 1;
    fprintf(out , "%c" , postorder[length - 1]);
    preorder(inorder , postorder , leftlength);
    preorder(inorder + leftlength + 1 , postorder + leftlength , rightlength);
}
//----------------------------------------
