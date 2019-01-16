#include<iostream>
#include<string>
using namespace std;
#define cin fin;
#define cout fout;
ifstream fin("preorder.in");
ofstream fout("preorde.out");
class treenode{
	public:
		treenode * left,*right;
		char data;
};
class tree{
	public:
		treenode * root;
};
int main(void){
	string A;
	string B;
	cin>>A;
	cin>>B;
	return 0;
}
