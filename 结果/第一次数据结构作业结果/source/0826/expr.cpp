    #include <iostream>  
    #include <string>  
    #include <stack>  
    #include <fstream> 
    using namespace std;  
            
    template <class T>  
    void zhanqingkong(stack<T> &s)          //清空栈  
    {  
        while(!s.empty())  
            s.pop();  
    }  
           
 int zifupanduan(char c)  
    {  
      if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='=')  
          return 1;  		
      else     
		  return 0;              
         
    }  
      
    int youxianji(char fu1,char fu2)  
    {  
        int jibie;  
        switch(fu2)  
        {  
            case '+':  
            case '-':  
                if(fu1=='(' || fu1=='=')  
                    jibie=-1;  
                else  
                    jibie=1;  
                break;  
      
            case '*':  
            case '/':  
                if(fu1=='*' || fu1=='/' || fu1==')')  
                    jibie=1;  
                else  
                    jibie=-1;  
                break;  
      
            case '(':  
                if(fu1==')')      //左括号右侧不能马上出现右括号  
                {  
                    cout<<"表达式格式有误！\n";  
                    return 0;  
                }  
                else  
                    jibie=-1;  
                break;  
      
            case ')':  
                if(fu1=='(')  
                    jibie=0;       //左右括号配对  
                else  
                    jibie=1;  
                break;  
      
            case '=':  
                if(fu1=='(')  
                {  
                    cout<<"括号不匹配\n";  
                    return 0;  
                }  
                else if(fu1=='=')  
                    jibie=0;      //等号配对，返回0  
                else  
                    jibie=1;  
                break;  
        }  
        return jibie;  
    }  
      
      
    /* 
    根据运算符和两个操作数进行运算 
    */  
    double suanshi(double a,int oper,double b)  
    {  
        switch(oper)  
        {  
            case '+': return a+b;  
            case '-': return a-b;  
            case '*': return a*b;  
            case '/':  
                if (b!=0)  
                    return a/b;  
                else  
                {  
                    cout<<"不能被0除\n";  
                    return 0;  
                }  
        }  
    }  
      
      
    /* 
    对多位数字串转化位数字 
    */  
    double pinjie(char ch[])  
    {   double temp =0; //临时数值  
         //int len = 10;  
      
        for(int n=0;n<strlen(ch);n++)  
        {  
            char c = ch[n];  
             c-='0';     //先将相应的数字字符转换成整数 
			 temp = temp *10 + c;                                 
        }  
           
      
        return temp;  
    }  
      
      
     
    double jisuan(char express[])  
    {  
        double a,b;             //两个操作数  
        char opera;             //运算符  
        char c;                 //字符变量  
        char x;                 //x用来获取运算符栈栈顶的运算符  
        stack<char> oper;  
        stack<double> data;   //运算符栈栈顶的运算符，操作数栈  
        char tempNum[20];       //与多位数对应的字符数组  
        int j=0;  
      
        int i=0, flag=0;        
      
        oper.push('=');         
      
        c = express[i++];  
        double num=0;  
      
        while(c!='=' || x!='=')         
        {  
            if(zifupanduan(c))   
            {  
                if(flag)       
                {  
                    tempNum[j]=0;                     
                    j=0;  
                    num = pinjie(tempNum);  
                     
                    data.push(num);           
                    num = 0;               
                    flag = 0;                
                }  
      
                switch(youxianji(x,c))  
                {  
                    case -1:    

                        oper.push(c);       
                        c=express[i++];     
                        break;  
      
                    case 0:                
                        oper.pop();         
                        c=express[i++];     
                        break;  
      
                    case 1:                     
                        opera = oper.top();     
                        oper.pop();            
      
                        b = data.top();  
                        data.pop();  
                        a = data.top();  
                        data.pop();             
                        double t = suanshi(a,opera,b);     
                        data.push(t);         
                        break;  
                }  
            }  
      
            else if(c>='0' && c<='9' )     
            {  
                tempNum[j++] = c;  
                flag = 1;               
                c=express[i++];  
            }  
              
            x = oper.top();     
                            
        }  
      
            num = data.top();  
              
            zhanqingkong(oper);  
            zhanqingkong(data);       
           
      
            return  num;    
       
        }       
 
int main()
{
char c[200];
string textline[200];
int i=0,j=0;
ifstream fin("expr.in");
ofstream fout;
fout.open("expr.out");
for(;!fin.eof();)
{
    getline(fin,textline[i],'\n');
    i++;
}
for(j=0;j<i;j++)  { 
  string s=textline[j];
  strcpy(c,s.c_str());
  fout <<jisuan(c)<<endl;}

return 0;
}

