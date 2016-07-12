#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define M (1<<30)
#define maxn 5010
#define LL long long int

using namespace std;

bool check(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return false;
	return true;
}
int pi[710]={0},tt=0;
void getpi(int n){
	for(int i=2;i<=n;i++)
		if(check(i))pi[++tt]=i;
}
int su[maxn][210]={0};
void getsu(int n){
	int i,j,x;
	for(i=2;i<=n;i++){
		j=1,x=i;
		while(j<=tt){
			while(x%pi[j]==0)
				su[i][j]++,x/=pi[j];
			j++;
		}
	}
}
inline int getans(int x,int y,int z){
	int ans=1,s,i;
	for(i=1;i<=tt;i++){
		if(pi[i]>max(x,max(y,z)))break;
		s=su[x][i]+su[y][i]+su[z][i]+1;
		ans=((LL)ans*s)%M;
	}
	return ans;
}
int n,a,b,c;
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	n=max(a,max(b,c));
	getpi(n);
	getsu(n);
	int i,j,k,ans=0;
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
			for(k=1;k<=c;k++)
				ans=((LL)ans+getans(i,j,k))%M;
	printf("%d\n",ans);
	
	return 0;
}
