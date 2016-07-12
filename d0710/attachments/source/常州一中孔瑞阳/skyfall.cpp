#include<cstdio>
#define N 5000*5000+10
using namespace std;
typedef long long ll;
ll a,b,c,m,ans;
int f[N],num[N],e[N],p[N],t;
void get_prime(){
	num[1]=1;
	for(int i=2;i<=m;i++){
		if(!f[i]){p[++t]=i; e[i]=1; num[i]=2;}
		for(int j=1;j<=t&&i*p[j]<=m;j++){
			f[i*p[j]]=1;
			if(i%p[j]==0){
				num[i*p[j]]=num[i]/(e[i]+1)*(e[i]+2);
				e[i*p[j]]=e[i]+1; break;
			}else{num[i*p[j]]=num[i]*num[p[j]]; e[i*p[j]]=1;}
		}
	}
}
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%lld %lld %lld",&a,&b,&c); m=a*b*c;
	get_prime();
	for(ll i=1;i<=a;i++)
		for(ll j=1;j<=b;j++)
			for(ll k=1;k<=c;k++)
				ans+=num[i*j*k];
	printf("%lld\n",ans%(1<<30));
	return 0;
}
