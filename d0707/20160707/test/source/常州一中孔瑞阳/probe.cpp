#include<cstdio>
#include<algorithm>
#define FOR(n) for(int i=1;i<=n;i++)
#define N 2001
using namespace std;
int outside[N],inside[N],hu[N],nex[N],las[N],T,n,ans;
char ty[N];
void work(){
	scanf("%d",&n); 
	FOR(n){char c=getchar(); ty[i]=getchar(); scanf("%d",&hu[i]);}
	FOR(N-1)inside[i]=outside[i]=las[i]=0;
	FOR(n){
		int x=hu[i]; if(!x)continue; nex[i]=las[x]; las[x]=i;
		if(ty[i]=='L')
			if(inside[x]){inside[x]=0; outside[x]=1;}else
			if(!outside[x])outside[x]=1;else{
				bool fl=1;
				for(int j=nex[i];j<i;j++)
					if(ty[j]=='E'&&!hu[j]){
						hu[j]=x; fl=0; outside[x]=1; break;
					}
				if(fl){printf("OTHER\n"); return;}
			}
		if(ty[i]=='E')
			if(outside[x]){outside[x]=0; inside[x]=1;}else
			if(!inside[x])inside[x]=1;else{
				bool fl=1;
				for(int j=nex[i];j<i;j++)
					if(ty[j]=='L'&&!hu[j]){
						hu[j]=x; fl=0; inside[x]=1; break;
					}
				if(fl){printf("OTHER\n"); return;}
			}
	}
	int ans=0;
	FOR(N-1)if(inside[i])
		for(int j=las[i];j<=n;j++)
			if(ty[j]=='L'&&!hu[j]){
				hu[j]=i; inside[i]=0; break;
			}
	FOR(n)if(!hu[i])
		if(ty[i]=='L')ans=max(ans-1,0);else ans++;
	FOR(N-1)if(inside[i])ans++;
	printf("%d\n",ans);
}
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
