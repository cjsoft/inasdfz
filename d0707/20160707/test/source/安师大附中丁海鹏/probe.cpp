#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

char s[1100];
int a[1100],vis[1100],have[1100],T,n,cnt;

void clear(){
	memset(s,0,sizeof(s));
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	cnt=0;
}

int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d\n",&T);
	while(T--){
		clear();
		scanf("%d\n",&n);
		for(int i=1;i<=n;i++){
			scanf("%c %d\n",&s[i],&a[i]);
		}for(int i=1;i<=n;i++){
			if(a[i]==0)continue;
			for(int j=i-1;j>0;j--){
				if(a[i]==a[j]){
					if(s[i]!=s[j]){
						if(s[j]=='E'&&s[i]=='L'){
							vis[j]=vis[i]=1;
						}break;
					}else{
						for(int k=j+1;k<i;k++){
							if(a[k]==0&&s[k]!=s[j]&&!vis[k]){
								if(s[j]=='E')vis[j]=vis[k]=1;
								else vis[k]=vis[i]=1;
								goto abd;
							}
						}printf("OTHER");
						goto abd2;
					}
				}
			}abd:;
		}for(int i=1;i<=n;i++){
			/*if(!vis[i]){
				if(a[i]==0){
					if(s[i]=='L')left++;
					if(s[i]=='E')have[0]++;
				}
			}*/
			if(!vis[i]){
				if(a[i]==0){
					if(s[i]=='L') cnt=max(cnt-1,0);
					else cnt++;
				}else if(s[i]=='L')continue;
				else cnt++;
			}
		}printf("%d\n",cnt);
		abd2:;
	}return 0;
}
