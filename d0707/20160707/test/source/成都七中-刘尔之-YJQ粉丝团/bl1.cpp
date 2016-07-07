#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

ll a[40];
char s[42];
int main(){
	freopen("elf.in","r",stdin);
	freopen("bl.out","w",stdout);
	int n,l;scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%s",s);ll o=0;
		for(int j=0;j<40;j++)o=o<<1|s[j]-'0';
		a[i]=o;
	}
	ll ans=0;
	scanf("%d%s",&l,s+1);
	for(int i=0;i<1<<n;i++){ll x=0;
		for(int j=0;j<n;j++)if(i>>j&1)x^=a[j];
		for(int j=0;j+l-1<40;j++){
			for(int k=1;k<=l;k++)
				if((x>>j+k-1&1)+'0'^s[l-k+1])goto X;
			ans++;break;X:;
		}
	}
	cout<<ans;
}

