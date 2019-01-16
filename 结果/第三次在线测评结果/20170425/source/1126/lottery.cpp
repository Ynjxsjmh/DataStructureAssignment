#include <iostream>  
#include <fstream>  
#include<algorithm>
using namespace std;

int main(){
	int num;
	int a[7];
	int b[7];
	int c[7]={0};
	int cnt;
	ifstream fin("lottery.in");
	ofstream fout("lottery.out");	
	fin>>num;
	for(int t=0;t<7;t++)
	fin>>a[t];
	sort(a,a+7);
	for(int i=0;i<num;i++)
	{
	  for(int j=0;j<7;j++)
	  fin>>b[j];
      sort(b,b+7); 
	 
	     for(int x=0;x<7;i++);
		 { if(a[x]==b[x])
				  cnt++;
		 }
		 
	 switch(cnt)
	 {
		 case 1: c[0]++;   break;
		 case 2: c[1]++;   break;
		 case 3: c[2]++;   break;
		 case 4: c[3]++;  break;
		 case 5: c[4]++;  break;
		 case 6: c[5]++;  break;
		 case 7: c[6]++;  break;
		 
		 
	 }	 
			 	 
    }
	for(int p=6;p>=0;p--)
      fout << c[p] <<" ";
		
		  
return 0;
		
			
	
	
}





