#include <bits/stdc++.h>
using namespace std;
int T,n;
char buf[5];
int s[2005];
int O,I;
int ans;
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	for(cin>>T;T--;)
	{
		memset(s,-1,sizeof(s));
		O=I=0;ans=0;
		scanf("%d",&n);
		for(int id,i=1;i<=n;i++)
		{
			scanf("%s%d",buf,&id);
			if(ans==-1) continue;
			if(buf[0]=='E')
			{
				ans++;
				if(!id) I++;
				else if(s[id]==1)
				{
					if(O) O--;
					else ans=-1;
				}
				else s[id]=1;
			}
			else
			{
				ans--;
				if(!id) O++;
				else if(s[id]==-1)
				{
					if(I) I--;
					else ans=-1;
				}
				else if(s[id]==0) s[id]=-1,ans++;
				else s[id]=-1;
			}
		}
		if(~ans) printf("%d\n",max(0,ans-O+I));
		else printf("OTHER\n");
	}
	return 0;
}
