//
//  main.c
//  简易计算器
//  AC !!
//  Created by DuanHaoHua on 17/3/15.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//  Debug完成！

//当输入表达式时，在数字与数字之间多插入一个标志字符，方便在实际计算中进位计算

//若2/3*4=  则等于0
//将sum数组换成了int类型，以容纳大数值  2017.4.8晚8:28


#include <stdio.h>
#include <stdlib.h>
//#define exs 1E9

char expr[3000];
char opr[3000];  //栈
int i;  //栈指针
int len;    //操作字符串的长度

char chan[3000]; //change 存储后缀表达式
int chan_i; //指针

void input();
int set(char ch);
void operate();
void operate2(char ch);
void change();
void f1();
void output();
void count();

int main(void)
{
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    f1();
    //output();
    count();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void count()
{
    int p = 0;
    int q = 0;
    long long int sum[3000];
    
    for (int i = 0; i <= 2999; i ++)
    {
        sum[i] = '\0';
    }
    long long int temp;
    int flag = 0;
    temp = chan[p];
    
    while (temp != '\0')
    {
        flag = 0;
        if (temp >= '0' && temp <= '9')
        {
            temp -= '0';
            int temp2 = chan[p + 1];
            while (temp2 >= '0' && temp2 <= '9')
            {
                temp2 -= '0';
                flag = 1;
                temp = temp * 10 + temp2;
                p ++;
                temp2 = chan[p + 1];
            }
            sum[q ++] = temp;
        }
        
        else if (temp == '+')
        {
            long long int temp2 = sum[-- q];
            long long int temp3 = sum[-- q];
            sum[q ++] = temp2 + temp3;
        }
        
        else if (temp == '-')
        {
            long long int temp2 = sum[-- q];
            long long int temp3 = sum[-- q];
            sum[q ++] = temp3 - temp2;
        }
        
        else if (temp == '*')
        {
            long long int temp2 = (sum[-- q]);
            long long int temp3 = (sum[-- q]);
            sum[q ++] = temp2 * temp3;
        }
        
        else if (temp == '/')
        {
            long long int temp2 = sum[-- q];
            long long int temp3 = sum[-- q];
            sum[q ++] = temp3 / temp2;
        }
        
        temp = chan[++ p];
    }
    printf("%lld", (sum[0]));
}
void output()
{
    chan[chan_i] = '\0';
    printf("%s\n", chan);
}
void f1()
{
    change();
    
}
void change()
{
    input();
    operate();
}

void input()
{
    scanf("%s", expr);
}

int set(char ch)
{
    if (ch == '(' || ch == ')')
        return 0;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void operate()
{
    char temp;
    for (int k = 0; ; k ++)
    {
        if (expr[k] == '=')
            break;
        len ++;
    }
    
    for (int j = 0; j <= len - 1; )
    {
        temp = expr[j];
        if (temp >= '0' && temp <= '9')
        {
            chan[chan_i ++] = temp;
            int temp_1 = expr[j + 1];
            while (temp_1 >= '0' && temp_1 <= '9')
            {
                j ++;
                chan[chan_i ++] = temp_1;
                temp_1 = expr[j + 1];
            }
            chan[chan_i ++] = '\t';
            j ++;
        }
        else
        {
            operate2(temp);
            j ++;
        }
    }
    int temp2 = i - 1;
    for ( ; temp2 >= 0; temp2 --)
    {
        //printf("%c", opr[temp2]);
        chan[chan_i ++] = opr[temp2];
    }
    
}

//指针指在最后一个元素
void operate2(char ch)
{
    int temp = i;
    if (ch == '(')
    {
        opr[temp ++] = ch;
    }
    else if (ch == ')')
    {
        temp --;
        while (opr[temp] != '(')
        {
            chan[chan_i ++] = opr[temp];
            temp --;
            //printf("%c", opr[temp --]);
        }
        //temp --;
    }
    else
    {
        if (temp == 0)
        {
            opr[temp ++] = ch;
        }
        else
        {
            /*******************************/
            //if (set(ch) < set(opr[temp - 1]))
            /*******************************/
            if (set(ch) <= set(opr[temp - 1]))
            {
                /**************************************/
                //while (set(ch) <= set(opr[temp - 1]))
                /**************************************/
                while (set(ch) <= set(opr[temp - 1]))
                {
                    if (temp == 0)
                        break;
                    chan[chan_i ++] = opr[temp - 1];
                    //printf("%c", opr[temp - 1]);
                    temp --;
                }
                opr[temp ++] = ch;
                
            }
            else
            {
                opr[temp ++] = ch;
            }
        }
    }
    i = temp;
}

