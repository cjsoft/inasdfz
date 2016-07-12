#include<cstdio>
#include<cstring>
#include<cctype>
#include<ctime>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
typedef long long ll;
const int maxn=150010;
const int SIZE=7;
struct bign {
	int s[maxn/6],len;
	bign() {s[0]=0;len=1;}
	void clean() {while(len>1&&!s[len-1]) len--;}
	bign operator * (const int b) const {
		bign c;c.len=len+1;
		rep(i,0,len-1) {
			c.s[i]+=s[i]*b;
			c.s[i+1]=c.s[i]/10000000;
			c.s[i]%=10000000;
		}
		c.clean();return c;
	}
	bign operator + (const bign& b) const {
		bign c;c.len=max(b.len,len)+1;
		rep(i,0,c.len-1) {
			if(i<b.len) c.s[i]+=b.s[i];
			if(i<len) c.s[i]+=s[i];
			c.s[i+1]=c.s[i]/10000000;
			c.s[i]%=10000000;
		}
		c.clean();return c;
	}
	bign operator / (const int b) const {
		bign c;c.len=len;
		int last=0;
		dwn(i,len-1,0) {
			c.s[i]=last+s[i];
			last=(c.s[i]%2)*10000000;
			c.s[i]/=2;
		}
		c.clean();return c;
	}
	void print() {
		printf("%d",s[len-1]);
		dwn(i,len-2,0) printf("%07d",s[i]);
		puts("");
	}
}mul,add,t;
char s[maxn];
int A[maxn],ans;
int main() {
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s+1);int n=strlen(s+1);
	rep(i,1,n) A[i]=s[n-i+1]-'0';
	mul.s[0]=1;t.s[0]=2;
	rep(i,1,n-1) {
		if(A[i]) add=add+mul;
		A[i]=add.s[0]%2;add=add/2;
		if(!A[i]) ans++;
		else {
			add=add*3;add.s[0]+=2;mul=mul*3;
			ans+=2;
		}
		if(i==n-1) {
			if(add.len>1) n++;
			else if(add.len==1&&add.s[0]>1) n++;
			else if(A[i+1]&&mul.s[0]+add.s[0]>1) n++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
