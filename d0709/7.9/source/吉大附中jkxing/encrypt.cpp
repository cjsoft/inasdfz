#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n,a[N];
char str[N];
int sa[N<<1],rk[N<<1],h[N];
int mn[N][20],lg[N],ans[N<<1],top;
int pos[N],rnd[N],ls[N],rs[N],ml[N],mr[N],val[N],mnp[N],mnv[N],cnt,root;
void get_sa(int lim)
{
	static int SA[N<<1],RK[N<<1];
	for(int i=1;i<=n;i++) h[a[i]]++;
	for(int i=1;i<=lim;i++) h[i]+=h[i-1];
	for(int i=1;i<=n;i++) sa[h[a[i]]--]=i;
	for(int i=1;i<=n;i++) rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]);
	for(int k=1;k<=n;k<<=1)
	{
		for(int i=1;i<=n;i++) h[rk[sa[i]]]=i;
		for(int i=n;i;i--) if(sa[i]>k) SA[h[rk[sa[i]-k]]--]=sa[i]-k;
		for(int i=n-k+1;i<=n;i++) SA[h[rk[i]]--]=i;
		for(int i=1;i<=n;i++) 
			RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
		memcpy(sa,SA,sizeof(SA));
		memcpy(rk,RK,sizeof(RK));
	}
	for(int k=0,j,i=1;i<=n;i++)
	{
		j=sa[rk[i]-1];
		while(a[j+k]==a[i+k]) k++;
		h[rk[i]]=k;if(k) k--;
	}
}
int get_mn(int l,int r)
{
	int t=lg[r-l+1];
	return min(mn[l][t],mn[r-(1<<t)+1][t]);
}
void pushup(int x)
{
	mnp[x]=val[x];mnv[x]=0x3f3f3f3f;ml[x]=mr[x]=pos[x];
	if(ls[x])
	{
		ml[x]=ml[ls[x]];
		mnp[x]=min(mnp[x],mnp[ls[x]]);
		mnv[x]=min(mnv[x],min(mnv[ls[x]],get_mn(mr[ls[x]]+1,pos[x])));
	}
	if(rs[x])
	{
		mr[x]=mr[rs[x]];
		mnp[x]=min(mnp[x],mnp[rs[x]]);
		mnv[x]=min(mnv[x],min(mnv[rs[x]],get_mn(pos[x]+1,ml[rs[x]])));
	}
}
void split(int x,int &a,int &b,int v)
{
	if(!x) {a=0;b=0;return;}
	if(mr[x]<=v) {a=x;b=0;return;}
	else if(ml[x]>v) {b=x;a=0;return;}
	else if(pos[x]<v) 
	{
		a=x;
		split(rs[x],rs[a],b,v);
		pushup(a);
	}
	else 
	{
		b=x;
		split(ls[x],a,ls[b],v);
		pushup(b);
	}
}
void merge(int &x,int a,int b)
{
	if(!a||!b) x=a+b;
	else if(rnd[a]<rnd[b]) 
	{
		x=a;merge(rs[x],rs[a],b);
		pushup(x);
	}
	else
	{
		x=b;merge(ls[x],a,ls[b]);
		pushup(x);
	}
}
int get_pos0(int x,int v,int last)
{
	int ans=sa[mr[x]];
	while(x)
	{
		if(rs[x])
		{
			if(mnv[rs[x]]>=v&&get_mn(mr[rs[x]]+1,last)>=v)
			{
				if(get_mn(pos[x]+1,ml[rs[x]])<v) return min(ans,mnp[rs[x]]);
				else ans=min(ans,min(val[x],mnp[rs[x]])),last=pos[x],x=ls[x];
			}
			else x=rs[x];
		}
		else
		{
			if(get_mn(pos[x]+1,last)<v) return ans;
			else ans=min(ans,val[x]),last=pos[x],x=ls[x];
		}
	}
	return ans;
}
int get_pos1(int x,int v,int last)
{
	int ans=sa[ml[x]];
	while(x)
	{
		if(ls[x])
		{
			if(mnv[ls[x]]>=v&&get_mn(last+1,ml[ls[x]])>=v)
			{
				if(get_mn(mr[ls[x]]+1,pos[x])<v) return min(ans,mnp[ls[x]]);
				else ans=min(ans,min(val[x],mnp[ls[x]])),last=pos[x],x=rs[x];
			}
			else x=ls[x];
		}
		else
		{
			if(get_mn(last+1,pos[x])<v) return ans;
			else ans=min(ans,val[x]),last=pos[x],x=rs[x];
		}
	}
	return ans;
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",str+1);n=strlen(str+1);
	for(int i=1;i<=n;i++) a[i]=str[i]-'a'+1;
	get_sa(26);
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) mn[i][0]=h[i];
	for(int j=1;j<20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++) 
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
	for(int i=1;i<=n;i++) 
	{
		int a=0,b=0;
		split(root,a,b,rk[i]);
		int mx=0,p=0x3f3f3f3f,tmp;
		if(a) 
		{
			mx=get_mn(mr[a]+1,rk[i]);
			p=get_pos0(a,mx,rk[i]);
		}
		if(b)
		{
			if((tmp=get_mn(rk[i]+1,ml[b]))>mx)
			{
				mx=tmp;
				p=get_pos1(b,mx,rk[i]);
			}
			else if(tmp==mx) p=min(p,get_pos1(b,mx,rk[i]));
		}
		if(mx) 
		{
			ans[++top]=mx,ans[++top]=p-1;
			merge(root,a,b);
			while(mx--) 
			{
				a=0,b=0;
				pos[++cnt]=rk[i];val[cnt]=i;
				rnd[cnt]=rand();	
				mnp[cnt]=i;mnv[cnt]=0x3f3f3f3f;
				ml[cnt]=mr[cnt]=rk[i];a=0;b=0;
				split(root,a,b,rk[i]);
				merge(a,a,cnt);
				merge(root,a,b);
				i++;
			}
			i--;
		}
		else
		{
			ans[++top]=-1,ans[++top]=str[i];
			pos[++cnt]=rk[i];val[cnt]=i;
			rnd[cnt]=rand();
			mnp[cnt]=i;mnv[cnt]=0x3f3f3f3f;
			ml[cnt]=mr[cnt]=rk[i];
			merge(a,a,cnt);merge(root,a,b);
		}
	}
	for(int i=1;i<=top;i++) printf("%d ",ans[i]);
	puts("");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
