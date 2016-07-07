#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=2010;
int q[N][2],st[N][N],top[N],flag[N],p[N][2],used[N],las[N],exi[N],tmp[N];
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int T,i,n,x,c,l,ans,j,sum;char tp[10];
	scanf("%d",&T);
	while(T--){
		memset(top,0,sizeof(top));
		memset(flag,0,sizeof(flag));
		memset(used,0,sizeof(used));
		memset(las,0,sizeof(las));
		memset(exi,0,sizeof(exi));
		l=0;ans=0;sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%s %d",tp,&q[i][1]);
			if(tp[0]=='E') q[i][0]=0;
			else q[i][0]=1;
		}
		for(i=1;i<=n;i++){
			x=q[i][1];
			if(x==0) continue;
			if(q[i][0]==0) st[x][++top[x]]=i;
			else if(st[x][top[x]]) flag[st[x][top[x]--]]=1,flag[i]=1; 
		}
		for(i=1;i<=n;i++)
		    if(!flag[i]) p[++l][0]=q[i][0],p[l][1]=q[i][1];
		for(i=1;i<=l;i++){
			c=p[i][0];x=p[i][1];
			if(x==0||c==0) continue;
			if(!exi[x]) exi[x]=1,las[x]=i;
			else{
				for(j=las[x];j<=i;j++)
				    if(!used[j]&&p[j][0]==0&&p[j][1]==0) break;
				if(j>i) break;
				used[j]=1;
				las[x]=i;
			}
		}
		if(i<=l){printf("OTHER\n");continue;}
		memset(las,0,sizeof(las));
		memset(exi,0,sizeof(exi));
		for(i=l;i>=1;i--){
			c=p[i][0];x=p[i][1];
			if(x==0||c==1) continue;
			if(!exi[x]) exi[x]=1,las[x]=i;
			else{
				for(j=las[x];j>=i;j--)
				    if(!used[j]&&p[j][0]==1&&p[j][1]==0) break;
				if(j<i) break;
				used[j]=1;
				las[x]=i;
			}
		}
		if(i>=1){printf("OTHER\n");continue;}
		memset(exi,0,sizeof(exi));
		for(i=1;i<=l;i++){
			c=p[i][0];x=p[i][1];
			if(c==0&&x==0&&!used[i]) sum++;
			if(c==0||x==0) continue;
			if(exi[x]) continue;
			if(sum) sum--;
			exi[x]=1;
		}
		memset(exi,0,sizeof(exi));
		int k=0;
		for(i=l;i>=1;i--){
			c=p[i][0];x=p[i][1];
			if(c==1&&x==0&&!used[i]) tmp[++k]=-1;
			if(c==1||x==0) continue;
			if(exi[x]) continue;
			tmp[++k]=1;
			exi[x]=1;
		}
		for(i=k;i>=1;i--)
		    if(ans+tmp[i]>=0) ans+=tmp[i];
		printf("%d\n",ans+sum);
	}
	return 0;
}
