#include<iostream>
#include<stdio.h>
using namespace std;
int T,n;
int in[2050],in0,out0;
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2000;i++) in[i]=0;
		int flag=0,cnt=0;
		while(n--){
			char c[3];int x;
			scanf("%s%d",c,&x);if(flag) continue;
			if(c[0]=='E') {
				if(x)
				if(in[x]==1) if(!out0) flag=1;else out0--;
				else in[x]=1;
				else in0++;
				cnt++;
			}
			else{
				if(x)
				if(in[x]==-1) if(!in0) flag=1;else in0--;
				else in[x]=-1;
				else out0++;cnt=max(0,cnt-1);
			}
		}
		if(!flag) printf("%d\n",cnt);
		else printf("OTHER\n");
	}
}

