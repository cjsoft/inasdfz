#include<cstdio>
/*int main(){
	freopen("data.out","w",stdout);
	for (int i=1;i<=623333;i++) printf("miao\n");
	return 0;
}
*/

const int saffah=87523187;

int TaTaT;
int n,k,m,mm;
int s[50];
int zz[50];
int hash[saffah];

void init(){
	scanf("%d%d%d",&n,&k,&mm);
	for (int i=1;i<=n;i++) scanf("%d",s+i);
	for (m=1;m<=mm;m++){
		int op;
		int l,r;
		scanf("%d%d%d",&op,&l,&r);
		if (op==1){
			int x;
			scanf("%d",&x);
			for (int i=l;i<=r;i++) {
				s[i]+=x;
				s[i]%=k;
			}
		}
		else if (op==2){
			int x;
			scanf("%d",&x);
			for (int i=1;i<=r;i++){
				s[i]*=x;
				s[i]%=k;
			}
		}
		else {
			int ans=0;
			for (int i=l;i<=r;i++) zz[i-l]=s[i];
			int len=r-l+1;
			//for (int i=0;i<len;i++) printf("%d ",zz[i]);
			//printf("\n");
			for (int zt=1;zt<=(1<<len)-1;zt++){
				int tmp=0;
				for (int i=0;i<len;i++){
					tmp%=saffah;
					if (zt & (1<<i)){
						tmp*=k+1;
						tmp+=zz[i]+1;
					}
				}
				//printf("%d~%d\n",zt,tmp);
				if (hash[tmp]!=m){
					++ans;
					hash[tmp]=m;
				}
			}
			printf("%d\n",ans);
		}
	}
}




int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&TaTaT);
	while (TaTaT--){
		init();
	}
	return 0;
}
