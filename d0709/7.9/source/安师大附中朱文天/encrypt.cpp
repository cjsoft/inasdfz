#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500005

bool f;
char s[N];

int solve(int i,int len){
	bool f=false;
	int ans;
	for(int j=0;j<i;j++){
		bool f1=true;
		for(int k=0;k<len;k++)
			if(s[i+k]!=s[j+k]){
				f1=false;
				break;
			}
		if(f1){
			ans=j;
			f=true;
			break;
		}
	}
	if(f) return ans;
	else return -1;
}

int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	int i,j,x,y,l,r,mid,len;
	scanf("%s",s);
	len=strlen(s);
	while(i<len){
		x=0,l=1,r=len-i;
		while(l<=r){
			mid=l+r>>1;
			j=solve(i,mid);
			if(j!=-1){
				x=mid,y=j;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(!x) printf("-1 %d ",s[i]),i++;
		else printf("%d %d ",x,y),i+=x;
	}
	return 0;
}				
