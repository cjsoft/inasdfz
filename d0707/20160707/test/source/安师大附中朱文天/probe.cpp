#include     <cmath>
#include     <queue>
#include    <cstdio>
#include    <vector>
#include   <cstdlib>
#include   <cstring>
#include <algorithm>
using namespace std;
#define N 1005

char s[5];bool f,f1,it[N],is[N],vis1[N],vis2[N];
int T,n,m,ans,id,p,q,a[N],I[N],O[N],pos[N],next[N],head[N*2];

void baoli(){
}

int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		//if(n<=15){
			//baoli();
			//continue;
		//}
		p=q=m=ans=0;
		memset(is,0,sizeof(is));
		memset(head,0,sizeof(head));
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		for(int i=1;i<=n;i++){
			scanf("%s %d",s,&id);
			if(s[0]=='E'){
				if(!id) I[++p]=i;
				else it[++m]=1,pos[m]=i,next[m]=head[id],head[id]=m;
			}
			else{
				if(!id) O[++q]=i;
				else it[++m]=0,pos[m]=i,next[m]=head[id],head[id]=m;
			}
		}
		for(int i=1;i<=2000;i++){
			if(!head[i]) continue;
			int j=head[i],k=0,tmp=0;
			while(j) a[++k]=j,j=next[j];
			f1=true;
			for(int j=k;j;j--){
				if(it[a[j]]){
					tmp++;
					if(tmp==1) continue;
					f=false;
					for(int l=1;l<=q;l++){
						if(vis2[l]) continue;
						if(pos[a[j+1]]<O[l]&&O[l]<pos[a[j]]){vis2[l]=1;f=true;break;}
					}
	                if(!f){f1=false;break;}
	                tmp=1;
	            }
	            else{
	            	tmp--;
	            	if(!tmp) continue;
	            	if(j==k){tmp=0;continue;}
	            	f=false;
					for(int l=1;l<=p;l++){
						if(vis1[l]) continue;
						if(pos[a[j+1]]<I[l]&&I[l]<pos[a[j]]){vis1[l]=1;f=true;break;}
					}
	                if(!f){f1=false;break;}
	                tmp=0;
	            }
	        }
	        if(!f1){printf("OTHER\n");break;}
	        if(tmp) ans++,is[i]=true;
	    }
		if(f1){
			f1=true;
			for(int j=1;j<=p;j++){
				if(vis1[j]) continue;
				if(!f1){ans++;continue;}
				f=false;
				for(int k=1;k=q;k++){
					if(vis2[k]) continue;
					if(O[k]>I[j]){vis2[k]=1,f=true;break;}
				}
				if(!f) ans++,f1=false;
			}
			if(!f1) printf("%d\n",ans);
			else{
				for(int i=1;i<=2000;i++){
					if(!head[i]) continue;
					if(!is[i]) continue;
					for(int j=1;j<=q;j++){
						if(vis2[j]) continue;
						if(O[j]>pos[head[i]]){
							vis2[j]=0;
							ans--;
							break;
						}
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}	
