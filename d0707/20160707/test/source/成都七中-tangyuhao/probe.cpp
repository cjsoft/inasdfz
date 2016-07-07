#include <cstdio>
#include <algorithm>

using namespace std;

struct rec{
	int type,x,use;
}a[1009],b[2009];
int last[2009],n,T,ch;
int readint(){
	int ch=getchar(),ret=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
bool chk(int x){
	for (int i=1;i<=x;i++){
		b[i].type=1;
		b[i].x=0;
		b[i].use=0;
	}
	for (int i=1;i<=n;i++){
		b[i+x]=a[i];
	}
#define n (n+x)
	for (int i=1;i<=2000;i++) last[i]=0;
	//solve use l 0
	for (int i=1;i<=n;i++){
		if (b[i].x && last[b[i].x] && b[last[b[i].x]].type==1 && b[i].type==1){
			bool suc=0;
			for (int j=last[b[i].x]+1;j<i;j++){
				if (b[j].type==0 && b[j].x==0 && !b[j].use){
					b[j].use=1;
					suc=1;
					break;
				}
			}
			if (!suc) return false;
		}
		last[b[i].x]=i;
	}
	//solve l 0 use e 0
	/*int persum=0,h=0;
	for (int i=1;i<=n;i++){
		if (b[i].type==0 && b[i].x==0 && !b[i].use){
			persum--,h++;
			b[i].use=1;
		}
		if (b[i].type==1 && b[i].x==0) persum++;
		if (persum<0) return false;
	}
	for (int i=1;i<=n;i++){
		if (!h) break;
		if (b[i].type==1 && b[i].x==0){
			b[i].use=1,h--;
		}
	}*/
	//if (h) return false;
	//solve other
	for (int i=1;i<=2000;i++) last[i]=0;
	for (int i=1;i<=n;i++){
		if ((b[i].x==0 && b[i].type==0 && !b[i].use)||(b[i].x && ((last[b[i].x] && b[last[b[i].x]].type==0 && b[i].type==0) || (b[i].type==0 && !last[b[i].x])))){
			bool suc=0;
			for (int j=last[b[i].x]+1;j<i;j++){
				if (b[j].type==1 && b[j].x==0 && !b[j].use){
					b[j].use=1;
					suc=1;
					break;
				}
			}
			if (!suc) 
				return false;
		}
		last[b[i].x]=i;
		last[0]=0;
	}
	return true;
#undef n
}
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		n=readint();
		int d=0;
		for (int i=1;i<=n;i++){
			ch=getchar();
			while(ch!='L' && ch!='E') ch=getchar();
			if (ch=='L') a[i].type=0,d--;
			else a[i].type=1,d++;
			a[i].x=readint();
		}
		chk(3);
		if (!chk(n)){
			printf("OTHER\n");
			continue;
		}
		int l=0,r=n;
		while(r-l>1){
			int mid=(l+r)>>1;
			if (chk(mid)) r=mid;
			else l=mid+1;
		}
		if (chk(l)){
			printf("%d\n",l+d);
		}
		else{
			printf("%d\n",r+d);
		}
	}
}
