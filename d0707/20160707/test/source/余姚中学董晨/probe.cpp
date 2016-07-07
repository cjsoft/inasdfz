#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2005
int T,n,m,k,l,t,s,x,y,ans;
int q[N][2],p[N],pre[N],last[N],a[N],b[N],f[N][2],flag[N];
char st[5];
bool check(){
	for (int i=1;i<=2000;i++)p[i]=-1,pre[i]=n+1;
	for (int i=n;i;i--)
		if(q[i][1]){
			x=q[i][1];
			if(p[x]==q[i][0]){
				t=1;
				for (int j=pre[x]-1;j>i;j--)
					if(q[j][0]==1-q[i][0]&&q[j][1]==0&&!flag[j]){
						flag[j]=1;
						t=0;
						break;
					}
				if(t)return 0;
			}
			p[x]=q[i][0];
			pre[x]=i;
		}
	return 1;
}
void work(){
	for (int i=1;i<=2000;i++)p[i]=-1,pre[i]=0,b[i]=0;
	for (int i=1;i<=n;i++)
		if(q[i][1]){
			x=q[i][1];
			if(p[x]==-1)f[x][0]=q[i][0],f[x][1]=i;
			p[x]=q[i][0];
			pre[x]=i;
		}
	for (int i=1;i<=2000;i++)
		if(p[i]>=0&&f[i][0]==1){
			for (int j=1;j<f[i][1];j++)
				if(q[j][0]==0&&q[j][0]==0&&!flag[j]){
					flag[j]=1;
					break;
				}
		}
	ans=0;
	for (int i=1;i<=2000;i++)b[pre[i]]=1;
	for (int i=1;i<=n;i++){
		if(b[i]==1&&q[i][0]==0)ans++;
		else{
			if(q[i][1]==0&&!flag[i]){
				if(q[i][0]==0)ans++;else ans--;
				ans=max(ans,0);
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s%d",st,&q[i][1]);
			flag[i]=0;
			if(st[0]=='E')q[i][0]=0;
			else q[i][0]=1;
		}
		if(!check()){puts("OTHER");continue;}
		work();
	}
}
