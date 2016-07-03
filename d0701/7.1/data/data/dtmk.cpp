#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
int n=3000,m=3000,K=4;
int main(){
	freopen("data.in","w",stdout);
	cout<<2<<endl;
	for (;K<=5;K++){
		cout<<n<<" "<<K<<" "<<m<<endl;
		srand(time(0));
		for (int i=1;i<=n;i++) cout<<rand()%K<<" "; cout<<endl;
		for (int i=1;i<=m;i++){
			int k1,k2,k3;
			k2=rand()%n+1,k3=rand()%n+1;
			if (k2>k3) swap(k2,k3);
			k1=rand()%3+1;
		/*	if (k1==1) k1+=rand()%1; else k1++;
			int lim=0;
			if (i>=m/3) lim=20000;
			while (k3-k2<=lim) k2=rand()%n+1,k3=rand()%n+1;
			*/
			int k4=rand()%K;/*
			if (k1==2&&K==4){
				if (i<=m-10000){
					while (k4==0||(k4==2&&rand()%5)) k4=rand()%K;
				} else while (k4==0&&rand()%5) k4=rand()%K;
			}*/
			if (k1==3) cout<<k1<<" "<<k2<<" "<<k3<<endl;
			else cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;
		}
	}
	return 0;
}
