#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

class circle{
private:
    unsigned int x;
    unsigned int y;
    unsigned int r;
public:
    circle(int x_input=0,int y_input=0,int r_input=0):x(x_input),y(y_input),r(r_input){}
    unsigned int getX(){return x;}
    unsigned int getY(){return y;}
    unsigned int getR(){return r;}
};

class manager{
private:
    int num;
    int now;
    int sum;
    circle* p;
public:
    manager(int n):num(n),now(0),p(NULL),sum(0){p=new circle[n];}
    ~manager(){delete[]p;}
    void insert(circle*item)
    {
        check(item);
        p[now++]=*item;
    }
    bool cross(circle*p1,circle*p2)
    {
        //为什么fabs用不了？
        int dx=(p1->getX())-(p2->getX())>0?(p1->getX())-(p2->getX()):(p2->getX())-(p1->getX());
        int dy=(p1->getY())-(p2->getY())>0?(p1->getY())-(p2->getY()):(p2->getY())-(p1->getY());
        double dis=sqrt(dx*dx+dy*dy);
        if(dis>(p1->getR()+p2->getR()))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void check(circle*item)
    {
        for(int i=0;i<now;i++)
        {
            if(cross((p+i),item))
                return;
        }
        sum++;
    }
    int getSum(){return sum;}
};

int main()
{
    int i,n;
    unsigned x,y,r;
    circle *temp;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d",&n);
    manager m(n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&r);
        temp=new circle(x,y,r);
        m.insert(temp);
        delete temp;
        temp=NULL;
    }
    printf("%d",m.getSum());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
