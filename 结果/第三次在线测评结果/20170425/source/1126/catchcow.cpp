#include <iostream>  
#include <fstream> 
#include <queue>  
using namespace std;
int bfs(int,int);
int main(){

int num1,num2;
ifstream fin("catchcow.in");
ofstream fout("catchcow.out");	
fin>>num1>>num2;
queue<int>q;
bool vis[10000]={false};
int time=0;
int m=bfs(num1,num2);
fout<<m;				  
return 0;
					
	
	
}

int bfs(int n,int k){
  q.push(n);
  vis[n]=1;
 // q.pop(n);
  time++;
  while(q.empty()!=0)
	 head=q.front();
       q.pop();
	   
	if(time==k) return time;
	   
	if(head-1>=0&&vis[x-1]!=false)
	{	time=time+1;
        bfs(head-1,k);
		
         

     }
	 
	 if(head*2<=100000&&vis[2*head]!=false)
	{	time=time+1;
          bfs(head+1,k);


     }
	 
	 
	 if(head+1<=100000&&vis[head+1]!=false)
	{	time=time+1;
          bfs(head*2,k);


     }
	    
  
 

}



