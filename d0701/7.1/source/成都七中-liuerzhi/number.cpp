#include<cstdio>
#include<algorithm>
#define Z 23
#define N 1200001
#define fz(x,y)for(int i=0;i<Z;i++)x.a[i]=y.a[i]
#define F for(int i=0;i<Z;i++)
using namespace std;
int s[2*N],w[2*N];
long long o[50];
struct gj{int a[Z];}b[N],p[30*Z];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k,t=1;scanf("%d",&k);
	b[1].a[0]=p[0].a[0]=1;
	for(int ii=1;ii<30*Z;ii++){
		F o[i]=1ll*p[ii-1].a[i]*10;
		F{if(i+1<Z)o[i+1]+=o[i]>>30;o[i]&=(1<<30)-1;}
		F p[ii].a[i]=o[i];
	}
	s[s[0]=2]=1;
	for(int l=0,he;;l++){he=w[0]=0;
		for(int ii=1;ii<=s[0];ii++){int u=s[ii];
			if(b[u].a[l/30]>>l%30&1&&!(--k)){
				for(int i=l;~i;i--)printf("%d",b[u].a[i/30]>>i%30&1);
				return 0;
			}
			if(b[u].a[(l+1)/30]>>(l+1)%30&1)continue;
			s[++he]=++t;fz(b[t],b[u]);
			w[++w[0]]=++t;fz(b[t],b[u]);
			F{b[t].a[i]+=p[l+1].a[i];
				if(i+1<Z)b[t].a[i+1]+=b[t].a[i]>>30;
				b[t].a[i]&=(1<<30)-1;
			}
		}
		s[0]=he;
		for(int i=1;i<=w[0];i++)s[++s[0]]=w[i];
	}
}
