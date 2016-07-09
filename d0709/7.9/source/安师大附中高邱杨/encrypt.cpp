#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

const int N=500005;
const long long MOD=150838133;
char s[N];
int n,a[N],b[N],pos;
long long h[N],slj[N];

long long gethash(int l,int r)
{
	return (h[r]-h[l-1]*slj[r-l+1]%MOD+MOD)%MOD;
}

bool ok(int i,int l)
{
	if(i+l-1>n)return 0;
	long long nowhash=gethash(i,i+l-1);
	for(int j=1;j<i;j++)
	    if(gethash(j,j+l-1)==nowhash)
	    {
	    	pos=j;
	        return 1;
	    }
	return 0;
}

int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	int i,lb,rb,mid,anspos;
	slj[0]=1;
	for(i=1;i<=n;i++)
	{
		h[i]=(h[i-1]*27+s[i]-'a'+1)%MOD;
		slj[i]=slj[i-1]*27%MOD;
	}
	for(i=1;i<=n;i++)
	{
		lb=0;rb=n;
		while(lb+1<rb)
		{
			mid=(lb+rb)/2;
			if(ok(i,mid))lb=mid,anspos=pos;
			else rb=mid;
		}
		a[i]=lb;
		b[i]=anspos;
	}
	i=1;
	while(i<=n)
		if(a[i])
		{
			printf("%d %d ",a[i],b[i]-1);
			i+=a[i];
		}
		else
		{
			printf("%d %d ",-1,s[i]);
			i++;
		}
	return 0;
}

