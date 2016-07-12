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
struct Binary{
	static const int L=29, mod=(1<<L)-1;
	int n, a[100005];
	inline void mul3_plus1(){
		for (int i=0, d=1;i<=n;i++) a[i]=(a[i]<<1)+a[i]+d, d=a[i]>>L, a[i]&=mod;
		while (n&&!a[n]) n--;n++;
	}
	inline void div2(){
		a[0]>>=1;for (int i=1;i<n;i++) a[i-1]|=(a[i]&1)<<(L-1), a[i]>>=1;
		while (n&&!a[n]) n--;n++;
	}
	inline void mul2(){
		for (int i=0, d=0;i<=n;i++) a[i]=(a[i]<<1)+d, d=a[i]>>L, a[i]&=mod;
		while (n&&!a[n]) n--;n++;
	}
	inline bool equal1(){return n==1&&a[0]==1;}
	inline int count0(){
		int i, ans=0;
		for (i=0;!a[i];i++) ans+=L;
		int t=a[i];
		for (;t;t>>=1, ans++) if (t&1) break;
		return ans;
	}
	inline int clear0(){
		int t=0;
		for (;~a[0]>>t&1;t++);
		if (!t) return 0;
		a[0]>>=t;for (int i=1;i<n;i++) a[i-1]|=(a[i]&((1<<t)-1))<<(L-t), a[i]>>=t;
		while (n&&!a[n]) n--;n++;
		return t;
	}
	void init(int m, char str[]){
		while (m%L) str[++m]='0';
		n=m/L;
		for (int i=0, l=1, r=L;i<n;i++, l+=L, r+=L) for (int j=r;j>=l;j--) a[i]=a[i]<<1|(str[j]-'0');
	}
} A;
char str[500005];
int n;
int main(){
	freopen("yi.in", "r", stdin);
	freopen("yi.out", "w", stdout);
	scanf("%s", str+1), n=strlen(str+1);
	std::reverse(str+1, str+n+1);
	A.init(n, str);
	//for (int i=1;i<=n;i++) A.mul2(), A.a[0]|=str[i]-'0';
	int ans=0;
	while (!A.equal1()){
		if (A.a[0]&1) A.mul3_plus1(), ans++; else A.div2(), ans++;
		//ans+=A.clear0();
		//printf("%d\n", A.count0());
	}
	printf("%d\n", ans);
	return 0;
}
