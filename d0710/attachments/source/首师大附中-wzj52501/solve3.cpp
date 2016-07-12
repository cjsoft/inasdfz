#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
typedef long long LL;

LL m,fr,to;
const int maxn=120000010;
int mu[maxn],pri[maxn/10],cnt;
bool vis[maxn];
void init(int n) {
	mu[1]=1;
	rep(i,2,n) {
		if(!vis[i]) pri[++cnt]=i,mu[i]=-1;
		rep(j,1,cnt) {
			if(i*pri[j]>n) break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
}
LL mzz(LL n)//mu(x)
{
	return mu[n];
}

LL rzz(LL n,LL s)
{
	LL t=0;
	for(LL i=1;i<=n;i++)
		if(mzz(i)==s)t++;
	return t;
}
int solve(int s) {
	int cnt=0;
	rep(i,1,120000000) if(mu[i]==s) {
		if(++cnt==m) return i;
	}
}
int main()
{
	freopen("thefall3.in","r",stdin);
	freopen("thefall3.out","w",stdout);
	int T;init(120000000);
	for(cin>>T;T--;)
	{
		cin>>m;
		fr=to=0;
		for(LL s=-1,k;s<=1;s++)
		{
			cout<<solve(s);
			if(s==1)cout<<endl;
			else cout<<' ';
		}
	}
	return 0;
}
/*
29 27 34
163 128 161
3378 2612 3327
*/
