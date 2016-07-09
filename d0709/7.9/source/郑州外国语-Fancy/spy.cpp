#include <iostream>
#include <cstdio>
int n,a[2505][2505];
inline int bitcount(int x)
{
	int answer=0;
	for(;x;x-=x&(-x)) answer++;
	return answer;
}
int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}
inline void Guass()
{
	for(int i=0;i<n;i++)
	{
		int t=i;while(t<n&&!a[t][i]) t++;
		if(t==n) continue;
		if(i!=t) std::swap(a[i],a[t]);
		for(int j=0,d,ta,tb;j<n;j++)
			if(j!=i&&a[j][i])
			{
				d=gcd(a[j][i],a[i][i]);
				ta=a[i][i]/d,tb=a[j][i]/d;
				if(j<i) a[j][j]*=ta;
				for(int t=i;t<=n;t++)
					a[j][t]=a[j][t]*ta-a[i][t]*tb;
			}
		/*for(int j=0;j<n;j++,printf("\n"))
			for(int t=0;t<=n;t++)
				printf("%d ",a[j][t]);
		printf("\n");*/
	}
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i][n]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=(bitcount((i|j)^i)+1)&1;
	Guass();
	for(int i=0;i<n;i++) printf("%d ",a[i][n]/a[i][i]);
}
