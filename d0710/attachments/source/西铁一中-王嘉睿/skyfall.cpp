#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int vis[5050];
int maxa,maxb,maxc;
struct node{
	int num;unsigned int cnt;
};vector<node> A[5050];
int n;
void init(){
	for(int i=2;i<=n;i++) vis[i]=1;
	for(int i=2;i<=n;i++)
		if(vis[i]){
			for(int j=i;j<=n;j+=i){
				vis[j]=0;
				int ls=j;
				unsigned int cnt=0;
				while(ls%i==0){
					cnt++;ls/=i;
				}
			//	cout<<i<<' '<<j<<' '<<cnt<<endl;
				A[j].push_back((node){i,cnt});
			}
		}
}
unsigned int f[5050];
unsigned int work(int x,int y,int z){
//	cout<<x<<' '<<y<<' '<<z<<endl;
	for(int i=0;i<A[x].size();i++) f[A[x][i].num]+=A[x][i].cnt;
	for(int i=0;i<A[y].size();i++) f[A[y][i].num]+=A[y][i].cnt;
	for(int i=0;i<A[z].size();i++) f[A[z][i].num]+=A[z][i].cnt;
	unsigned int ret=1;
//	for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<endl;
	for(int i=0;i<A[x].size();i++) ret*=f[A[x][i].num]+1,f[A[x][i].num]=0;
	for(int i=0;i<A[y].size();i++) ret*=f[A[y][i].num]+1,f[A[y][i].num]=0;
	for(int i=0;i<A[z].size();i++) ret*=f[A[z][i].num]+1,f[A[z][i].num]=0;
	return ret;
}
int a,b,c;
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);n=max(a,max(b,c));
	unsigned int ans=0;
	init();
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++)
				ans+=work(i,j,k);
				ans%=(1<<30);
	cout<<ans<<endl;
}
