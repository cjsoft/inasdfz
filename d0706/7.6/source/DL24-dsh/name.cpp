#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int tl,tr,t;
int n,m;
long long sum;
int all[2][200005];
bool now[200005];

int main(){
	freopen ("name.in","r",stdin);
	freopen ("name.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>all[0][i];
	for (int i=1;i<=n;i++) cin>>all[1][i];
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>tl>>tr>>t;
		for (int j=tl;j<=tr;j++){
			if (all[now[j]][j]<=t){
				if (now[j]==0) now[j]=1;
				else now[j]=0;
			}
		}
	}
	
	for (int i=1;i<=n;i++) sum+=all[now[i]][i];
	cout<<sum<<endl;

	return 0;
}


















