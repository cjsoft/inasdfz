#include<iostream>
#include<stdio.h>
using namespace std;
int a[15],vis[15];int n,m;
int ans=0;
void dfs(int deep,int yu){
	if(deep==n&&!yu){
		int num=0;
		for(int i=0;i<n;i++)
			num*=n,num+=a[i];
		int ls=0,flag=0;
		for(int i=1;i<n;i++){
			ls=0;
			for(int j=i;j<n+i;j++)
				ls*=n,ls+=a[j%n];
			if(ls>=num) {flag=1;break;}
		}
		if(!flag) ans++;
	}
	for(int i=0;i<=yu;i++)
		if(!vis[(i+deep+1)%n]){
			vis[(i+deep+1)%n]=1;
			a[deep]=a[deep+n]=i;
			dfs(deep+1,yu-i);
			vis[(i+deep+1)%n]=0;
		}
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(0,m);
	cout<<ans<<endl;
}
