#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int p[2000000];
short x[25000005];
char y[25000005];
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	register int n,m=0,A,B,C,i,j,k,ans=0;
	cin>>A>>B>>C;
	if(A>C)swap(A,C);
	if(B>C)swap(B,C);
	if(A>B)swap(A,B);
	n=A*B*C;
	for(x[1]=1,i=2;i<=n;i++)
	{
		if(!x[i])x[p[m++]=i]=y[i]=1;
		for(j=0;j<m&&(k=i*p[j])<=n;j++)if(i%p[j])
		{
			x[k]=x[i]*(y[i]+1);
			y[k]=1;
		}
		else
		{
			x[k]=x[i];
			y[k]=y[i]+1;
			break;
		}
	}
	for(i=1;i<=n;i++)x[i]*=y[i]+1;
	for(i=1;i<=A;i++)for(j=1;j<=B;j++)for(k=1;k<=C;k++)ans+=x[i*j*k];
	ans&=1073741823;
	cout<<ans<<endl;
	return 0;
}

