#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000001];
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("bl.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;){
		int x=0,y=0;
		for(int j=1,k;j<i;j++){
			for(k=0;s[j+k]==s[i+k];k++);
			if(k>x)x=k,y=j;
		}
		if(!x)printf("-1 %d ",s[i]);
		else printf("%d %d ",x,y-1);
		i+=max(1,x);
	}
}
