#include <bits/stdc++.h>

#define MAXN 400001
#define next(p) (((p)==n)?1:((p)+1))


int n,c;
int ans;

int t[MAXN];

void dfs(int x,int sum=0){
	if(x>n){
		if(sum==c){
			int flag=1;
			for(int i=2;i<=n;++i){
				int fl=0;
				for(int p=1,q=i;p<=n;++p,q=next(q)){
					if(t[p]!=t[q]){
						fl=t[p]>t[q];
						break;
					}
				}
				flag=flag&&fl;
			}
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j){
					if(i==j)continue;
					flag=flag&&(t[i]+i)%n!=(t[j]+j)%n;
				}
			ans+=flag;
		}
		return;
	}
	for(int i=0;i<=c;++i)t[x]=i,dfs(x+1,sum+i);
}

int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&c);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
