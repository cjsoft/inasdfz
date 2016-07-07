#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
int A[5010];//1-in 0-out -1-initial
int T,N;
int ltime[5010];
int L[5010],R[5010],len;
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(A,-1,sizeof(A));
		memset(ltime,0,sizeof(ltime));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		len=0;
		vector<int> E0,L0;
		scanf("%d",&N);
		char c;int x;
		bool GG=0;
		int cnt=0;
		for(int i=1;i<=N;i++){
			scanf("\n%c%d",&c,&x);
			if(GG)continue;
			if(c=='E'){
				if(x==0)E0.push_back(i);
				else{
					if(A[x]==1){
						if(L0.empty())printf("OTHER\n"),GG=1;
						else{
							bool flag=0;
							for(int j=0;j<L0.size();j++)
							if(L0[j]>ltime[x]){
								L0.erase(L0.begin()+j);
								flag=1;
								break;
							}
							if(!flag)printf("OTHER\n"),GG=1;
						}
						ltime[x]=i;
					}
					else A[x]=1,cnt++,ltime[x]=i;
				}
			}
			if(c=='L'){
				if(x==0)L0.push_back(i);
				else{
					if(A[x]==0){
						if(E0.empty())printf("OTHER\n"),GG=1;
						else{
							bool flag=0;
							for(int j=0;j<L0.size();j++)
							if(E0[j]>-ltime[x]){
								E0.erase(E0.begin()+j);
								flag=1;
								break;
							}
							if(!flag)printf("OTHER\n"),GG=1;
						}
						L[++len]=ltime[x];
						R[len]=i;
						ltime[x]=-i;
					}
					else{
						if(A[x]==1){
						cnt--;
						L[++len]=ltime[x];
						R[len]=i;
						ltime[x]=-i;
						}
						A[x]=0;
					}
				}
			}	
		}
		if(!GG){
			int smg=0;
			//for(int i=1;i<=2000;i++)
			//if(A[i]==0&&ltime[i]<=0)smg++;
			//printf("smg=%d\n",smg);
			/*int p=0,q=0;
			while(p<E0.size()&&q<L0.size()){
				int a=E0[p],b=L0[q];
				if(a<b)cnt++,smg++,p++;
				else {if(smg)smg--,cnt--;q++;}
			}
			while(p<E0.size()){
				cnt++,smg++;
				p++;
			}
			while(q<L0.size()){
				if(smg)smg--,cnt--;
				q++;
			}*/
			int p=0,q=0;
			while(p<E0.size()&&q<L0.size()){
				while(q<L0.size()&&E0[p]>L0[q])q++;
				q--;
				if(E0[p]>L0[q])smg++;
				p++;
			}
			//printf("%d %d %d\n",cnt,smg,E0.size());
			printf("%d\n",cnt-smg+E0.size());
		}
	}
	return 0;
}
