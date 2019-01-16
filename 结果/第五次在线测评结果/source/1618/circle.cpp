#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int x,y,r;
    struct node*next;
}Node;
struct node *dif[7000];
int visited[7000];
int a[3];
int together(Node*temp,int a[])
{
    float f1=sqrt(1.0*(temp->x-a[0])*(temp->x-a[0])+1.0*(temp->y-a[1])*(temp->y-a[1]));

    if(f1>(a[2]+temp->r)*1.0)
        return 0;
    return 1;

}
void compare(int a[])
{
    int i,flag=0;
    Node*temp;
    int result;
    Node*w;
    for(i=0;visited[i]!=0;i++)
    {
        temp=dif[i];
        while(temp!=NULL)
        {

            result=together(temp,a);
            if(result==1)
            {break;}
        }
        if(result==1)
        {
            w=(Node*)malloc(sizeof(Node));
            w->x=a[0];
            w->y=a[1];
            w->r=a[2];
            w->next=temp->next;
            temp->next=w;
            flag=1;
            break;

        }
    }
    if(flag==0)
    {
        for(i=0;visited[i]!=0;i++);
        visited[i]=1;
        dif[i]->x=a[0];
        dif[i]->y=a[1];
        dif[i]->r=a[2];
    }

}

int main()
{
    freopen("circle","r",stdin);
    freopen("circle","w",stdout);
    int n;
    scanf("%d",&n);
    int i;

    for(i=0;i<n;i++)
    {
        printf("333");
        visited[i]=0;
        printf("22");
        //dif[i]->next=NULL;
        printf("444");
    }
    printf("11");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        compare(a);
    }
    for(i=0;visited[i]!=0;i++);
    printf("%d",i);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
