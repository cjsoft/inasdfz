#include <stdio.h>
#include <iostream>
#include <cstring>
#include <set>
const int N=1000005;
const int inf=1<<29;
int n,seq[N],sa[N];
int rank[N],cnt[N],r[N];
int ht[N],lg2[N],pw[N],st[N][20];
int len[N],beg[N],pos[N][20];
char s[N];
using namespace std;

set<int> S;
set<int>::iterator it1,it2;
inline int get_lcp(int l,int r)
{
	if (l>r) l^=r^=l^=r;l++;
	return min(st[l][lg2[r-l+1]],st[r-(pw[lg2[r-l+1]])+1][lg2[r-l+1]]);
}
inline int get_pos(int l,int r)
{
	if (l>r) l^=r^=l^=r;l++;
	return min(pos[l][lg2[r-l+1]],pos[r-(pw[lg2[r-l+1]])+1][lg2[r-l+1]]);
}
inline int fl(int p,int l)
{
	register int lb=0,rb=p+1,mid;
	while (lb<rb-1)
	{
		mid=lb+rb>>1;
		if (get_lcp(mid,p)>=l) rb=mid;
		else lb=mid;
	}
	if (get_lcp(rb,p)<l) return inf;
	return get_pos(rb,p);
}
inline int fr(int p,int l)
{
	register int lb=p-1,rb=n+1,mid;
	while (lb<rb-1)
	{
		mid=lb+rb>>1;
		if (get_lcp(p,mid)>=l) lb=mid;
		else rb=mid;
	}
	if (get_lcp(lb,p)<l) return inf;
	return get_pos(lb,p);
}
inline int min(int x,int y){return x<y?x:y;}
inline void get_answer()
{
	register int i,j,lim,l1,l2;
	for (i=0;(1<<i)<=n;i++)
	lg2[1<<i]=i;
	for (i=3;i<=n;i++)
	if (!lg2[i]) lg2[i]=lg2[i-1];
	for (i=1;i<=n;i++) st[i][0]=ht[i];
	if (n<=100000) lim=17;
	else lim=19;
	for (i=0;i<=lim;i++) pw[i]=(1<<i);
	for (j=1;j<=lim;j++)
	for (i=1;i<=n;i++)
	if (i+pw[j-1]<=n) st[i][j]=min(st[i][j-1],st[i+pw[j-1]][j-1]);
	else st[i][j]=st[i][j-1];
	for (i=1;i<=n;i++) pos[i][0]=min(sa[i],sa[i-1]);
	for (j=1;j<=lim;j++)
	for (i=1;i<=n;i++)
	if (i+pw[j-1]<=n) pos[i][j]=min(pos[i][j-1],pos[i+pw[j-1]][j-1]);
	else pos[i][j]=pos[i][j-1];
	S.insert(inf);S.insert(rank[1]);
	printf ("-1 %d ",s[1]);
	for (i=2;i<=n;)
	{
		it1=S.lower_bound(rank[i]);it2=it1;it2--;
		if ((*it1)==inf) len[i]=get_lcp(*it2,rank[i]);
		else
		{
			if ((*it2)==inf) len[i]=get_lcp(*it1,rank[i]);
			else len[i]=max(get_lcp(*it1,rank[i]),get_lcp(*it2,rank[i]));
		}
		if (!len[i]) putchar('-'),putchar('1'),putchar(' '),printf ("%d ",s[i]),S.insert(rank[i]),i++;
		else
		{
			printf ("%d ",len[i]);
			if ((*it1)!=inf && (*it2)!=inf) printf ("%d ",min(fl(rank[i],len[i]),fr(rank[i],len[i]))-1);
			else
			{
				if ((*it1)==inf) printf ("%d ",fl(rank[i],len[i])-1);
				else printf ("%d ",fr(rank[i],len[i])-1);
			}
			for (j=i;j<i+len[i];j++) S.insert(rank[j]);
			i+=len[i];
		}
	}
}
inline void get_suffix_array()
{
	register int i,j,k,lim;s[n+1]='%';
	for (i=1;i<=n;i++) cnt[s[i]-'a'+1]=1;
	for (i=2;i<=26;i++) cnt[i]+=cnt[i-1];
	for (i=1;i<=n;i++) rank[i]=cnt[s[i]-'a'+1];
	for (i=1;i<=n;i++)
	if (cnt[s[i]-'a'+1]==cnt[26]){sa[n]=i;break;}
	fill(cnt,cnt+27,0);
	for (k=1;k+1<=n;k<<=1)
	{
		lim=rank[sa[n]];
		fill(cnt,cnt+1+lim,0);
		for (i=1;i<=n;i++) cnt[rank[i+k]]++;
		for (i=1;i<=lim;i++) cnt[i]+=cnt[i-1];
		for (i=1;i<=n;i++) seq[cnt[rank[i+k]]--]=i;
		fill(cnt,cnt+1+lim,0);
		for (i=1;i<=n;i++) cnt[rank[i]]++;
		for (i=1;i<=lim;i++) cnt[i]+=cnt[i-1];
		for (i=n;i>=1;i--) sa[cnt[rank[seq[i]]]--]=seq[i];
		r[sa[1]]=1;
		for (i=2;i<=n;i++)
		if (rank[sa[i]]==rank[sa[i-1]] && rank[sa[i]+k]==rank[sa[i-1]+k]) r[sa[i]]=r[sa[i-1]];
		else r[sa[i]]=r[sa[i-1]]+1;
		swap(r,rank);
		if (rank[sa[n]]==n) break;
	}
	k=0;
	for (i=1;i<=n;i++)
	{
		if (k) k--;j=sa[rank[i]-1];
		while (s[i+k]==s[j+k]) k++;
		ht[rank[i]]=k;
	}
}
int main()
{
	freopen ("encrypt.in","r",stdin);
	freopen ("encrypt.out","w",stdout);
	scanf ("\n%s",s+1);n=strlen(s+1);
	get_suffix_array();
	get_answer();
	return 0;
}

