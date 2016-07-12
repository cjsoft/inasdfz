#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

int ch,n,a[1000009],tot;
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	ch=getchar();
	while(ch<'0' || ch>'1') ch=getchar();
	while(ch>='0' && ch<='1') a[++n]=ch-'0',ch=getchar();
	for (int i=1;i<=n;i++){
		if (i<n-i+1) swap(a[i],a[n-i+1]);	
	}
	int ans=0,l=1;
	while(l!=n){
		ans++;
		if (a[l]==0){
			tot++;
			l++;
		}
		else{
			int p=0;
			for (int i=l;i<=n || p;i++){
				if (i>n) n=i;
				a[i]=a[i]*3+p;
				p=a[i]>>1;
				a[i]=a[i]&1;
			}
			a[l]++;
			p=a[l]>>1;
			a[l]=a[l]&1;
			for (int i=l+1;p;i++){
				if (i>n) n=i;
				a[i]+=p;
				p=a[i]>>1;
				a[i]&=1;
			}
		}
	}
	printf("%d\n",ans);
//	fprintf(stderr,"%.3f",(double)clock()/CLOCKS_PER_SEC);
	//	printf("%d\n",tot);
}
