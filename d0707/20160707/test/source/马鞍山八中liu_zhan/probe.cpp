#include <stdio.h>
#include <stdbool.h>
#define maxn 1000
int t,n,i,j,k,a[maxn+10][2],s,count;
bool mark,b1[2010],b2[maxn+10];
char c;
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	for (scanf("%d",&t);t>0;t--)
	{
		scanf("%d\n",&n);
		mark=true;
		for (i=0;i<n;i++)
		{
			b1[i+1]=false;
			b2[i]=true;
			scanf("%c%d\n",&c,&a[i][1]);
			if (c=='E') a[i][0]=1;
				else a[i][0]=0;
			if (a[i][1]>0)
			{
				k=n;
				mark=true;
				for (j=i-1;j>=0;j--)
				{
					if ((a[i][1]==a[j][1]) && (a[i][0]!=a[j][0])) break;
					if ((a[i][1]==a[j][1]) && (a[i][0]==a[j][0]))
					{
						mark=k<n;
						break;
					}
					if ((a[j][1]==0) && (a[i][0]!=a[j][0])) k=j;
				}
				if (!mark)
				{
					printf("OTHER\n");
					break;
				}
				if ((k<n) && (j>=0) && (a[i][1]==a[j][1]) && (a[i][0]==a[j][0])) a[k][1]=a[i][1];
			}
		}
		if (mark)
		{
			for (i=0;i<n-1;i++)
				if ((a[i][1]>0) && (a[i][0]==1) && b2[i])
					for (j=i+1;j<n;j++)
						if ((a[i][1]==a[j][1]) && (a[i][0]!=a[j][0]))
						{
							b2[i]=b2[j]=false;
							break;
						}
			for (i=0;i<n;i++)
				if (a[i][1]==0)
					if (a[i][0]==1)
						for (j=i+1;j<n;j++)
						{
							if (b2[j] && (a[i][0]!=a[j][0]))
							{
								a[i][1]=a[j][1];
								b2[i]=b2[j]=false;
								break;
							}
						}
					else
						for (j=i-1;j>=0;j--)
						{
							if (b2[j] && (a[i][0]!=a[j][0]))
							{
								a[i][1]=a[j][1];
								b2[i]=b2[j]=false;
								break;
							}
						}
			s=0;
			for (i=0;i<n;i++)
				if (b2[i])
					if (a[i][1]>0)
					{
						if ((a[i][0]==0) && b1[a[i][1]])
						{
							s--;
							b1[a[i][1]]=false;
						}
						if ((a[i][0]==1) && !b1[a[i][1]])
						{
							s++;
							b1[a[i][1]]=true;
						}
					}
					else s+=a[i][0];
			printf("%d\n",s);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
