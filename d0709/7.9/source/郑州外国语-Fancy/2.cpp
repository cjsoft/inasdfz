#include <cstring>
#include <cstdio>
#include <queue>
const int N=500005;
int n,tota,next[N],ans[N<<1];
char s[N];
std::pair<int,int> fail[N];
inline void getnext(int st)
{
	next[st]=st-1;
	for(int i=st,j=st-1;i<n;i++,j++)
	{
		while(j!=st-1&&s[i]!=s[j]) j=next[j];
		next[i+1]=j+1;
		if(j+1-st>fail[i+1].first)
			fail[i+1]=std::make_pair(j+1-st,st+1);
	}
}
int main()
{
	freopen("encrypt.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) getnext(i);
	//for(int i=1;i<=n;i++) printf("%d %d\n",fail[i].first,fail[i].second);
	for(int i=n;i;)
	{
		if(!fail[i].first) ans[++tota]=s[i-1],ans[++tota]=-1,i--;
		else ans[++tota]=fail[i].second-1,ans[++tota]=fail[i].first,i-=fail[i].first;
	}
	while(tota) printf("%d ",ans[tota--]);
}
