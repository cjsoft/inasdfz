#include<cstdio>
#include<cstring>

const int maxn=26000000;
const int saffah=1073741823;

int prime[2100000],d[maxn];
bool isprime[maxn];
int tot;
int A,B,C;
int ans;

void euler(int n){
	memset(isprime,true,sizeof(isprime));
	memset(d,0,sizeof(d));
	isprime[1]=false;
	tot=0;
	d[1]=1;
	for (int i=2;i<=n;i++){
		if (isprime[i]){
			prime[++tot]=i;
			d[i]=2;
		}
		for (int j=1;j<=tot;j++){
			if (i*prime[j]>n) break;
			isprime[i*prime[j]]=false;
			d[i*prime[j]]=d[i]*d[prime[j]];
			if (!(i % prime[j])){
				d[i*prime[j]]-=d[i/prime[j]];
				break;
			}
		}
	}
}

int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	euler(A*B*C);
	int ans=0;
	for (int i=1;i<=A;i++) for (int j=1;j<=B;j++) for (int k=1;k<=C;k++){
		ans+=d[i*j*k];
		ans&=saffah;
	}
	printf("%d",ans);
	return 0;
}

