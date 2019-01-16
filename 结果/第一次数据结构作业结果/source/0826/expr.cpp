    #include <iostream>  
    #include <string>  
    #include <stack>  
    #include <fstream> 
    using namespace std;  
            
    template <class T>  
    void zhanqingkong(stack<T> &s)          //���ջ  
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
                if(fu1==')')      //�������Ҳ಻�����ϳ���������  
                {  
                    cout<<"���ʽ��ʽ����\n";  
                    return 0;  
                }  
                else  
                    jibie=-1;  
                break;  
      
            case ')':  
                if(fu1=='(')  
                    jibie=0;       //�����������  
                else  
                    jibie=1;  
                break;  
      
            case '=':  
                if(fu1=='(')  
                {  
                    cout<<"���Ų�ƥ��\n";  
                    return 0;  
                }  
                else if(fu1=='=')  
                    jibie=0;      //�Ⱥ���ԣ�����0  
                else  
                    jibie=1;  
                break;  
        }  
        return jibie;  
    }  
      
      
    /* 
    ����������������������������� 
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
                    cout<<"���ܱ�0��\n";  
                    return 0;  
                }  
        }  
    }  
      
      
    /* 
    �Զ�λ���ִ�ת��λ���� 
    */  
    double pinjie(char ch[])  
    {   double temp =0; //��ʱ��ֵ  
         //int len = 10;  
      
        for(int n=0;n<strlen(ch);n++)  
        {  
            char c = ch[n];  
             c-='0';     //�Ƚ���Ӧ�������ַ�ת�������� 
			 temp = temp *10 + c;                                 
        }  
           
      
        return temp;  
    }  
      
      
     
    double jisuan(char express[])  
    {  
        double a,b;             //����������  
        char opera;             //�����  
        char c;                 //�ַ�����  
        char x;                 //x������ȡ�����ջջ���������  
        stack<char> oper;  
        stack<double> data;   //�����ջջ�����������������ջ  
        char tempNum[20];       //���λ����Ӧ���ַ�����  
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

