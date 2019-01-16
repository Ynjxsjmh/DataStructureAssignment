#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin("preorder.in");
ofstream fout("preorder.out");
struct point
{
    char data;
    point *left;
    point *right;
};
class tree
{
public:
    point *root;
    void build(string &, string &, point *&);
    tree();
    void preorder(point *);
};
void tree::preorder(point * p)
{
    if(p == NULL)
        return;
    fout << p->data;
    preorder(p->left);
    preorder(p->right);
}
tree::tree()
{

    string s2;
    string s1;
    fin >> s2;
    fin >> s1;
    build(s1, s2, root);
}
void tree::build(string &s1, string &s2, point *&p)
{
    int j, l;
    char c;
    l = s1.length();
    if(l == 0)
    {
        p = NULL;
        return;
    }
    p = new point;
    c = *(s1.substr(l-1,1).c_str());
    p->data = c;
    for(j = 0; *(s2.substr(j,1).c_str()) != c; j++);
    string s11 = s1.substr(0, j);
    string s21 = s2.substr(0, j);
    string s12 = s1.substr(j, l-j-1);
    string s22 = s2.substr(j+1, l-j-1);
    build(s11, s21, p->left);
    build(s12, s22, p->right);
}
int main()
{
    tree t;
    t.preorder(t.root);
}
