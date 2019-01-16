#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct circle
{
    int x;
    int y;
    int r;
    circle(int xx,int yy,int rr)
    {
        x=xx;
        y=yy;
        r=rr;
    }

    bool sameBlock(const circle &another) const
    {
        int dx=x-another.x;
        int dy=y-another.y;
        int rr=r+another.r;
        if (dx*dx+dy*dy<rr*rr)
            return true;
        return false;
    }
};
vector<vector<circle>> cirk;
vector<circle> cirs;

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n;
    scanf("%d",&n);
    int x,y,r;
    int j;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&r);
        circle cc(x,y,r);
        for(j=0;j<cirk.size();j++)
        {
            for(int k=0;k<cirk[j].size();k++)
            {
                if(cirk[j][k].sameBlock(cc))
                {
                    cirk[j].push_back(cc);
                    goto out;
                }
            }
        }
        if(j==cirk.size())
        {
            cirk.push_back(vector<circle>());
            cirk[j].push_back(cc);
        }
        out:
        ;
    }
    printf("%d",cirk.size());
}
