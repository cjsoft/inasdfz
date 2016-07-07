#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1005;

int test,n,ide[2*N],idl[2*N];

int main(){
freopen("probe.in","r",stdin);
freopen("probe.out","w",stdout);
scanf("%d",&test);
while(test--){
	scanf("%d",&n);
	int flag=0,ans=0;
	memset(ide,0,sizeof(ide));
	memset(idl,0,sizeof(idl));
	while(n--){
		char s[5];
		int x;
		scanf("%s %d",s,&x);
		if(flag)continue;
		if(s[0]=='E'){
			if(ide[x]==1 && x && idl[0]<=0){flag=1;continue;}
			else if(ide[x]==1 && x){idl[0]--;continue;}
			else if(x){
				if(ide[x]==-1 && idl[x]==1){ide[x]=1;idl[x]=-1;}
				else if(ide[x]==0 && idl[x]==0){if(idl[0]>0)idl[0]--;ide[x]=1;}
			}
			else ide[0]++;
		}
		if(s[0]=='L'){
			if(idl[x]==1 && x && ide[0]<=0){flag=1;continue;}
			else if(idl[x]==1 && x){ide[0]--;continue;}
			else if(x){
				if(idl[x]==-1 && ide[x]==1){idl[x]=1;ide[x]=-1;}
				else if(ide[x]==0 && idl[x]==0){if(ide[0]>0)ide[0]--;ide[x]=1;}
			}
			else idl[0]++;
		}
	}
	for(int i=1;i<=2000;i++)if(ide[i]>0)ans++;
	if(flag)puts("OTHER");
	else printf("%d\n",ans+(ide[0]+idl[0]>0?ide[0]+idl[0]:-ide[0]-idl[0]));
}
return 0;
}

