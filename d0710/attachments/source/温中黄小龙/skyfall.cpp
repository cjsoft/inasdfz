#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 5001

bool isntprime[MAXN*MAXN];
int prime[MAXN*MAXN/10],tot_prime;
int m_d[MAXN*MAXN];
int gcd[MAXN][MAXN];
void sift(int n){
	m_d[1]=1;
	for(int i=2;i<=n;++i){
		if(!isntprime[i])prime[++tot_prime]=i,m_d[i]=i;
		for(int j=1;j<=tot_prime&&i*prime[j]<=n;++j){
			isntprime[i*prime[j]]=1;
			m_d[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}


int divs[200],cnt[200],tot;
int query(ll x){
	ll tmp=x; tot=0;
	while(tmp!=1){
		int q=m_d[tmp];
		divs[++tot]=q; cnt[tot]=0;
		while(m_d[tmp]==q)tmp/=m_d[tmp],++cnt[tot];
	}
	ll ans=1;
	for(int i=1;i<=tot;++i)
		ans=ans*(cnt[i]+1);
	return ans;
}

int main(){
	for(int i=0;i!=MAXN;++i)gcd[i][0]=gcd[0][i]=i;
	for(int i=1;i!=MAXN;++i)
		for(int j=1;j!=MAXN;++j)
			if(i>j)gcd[i][j]=gcd[j][i%j];
			else gcd[i][j]=gcd[j%i][i];
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	int A,B,C;scanf("%d%d%d",&A,&B,&C);
	sift(A*B*C);
	unsigned ans=0;
	if(C!=1){
		for(int i=1;i<=A;++i)
			for(int j=1;j<=B;++j)
				for(int k=1;k<=C;++k)
					ans+=query((ll)i*j*k);
	}else{
		for(int i=1;i<=A;++i)
			for(int j=1;j<=B;++j)
				if(gcd[i][j]==1)ans+=query(i)*query(j);
				else ans+=query((ll)i*j);
	}
	cout<<(ans&((1<<30)-1))<<endl;
	return 0;
}
