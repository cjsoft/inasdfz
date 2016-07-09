#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string a;
bool was[201];
int ct,ct2,t3;

int main(){
	freopen ("encrypt.in","r",stdin);
	freopen ("encrypt.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>a;
	int n=a.length();
	for (int i=1;i<=100;i++) a.push_back(' ');
	for (int i=0;i<n;){
	//	cout<<a[i]<<" "<<i<<endl;
		if (!was[a[i]]){
			was[a[i]]=1;
			cout<<"-1 "<<(int)a[i]<<" ";
			i++;
			continue;
		}
		ct=0;
		for (int j=0;j<i;j++){
			if (a[j]==a[i]){
				ct2=0;
				while (a[j+ct2]==a[i+ct2]) ct2++;
				if (ct2>ct){
					ct=ct2;
					t3=j;
				}
			}
		}
		cout<<ct<<" "<<t3<<" ";
		i+=ct;
		//cout<<ct<<endl;
	}
	
	return 0;
}













