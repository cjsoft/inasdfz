#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 25000005
#define ll long long
int n,m,k,l,t,tot,P,a,b,c,s;
ll ans,x;
int flag[N],pri[N/8],pre[N];
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	P=1<<30;
	scanf("%d%d%d",&a,&b,&c);
	n=a*b*c;
	for (int i=2;i<=n;i++){
		if(!flag[i])pri[++tot]=i,pre[i]=i;
		for (int j=1;j<=tot;j++){
			if(pri[j]*i>n)break;
			flag[pri[j]*i]=1;
			pre[pri[j]*i]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
			for (int k=1;k<=c;k++){
				x=(ll)i*j*k;
				s=1;
				while(x>1){
					l=pre[x];
					t=0;
					while(pre[x]==l){
						t++;
						x=x/pre[x];
					}
					s=s*(t+1);
				}
				ans=(ans+s)%P;
			}
	printf("%lld\n",ans);
}
					
