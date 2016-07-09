#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int S=128;
int a,b,c,f[500005],j,n,rank[1100000],sa[1100000],lt,rt,st,len,num;
bool used[256],flag[500005]; char z[500005];
struct tree {
	int l,r,lc,rc,lt,rt;
}t[1000005];

int hash[1100000],tr[1100000],h[1100000];
bool cmp(int x,int y,int len) {
	if(x+len>=n)	return 0;
	return rank[x]==rank[y]&&rank[x+len]==rank[y+len];
}

void getsa() {
	int i,k,len,cnt;
	for (i=0;i<n;i++) hash[f[i]]++;
	for (i=0,cnt=-1;i<S;i++)	if(hash[i])	tr[i]=++cnt;
	for (i=1;i<S;i++) hash[i]+=hash[i-1];
	for (i=0;i<n;i++) sa[--hash[f[i]]]=i,rank[i]=tr[f[i]];
	for (len=2;cnt<n-1;len<<=1) {
		memset (hash,0,sizeof(int)*n);
		for (i=0;i<n;i++) hash[rank[i]]++;
		for (i=1;i<n;i++) hash[i]+=hash[i-1];
		for (i=n-1;i>=0;i--) if(sa[i]>=len>>1)	tr[sa[i]-(len>>1)]=--hash[rank[sa[i]-(len>>1)]];
		for (i=1;i<=len>>1;i++)	tr[n-i]=--hash[rank[n-i]];
		for (i=0;i<n;i++) sa[tr[i]]=i;
		for (i=1,cnt=0;i<n;i++)
			tr[sa[i]]=cmp(sa[i-1],sa[i],len>>1)?cnt:++cnt;
		memcpy (rank,tr,sizeof(int)*n);
	}
	for (i=0;i<n;i++) if (rank[i]!=0)
		for (k=max(h[rank[i-1]]-1,1);;k++) {
			if (f[i+k-1]==f[sa[rank[i]-1]+k-1]) h[rank[i]]=k;
			else break;
		}
}

void build(int x,int l,int r) {
	t[x].l=l; t[x].r=r; t[x].lt=t[x].rt=-1;
	if (l==r) t[x].lc=t[x].rc=-1;
	else {
		int mid=(l+r)/2;
		t[x].lc=++num; build (num,l,mid);
		t[x].rc=++num; build (num,mid+1,r);
	}
}

void add(int x,int k) {
	if (t[x].r<k||k<t[x].l) return;
	if (t[x].l==t[x].r) t[x].lt=t[x].rt=k;
	else {
		add (t[x].lc,k); add (t[x].rc,k);
		if (t[t[x].lc].lt==-1)
			t[x].lt=t[t[x].rc].lt;
		else t[x].lt=t[t[x].lc].lt;
		if (t[t[x].rc].rt==-1)
			t[x].rt=t[t[x].lc].rt;
		else t[x].rt=t[t[x].rc].rt;
	}
}

void find(int x,int k) {
	if (t[x].r<=k) if (lt==-1||t[x].rt>lt) lt=t[x].rt;
	if (t[x].l>=k) if (rt==-1||t[x].lt<rt) rt=t[x].lt;
	if (t[x].l<k&&k<t[x].r) {find (t[x].lc,k); find (t[x].rc,k);}
}

inline void check(int i,int j,int &k) {
	int length=0;
	while (i+length<n&&f[i+length]==f[j+length]) length++;
	if (length==len&&(k>j||k==-100000)) k=j;
	if (length>len) {len=length; k=j;}
}

int main() {
	freopen ("encrypt.in","r",stdin);
	freopen ("encrypt.out","w",stdout);
	scanf ("%s",z); n=strlen (z);
	for (a=0;a<n;a++) f[a]=(int)z[a];
	for (a=0;a<n;a++) {
		if (used[f[a]]) flag[a]=true;
		else used[f[a]]=true;
	}
	getsa (); build (0,0,n-1);
	for (st=0,len=1;st<n;st+=len,len=1) {
		if (flag[st]) {
			lt=rt=-1; find (0,rank[st]); j=1;
			if (lt!=-1) check (st,sa[lt],j);
			if (rt!=-1) check (st,sa[rt],j);
			/*
			int ll=0,rr=lt,mid,jj=j;
			while (ll+1<rr) {
				mid=(ll+rr)/2; find (0,mid);
				if (lt!=-1) check (sa[lt],st,j);
				if (rt!=-1) check (sa[rt],st,j);
				if (jj==j) rr=mid-1; else ll=mid+1;
				j=jj;
			}
			find (0,ll);
			if (lt!=-1) check (sa[lt],st,j);
			if (rt!=-1) check (sa[rt],st,j);
			find (0,rank[st]);
			if (rt!=-1) {
				if (lt!=-1) check (sa[lt],st,j);
				ll=rt,rr=n-1,mid,jj=j;
				while (ll+1<rr) {
					mid=(ll+rr)/2; find (0,mid);
					if (lt!=-1) check (sa[lt],st,j);
					if (rt!=-1) check (sa[rt],st,j);
					if (jj==j) rr=mid-1; else ll=mid+1;
					j=jj;
				}
				find (0,ll);
				if (lt!=-1) check (sa[lt],st,j);
				if (rt!=-1) check (sa[rt],st,j);
			}*/
			
			for (a=st+1;a<st+len;a++) add (0,rank[a]);
			printf ("%d %d ",len,j);
		} else printf ("-1 %d ",f[st]);
		add (0,rank[st]);
	}
	return 0;
}
