#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;

const int N=45;

int n,L;
long long ans;
char str[N];
bitset<N> a[N],Lx[N],Rx[N],Tp;

int main(){
freopen("elf.in","r",stdin);
freopen("elf.out","w",stdout);
scanf("%d",&n);
for(register int i=1;i<=n;i++){
	scanf("%s",str+1);
	for(register int j=1;j<=40;j++)if(str[j]=='1')a[i][j]=1;
}
scanf("%d\n%s",&L,str+1);
for(register int i=1;i<=L;i++){if(str[i]=='1'){Lx[1][i]=1;}else Rx[1][i]=1;}
for(register int i=2;i<=41-L;i++){
	for(register int j=i;j<i+L;j++)Lx[i][j]=Lx[i-1][j-1],Rx[i][j]=Rx[i-1][j-1];
}
if(n<=20){
	register int tx=1<<n;
	for(register int i=0;i<tx;i++){
		Tp.reset();
		for(register int j=1;j<=n;j++)if(i&(1<<(j-1)))Tp^=a[j];
		for(register int j=1;j<=41-L;j++){
			if(((~Tp)&Lx[j]).count()==0 && (Tp&Rx[j]).count()==0){ans++;break;}
		}
	}
	printf("%lld\n",ans);
}
else {
	//s
}
return 0;
}

