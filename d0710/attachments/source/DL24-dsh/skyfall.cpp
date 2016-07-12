#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;

bool vis[5001];
int n,a,b,c,p[5001],num[5001],ct;
int map[5001][701];
int sum[25000001];
long long tmp;
long long ans;
const int inf=1073741824;


void euler(int x){
	for (int i=2;i<=x;i++){
		if (!vis[i]){
			ct++;
			p[ct]=i;
			num[i]=ct;
			map[i][ct]=1;
		}
		for (int j=1;j<=ct&&i*p[j]<=x;j++){
			vis[i*p[j]]=1;
		}
	}
}

void make(int x){
	for (int i=4;i<=x;i++){
		if (!num[i]){
			for (int j=1;j<=ct;j++){
				//cout<<i<<" "<<p[j]<<" "<<i%p[j]<<endl;
				if (i%p[j]==0){
					int t1=i/p[j];
					//cout<<i<<endl;
					for (int k=1;k<=ct;k++) map[i][k]=map[t1][k];
					map[i][j]++;
				}
			}
		}
	}
}

void init(){
	cin>>a>>b>>c;
	n=max(max(a,b),c);
	euler(n);
	make(n);
}
clock_t A,B;
int t9;

int main(){
	freopen ("skyfall.in","r",stdin);
	freopen ("skyfall.out","w",stdout);
	ios::sync_with_stdio(false);	

	init();

	for (int i=1;i<=a;i++){
		for (int j=1;j<=b;j++){
			for (int k=1;k<=c;k++){
				int t9=i*j*k;
				if (sum[t9]!=0){
					ans+=sum[t9];
					ans%=inf;
				//	cout<<i<<" "<<j<<" "<<k<<" "<<sum[t9]<<endl;
					continue;
				}
				tmp=1;
				for (int o=1;o<=ct;o++){
					tmp*=map[i][o]+map[j][o]+map[k][o]+1;
					tmp%=inf;
				}
			//	cout<<i<<" "<<j<<" "<<k<<" "<<tmp<<endl;
				sum[t9]=tmp;
				ans+=tmp;
				ans%=inf;
			}
		}
	}
	/*for (int i=1;i<=n;i++){
		cout<<i<<":";
		for (int j=1;j<=ct;j++){
			if (map[i][j]) cout<<p[j]<<"^"<<map[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	/*for (int i=1;i<=n*n;i++){
		if (all[i]>0) cout<<i<<" "<<all[i]<<endl;
	}*/
	cout<<ans<<endl;

	return 0;
}











