#include <cstring>
#include <cstdio>
const int base=29,N=500005;
int n;
char s[N];
unsigned long long h[N],power[N];
inline unsigned long long Hash(int x,int y)
{
	return h[y]-h[x-1]*power[y-x+1];
}
inline int LCP(int x,int y)
{
	int l=0,r=n-y+1,mid;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(Hash(x,x+mid-1)==Hash(y,y+mid-1)) l=mid;
		else r=mid-1;
	}
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	power[0]=1;
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]*base+s[i]-'a'+1,power[i]=power[i-1]*base;
	for(int i=1;i<=n;)
	{
		int len=0,pos=0;
		for(int j=1;j<i;j++)
		{
			int k=LCP(j,i);
			if(k>len) len=k,pos=j;
		}
		if(!len) printf("%d %d ",-1,s[i]),i++;
		else printf("%d %d ",len,pos-1),i+=len;
	}
}
