#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 500010
using namespace std;
int n,sa[nMax],rank[nMax],height[nMax],t1[nMax],t2[nMax],c[nMax],st[nMax][20],_log[nMax],ans[2*nMax],st2[nMax][20],Stack[nMax],s_cnt,last[nMax],next[nMax];
char s[nMax];
void build_sa()
{
	int m=200;
	int *x=t1,*y=t2;
	for(int i=0;i<m;i++) c[i]=0;
	for(int i=0;i<n;i++) c[x[i]=s[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<n;k<<=1)
	{
		int z=0;
		for(int i=n-1;i>=n-k;i--) y[z++]=i;
		for(int i=0;i<n;i++) if(sa[i]>=k) y[z++]=sa[i]-k;
		for(int i=0;i<m;i++) c[i]=0;
		for(int i=0;i<n;i++) c[x[i]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		z=0;
		swap(x,y);
		x[sa[0]]=z++;
		for(int i=1;i<n;i++) x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&sa[i]+k<n&&sa[i-1]+k<n&&y[sa[i]+k]==y[sa[i-1]+k]? z-1:z++;
		if(z>=n) break;
		m=z;
	}
	for(int i=0;i<n;i++) rank[sa[i]]=i;
	int z=0;
	for(int i=0;i<n;i++)
	{
		if(z)z--;
		if(rank[i]==0) continue;
		while(s[i+z]==s[sa[rank[i]-1]+z]) z++;
		height[rank[i]]=z;
		st[rank[i]][0]=z;
	}
	for(int i=2;i<=n;i++) _log[i]=_log[i>>1]+1;
	for(int i=1;(1<<i)<n;i++)
	for(int j=1;j+(1<<i)<=n;j++)
	st[j][i]=min(st[j][i-1],st[j+(1<<i>>1)][i-1]);
	Stack[0]=-1;
	for(int i=0;i<n;i++)
	{
		while(s_cnt>0&&sa[Stack[s_cnt]]>sa[i]) s_cnt--;
		last[i]=Stack[s_cnt];
		Stack[++s_cnt]=i;
		st2[i][0]=sa[i];
	}
	s_cnt=0;
	for(int i=n-1;i>=0;i--)
	{
		while(s_cnt>0&&sa[Stack[s_cnt]]>sa[i]) s_cnt--;
		next[i]=Stack[s_cnt];
		Stack[++s_cnt]=i;
	}
	for(int i=1;(1<<i)<=n;i++)
	for(int j=0;j+(1<<i)<=n;j++)
	st2[j][i]=min(st2[j][i-1],st2[j+(1<<i>>1)][i-1]);
}
int rmq(int l,int r,int st[][20])
{
	int ls=_log[r-l+1];
	return min(st[l][ls],st[r-(1<<ls)+1][ls]);
}
void solve()
{
	int z=0;
	while(z!=n)
	{
		int le,ri; le=ri=-1;
		int lj=nMax,rj=nMax;
		if(last[rank[z]]!=-1&&rmq(last[rank[z]]+1,rank[z],st)>0)
		{
			le=rmq(last[rank[z]]+1,rank[z],st);
			int l=0,r=last[rank[z]];
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(rmq(mid+1,rank[z],st)!=le) l=mid+1; else r=mid;
			}
			lj=rmq(l,rank[z],st2);
		}
		if(next[rank[z]]!=-1&&rmq(rank[z]+1,next[rank[z]],st)>0)
		{
			ri=rmq(rank[z]+1,next[rank[z]],st);
			int l=next[rank[z]],r=n-1;
			while(l<r)
			{
				if(l+1==r) if(rmq(rank[z]+1,r,st)==ri) {l=r; break;} else break;
				int mid=(l+r)>>1;
				if(rmq(rank[z]+1,mid,st)==ri) l=mid; else r=mid;
			}
			rj=rmq(rank[z],l,st2);
		}
		if(le==ri&&le==-1) {printf("-1 %d ",(int)s[z]); z++; continue;}
		if(le>ri||(le==ri&&lj<rj)) printf("%d %d ",le,lj);
		if(ri>le||(ri==le&&rj<lj)) printf("%d %d ",ri,rj);
		z+=max(le,ri);
	}
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	build_sa();
	solve();
	return 0;
}
