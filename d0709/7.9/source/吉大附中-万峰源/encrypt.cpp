#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 510000
#define S 128
#define lson l,mid,no<<1
#define rson mid+1,r,no<<1|1
#define debug(...)	fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
char str[N];
int n;
int sa[N],rank[N],hash[N],tr[N],h[20][N];
int LG[N];
int L[N],R[N],preval[N];
int ilen[N];
int mi[N<<2];
namespace SA {
int sa[N], rk[N], ht[N], s[N<<1], t[N<<1], p[N], cnt[N], cur[N];
#define pushS(x) sa[cur[s[x]]--] = x
#define pushL(x) sa[cur[s[x]]++] = x
#define inducedSort(v) fill_n(sa, n, -1); fill_n(cnt, m, 0);                  \
    for (int i = 0; i < n; i++) cnt[s[i]]++;                                  \
    for (int i = 1; i < m; i++) cnt[i] += cnt[i-1];                           \
    for (int i = 0; i < m; i++) cur[i] = cnt[i]-1;                            \
    for (int i = n1-1; ~i; i--) pushS(v[i]);                                  \
    for (int i = 1; i < m; i++) cur[i] = cnt[i-1];                            \
    for (int i = 0; i < n; i++) if (sa[i] > 0 &&  t[sa[i]-1]) pushL(sa[i]-1); \
    for (int i = 0; i < m; i++) cur[i] = cnt[i]-1;                            \
    for (int i = n-1;  ~i; i--) if (sa[i] > 0 && !t[sa[i]-1]) pushS(sa[i]-1)
void sais(int n, int m, int *s, int *t, int *p) {
    int n1 = t[n-1] = 0, ch = rk[0] = -1, *s1 = s+n;
    for (int i = n-2; ~i; i--) t[i] = s[i] == s[i+1] ? t[i+1] : s[i] > s[i+1];
    for (int i = 1; i < n; i++) rk[i] = t[i-1] && !t[i] ? (p[n1] = i, n1++) : -1;
    inducedSort(p);
    for (int i = 0, x, y; i < n; i++) if (~(x = rk[sa[i]])) {
        if (ch < 1 || p[x+1] - p[x] != p[y+1] - p[y]) ch++;
        else for (int j = p[x], k = p[y]; j <= p[x+1]; j++, k++)
            if ((s[j]<<1|t[j]) != (s[k]<<1|t[k])) {ch++; break;}
        s1[y = x] = ch;
    }
    if (ch+1 < n1) sais(n1, ch+1, s1, t+n, p+n1);
    else for (int i = 0; i < n1; i++) sa[s1[i]] = i;
    for (int i = 0; i < n1; i++) s1[i] = p[sa[i]];
    inducedSort(s1);
}
template<typename T>
int mapCharToInt(int n, const T *str) {
    int m = *max_element(str, str+n);
    fill_n(rk, m+1, 0);
    for (int i = 0; i < n; i++) rk[str[i]] = 1;
    for (int i = 0; i < m; i++) rk[i+1] += rk[i];
    for (int i = 0; i < n; i++) s[i] = rk[str[i]] - 1;
    return rk[m];
}
// Ensure that str[n] is the unique lexicographically smallest character in str.
template<typename T>
void suffixArray(int n, const T *str) {
    int m = mapCharToInt(++n, str);
    sais(n, m, s, t, p);
    for (int i = 0; i < n; i++) rk[sa[i]] = i;
    for (int i = 0, h = ht[0] = 0; i < n-1; i++) {
        int j = sa[rk[i]-1];
        while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
        if (ht[rk[i]] = h) h--;
    }
}
};
void init()
{
	memcpy(sa,SA::sa,sizeof(int)*n);
	memcpy(rank,SA::rk,sizeof(int)*n);
	for(int i=0;i<n;i++)
		h[0][i]=SA::ht[i];
	LG[0]=-1;
	for(int i=1;i<n;i++)
	{
		LG[i]=LG[i>>1]+1;
	}
	for(int k=1;k<20;k++)
	{
		for(int i=0;i+(1<<(k-1))<n;i++)
		{
			h[k][i]=min(h[k-1][i],h[k-1][i+(1<<(k-1))]);
		}
	}
}
int LCP(int x,int y)
{
	if(x==y)	return -1;
	if(x>y)	swap(x,y);
	int k=LG[y-x];
	return min(h[k][x+1],h[k][y-(1<<k)+1]);
}
void Pushup(int no)
{
	mi[no]=min(mi[no<<1],mi[no<<1|1]);
}
void Build(int l,int r,int no)
{
	mi[no]=0x3f3f3f3f;
	if(l==r)	return ;
	int mid=l+r>>1;
	Build(lson);
	Build(rson);
}
void update(int l,int r,int no,int k,int val)
{
	if(l==r)
		mi[no]=val;
	else
	{
		int mid=l+r>>1;
		if(k<=mid)	update(lson,k,val);
		else		update(rson,k,val);
		Pushup(no);
	}
}
int query(int l,int r,int no,int st,int en)
{
	if(st<=l&&r<=en)
	{
		return mi[no];
	}
	else
	{
		int mid=l+r>>1;
		if(en<=mid)		return query(lson,st,en);
		else if(st>mid)	return query(rson,st,en);
		else	return min(query(lson,st,en),query(rson,st,en));
	}
}
int getlseg(int st,int en,int x)
{
	int L,R,l,r,mid;
	l=st,r=en;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(LCP(mid,rank[x])>=ilen[x])
			r=mid-1;
		else
			l=mid+1;
	}
	L=l;
	l=L,r=en;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(LCP(mid,rank[x])<=ilen[x])
			l=mid+1;
		else
			r=mid-1;
	}
	R=r;
	if(L>R)	return 0x3f3f3f3f;
	return query(0,n-1,1,L,R);
}
int getrseg(int st,int en,int x)
{
	int L,R,l,r,mid;
	l=st,r=en;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(LCP(mid,rank[x])<=ilen[x])
			r=mid-1;
		else
			l=mid+1;
	}
	L=l;
	l=L,r=en;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(LCP(mid,rank[x])>=ilen[x])
			l=mid+1;
		else
			r=mid-1;
	}
	R=r;
	if(L>R)	return 0x3f3f3f3f;
	return query(0,n-1,1,L,R);
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",str);
	n=strlen(str);
	str[n]='a'-1;
	SA::suffixArray(n, str);
	init();
	for(int i=0;i<n;i++)
	{
		L[i]=i-1;
		R[i]=i+1;
		preval[i]=h[0][i];
	}
	R[n-1]=-1;
	for(int i=n-1;i>=0;i--)
	{
		ilen[i]=-1;
		if(L[rank[i]]!=-1)
		{
			ilen[i]=max(ilen[i],preval[rank[i]]);
		}
		if(R[rank[i]]!=-1)
		{
			ilen[i]=max(ilen[i],preval[R[rank[i]]]);
		}
		if(L[rank[i]]!=-1)
			R[L[rank[i]]]=R[rank[i]];
		if(R[rank[i]]!=-1)
		{
			L[R[rank[i]]]=L[rank[i]];
			if(L[rank[i]]!=-1)
				preval[R[rank[i]]]=min(preval[R[rank[i]]],preval[rank[i]]);
		}
	}
	Build(0,n-1,1);
	for(int i=0;i<n;)
	{
		int start=i;
		if(ilen[i]<=0)
		{
			printf("-1 %d ",str[i]);
			i++;
		}
		else
		{
			int ans=min(getlseg(0,rank[i]-1,i),getrseg(rank[i]+1,n-1,i));
			printf("%d %d ",ilen[i],ans);
			i+=ilen[i];
		}
		while(start<i)
		{
			update(0,n-1,1,rank[start],start);
			start++;
		}
	}
	return 0;
}
