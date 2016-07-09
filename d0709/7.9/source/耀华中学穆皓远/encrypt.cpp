#include <cstdio>
#include <cstring>
#include <algorithm>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
inline unsigned int getstring(char s[]){
	char w=getchar();
	while (w<'a'||'z'<w) w=getchar();
	unsigned int l=0;
	for (;'a'<=w&&w<='z';w=getchar()) s[++l]=w;
	return l;
}
inline void putuint(unsigned int x){if (x>=10) putuint(x/10);putchar('0'+x%10);}
int n;
const int MAXN=1000005;
char str[MAXN];
namespace Force233{
	struct Range_Minimum_Query{
		int n, maxpow2[MAXN], rmq[20][MAXN];
		inline int query(int l, int r){int t=maxpow2[r-l+1];return std::min(rmq[t][l], rmq[t][r-(1<<t)+1]);}
		void init(int _n, int a[]){
			memcpy(rmq[0]+1, a+1, sizeof(*a)*(n=_n));
			for (int i=2;i<=n;i++) maxpow2[i]=maxpow2[i>>1]+1;
			for (int j=0;1<<j+1<=n;j++) for (int *f=rmq[j+1], *g=rmq[j], i=n-(1<<j+1)+1;i;i--) f[i]=std::min(g[i], g[i+(1<<j)]);
		}
	} RMQ_LCP, RMQ;
	int sa[MAXN], rank[MAXN], height[MAXN];
	inline int LCP(int i, int j){if (rank[i]>rank[j]) std::swap(i, j);return i!=j?RMQ_LCP.query(rank[i]+1, rank[j]):n-i+1;}
	void suffix_array(int n, int m){
		static int c[MAXN], t[2][MAXN], *x=t[0], *y=t[1];
		for (int i=1;i<=n;i++) c[x[i]=str[i]-'a'+1]++;
		for (int i=2;i<=m;i++) c[i]+=c[i-1];
		for (int i=n;i;i--) sa[c[x[i]]--]=i;
		for (int k=1, l=0;k<n;k<<=1, l=0){
			for (int i=n-k+1;i<=n;i++) y[++l]=i;
			for (int i=1;i<=n;i++) if (sa[i]>k) y[++l]=sa[i]-k;
			memset(c+1, 0, sizeof(*c)*m);
			for (int i=1;i<=n;i++) c[x[i]]++;
			for (int i=2;i<=m;i++) c[i]+=c[i-1];
			for (int i=n;i;i--) sa[c[x[y[i]]]--]=y[i];
			std::swap(x, y), x[sa[1]]=m=1;
			for (int i=2;i<=n;x[sa[i++]]=m) if (y[sa[i-1]]!=y[sa[i]]||y[sa[i-1]+k]!=y[sa[i]+k]) m++;
			if (n==m) break;
		}
		for (int i=1;i<=n;i++) rank[sa[i]]=i;
		for (int i=1, k=0;i<=n;height[rank[i++]]=k?k--:0) for (int j=sa[rank[i]-1];str[i+k]==str[j+k];k++);
		RMQ_LCP.init(n, height);
	}
	void solve(){
		suffix_array(n, 26);
		//for (int i=1;i<=n;i++) printf("%d%c", sa[i], " \n"[i==n]);
		//for (int i=1;i<=n;i++) printf("%d%c", height[i], " \n"[i==n]);
		RMQ.init(n, sa);
		printf("%d %d", -1, (int)str[1]);
		for (int l, r, i=2;i<=n;){
			int len=-1, id=str[i];
			if (RMQ.query(1, rank[i])<i){
				l=1, r=rank[i];
				for (int mid;r-l>1;(RMQ.query(mid, rank[i])<i?l:r)=mid) mid=l+r>>1;
				int pos=l, t=LCP(sa[pos], i);
				if (t>=len){
					l=0, r=pos;
					for (int mid;r-l>1;(LCP(sa[mid], i)>=t?r:l)=mid) mid=l+r>>1;
					int num=RMQ.query(r, pos);
					if (t>len||num<id) len=t, id=num;
				}
			}
			if (RMQ.query(rank[i], n)<i){
				l=rank[i], r=n;
				for (int mid;r-l>1;(RMQ.query(rank[i], mid)<i?r:l)=mid) mid=l+r>>1;
				int pos=r, t=LCP(i, sa[pos]);
				if (t>=len){
					l=pos, r=n+1;
					for (int mid;r-l>1;(LCP(i, sa[mid])>=t?l:r)=mid) mid=l+r>>1;
					int num=RMQ.query(pos, l);
					if (t>len||num<id) len=t, id=num;
				}
			}
			if (len>0) putchar(' '), putuint(len), putchar(' '), putuint(id-1), i+=len;
			else putchar(' '), putchar('-'), putchar('1'), putchar(' '), putuint((int)str[i]), i++;
		}
		puts("");
	}
}
int main(){
	freopen("encrypt.in", "r", stdin);
	freopen("encrypt.out", "w", stdout);
	n=getstring(str);
	Force233::solve();
	return 0;
}
