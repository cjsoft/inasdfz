#include<cstdio>
#include<cstring>
#define N 2000001

using namespace std;

char ch[N],s;
int c[N],ans,l,r;

int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	s=getchar(); while(s=='0'||s=='1'){ch[++r]=s; s=getchar();}
	for(int i=1;i<=r;i++)c[i]=ch[r-i+1]-'0'; l=1;
	while(l!=r)
	{
		ans++;
		if(!c[l])l++;else
		{
			for(int i=l;i<=r;i++)c[i]*=3; c[l]++;
			for(int i=l;i<=r;i++){
				c[i+1]+=c[i]>>1; c[i]&=1;
				if(c[r+1])r++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
