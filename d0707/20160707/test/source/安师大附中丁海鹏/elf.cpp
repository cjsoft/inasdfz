#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

long long a[50];
int f[50],n,m,ans;
char s[50][50],tar[50],c[50];

void init(){
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%s\n",s[i]+1);
		for(int j=1;j<=40;j++){
			s[i][j]-='0';
		}
	}scanf("%d\n",&m);
	scanf("%s\n",tar+1);
	for(int i=1;i<=m;i++)tar[i]-='0';
}

int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	init();
	memset(f,0,sizeof(f));
	while(!f[n+1]){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				for(int j=1;j<=40;j++){
					c[j]^=s[i][j];
				}
			}
		}for(int i=1;i<=40-m+1;i++){
			int flag=0;
			for(int j=1;j<=m;j++){
				if(tar[j]!=c[i+j-1]){
					flag=1;break;
				}
			}if(!flag){ans++;break;}
		}f[1]++;int i=1;
		while(f[i]==2)f[i]=0,f[++i]++;
	}printf("%d\n",ans);
	return 0;
}
