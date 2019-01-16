#include<stdio.h>
int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int data[7];
	int lucky[7];

	long n,i,j,m,k,sum;

	int big=0,one=0,two=0,three=0,four=0,five=0,six=0;
	scanf("%d",&n);
	for(k=0;k<7;k++)
	{
		scanf("%d",&lucky[k]);
	}

	
	for(k=0;k<n;k++)
	{
		for(i=0;i<7;i++)
	    {
	    scanf("%d",&data[i]);
	    }

		    sum=0;
	    for(j=0;j<7;j++)
	    {
	    	for(m=0;m<7;m++)
	    	{
	    		if(data[m]==lucky[j])
	    		{
	    			sum++;
				}
			}
		}
		switch(sum)
		{
			case 1:six++ ;break;
			case 2:five++ ;break;
			case 3:four++ ;break;
			case 4:three++; break;
			case 5:two++ ;break;
			case 6:one++ ;break;
			case 7:big++;
		}

	}


	printf("%d %d %d %d %d %d %d",big,one,two,three,four,five,six);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
