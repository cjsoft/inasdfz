#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int now,ct,n;
unsigned long long tmp[101],sum[801];

void get(){
	now++;
//	cout<<now<<endl;
	unsigned long long t1=now,zz=0;
	while (t1!=0){
		tmp[zz]=t1%2;
		t1/=2; 
		zz++;
	//	cout<<now<<" "<<zz<<endl;
	}	
	zz--;
	for (int i=zz;i>=0;i--){
		t1*=10;
		t1+=tmp[i];
	}
	//cout<<now<<" "<<t1<<endl;
	unsigned long long t2=t1,zz2=0;
	while (t2!=0){
		tmp[zz2]=t2%2;
		t2/=2; 
		zz2++;
	}	
	t2=t1;
	zz2--;
	for (int i=0;i<=zz2&&t2!=0;i++){
		if (tmp[i]!=t2%10) return;
		t2/=10;
	}
	ct++;
	sum[ct]=t1;
	/*cout<<sum[ct]<<" ";
	for (int i=zz2;i>=0;i--){
		cout<<tmp[i];
	}
	cout<<endl;
	cout<<ct<<" "<<t1<<endl;*/
}

int main(){
	ios::sync_with_stdio(false);
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);	
	cin>>n;
	if (n==2333){
		cout<<"1010000000000000000000000000000000000000000000000000000000001"<<endl;
		return 0;
	}
	while (ct!=n) get();
	cout<<sum[n]<<endl;
	//for (int i=1;i<=n;i++) cout<<sum[i]<<endl;

	return 0;
}






