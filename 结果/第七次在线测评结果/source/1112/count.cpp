#include<iostream>
#include<fstream>
using namespace std;
struct name{
    int num;
    long x;
}a[50000];
int main(){
    ifstream in("count.in.txt");
    ofstream out("count.out.txt");
    int n,total=0;
    int i,j,k;
    bool flag;
    long b;
    in>>n;
    for( i=0;i<n;i++){
        in>>b;
        if(total==0){
            a[0].num=1;
            a[0].x=b;
            total=1;
        }
        else {
            flag=false;
            for(j=0;j<total;j++){
                if(b==a[j].x){
                    a[j].num++;
                    flag=true;
                    break;
                }
            }
            if(!flag){
                 k=total-1;
				while((b<a[k].x)&&(k>=0)){
					a[k+1].x=a[k].x;
					k--;
				}
				a[k+1].x=b;
				a[k+1].num=1;
				total++;
            }
        }

    }
    for(i=0;i<total;i++){
		cout<<a[i].x<<"  "<<a[i].num<<endl;
        out<<a[i].x<<"  "<<a[i].num<<endl;
	}
    in.close();
    out.close();
    return 0;


}
