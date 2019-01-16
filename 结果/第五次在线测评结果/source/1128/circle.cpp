#include <iostream>
#include <stdio.h>
using namespace std;
struct circle
{
    int x;
    int y;
    int r;
    circle*next;
    circle*right;
    circle(int a,int b,int c){x=a;y=b;r=c;next=NULL;right=NULL;};
    int comp(circle *p)
    {
        int d=(p->x-this->x)*(p->x-this->x)+(p->y-this->y)*(p->y-this->y);
        if(d<=(p->r+this->r)*((p->r+this->r)))
            return 1;
        else
            return 0;
    }
};
int sea(circle *p,circle *q)// const///、在以p为开头的链里找q
{
    circle*r=p;
    for(;r;r=r->next)
        if(q->comp(r))
        {
        return 1;
        }

    return 0;
}
void connect_link(circle*p,circle*q)///把p加到q
{
    circle *r;
    for(r=p;r->next!=NULL;r=r->next);
    r->next=q->next;
    q->next=p;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n,x,y,z;
    circle *head=NULL,*p,*q,*r,*f;
    cin>>n;
    if(n==0)
        cout<<0;
    for(int i=0;i<n;i++)
    {
        f=NULL;
        scanf("%d %d %d",&x,&y,&z);
        p=new circle(x,y,z);
        if(head==NULL)
            {head=p;
            continue;}
        for(q=head;q;q=q->right)
            if(sea(q,p))
            {
                if(f==NULL)
                    f=q;
                else
                    for(r=head->right;r->right;r=r->right)
                    if(r->right==f)
                       {
                           r->right=f->right;
                           connect_link(f,q);
                           f=q;
                           break;
                       }
            }
        if(f==NULL)
           {
               for(r=head;r->right;r=r->right);
               r->right=p;
           }
        else
        {p->next=f->next;
        f->next=p;}
    }
    n=0;
    for(r=head;r;r=r->right)
        n++;///跑一下看看是否多减去了一
    cout<<n;
}
