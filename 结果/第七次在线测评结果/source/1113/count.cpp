#include <iostream>
#include <cstdio>
#include <map>
//----------------------------------------
using namespace std;
//----------------------------------------
int main()
{
    FILE *in , *out;
    in = fopen("count.in" , "r");
    out = fopen("count.out" , "w");
    int n , x;
    fscanf(in , "%d" , &n);
    map< int , int > getd;
    map< int , int >::iterator temp;
    for (int i = 0 ; i < n ; i++)
    {
        fscanf(in , "%d" , &x);
        if (!getd.empty() && (temp = getd.find(x)) != getd.end())
        {
            temp->second++;
        }
        else
        {
            getd.insert(pair<int , int>(x , 1));
        }
    }
    for (map<int , int>::iterator i = getd.begin() ; i != getd.end() ; i++)
    {
        fprintf(out , "%d %d\n" , i->first , i->second);
    }
    //cout << "Hello world!" << endl;
    fclose(in);
    fclose(out);
    return 0;
}
//----------------------------------------
