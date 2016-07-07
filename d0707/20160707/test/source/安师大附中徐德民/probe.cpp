#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Test,N,E[2005],D[2005],Z[4005],W[4005],C;
int Pan(int x){
	memset(Z,0,sizeof(Z));int i,j;
	for(i=1;i<=x;i++){
		for(j=1;j<=N;j++){
		    if(E[j]==0&&D[j]!=0&&Z[D[j]]==0&&W[D[j]]!=i){Z[D[j]]=1;break;}
		    if(E[j]==1)W[D[j]]=i;
		    }
		if(j<=N)continue;
		for(j=2001;j<=4000;j++)
		    if(Z[j]==0){Z[j]=1;break;}
	    }
	for(i=1;i<=N;i++){
		if(E[i]==1&&D[i]!=0&&Z[D[i]]==1)return 0;
		if(E[i]==1&&D[i]!=0){Z[D[i]]=1;continue;}
		if(E[i]==0&&D[i]!=0&&Z[D[i]]==0)return 0;
		if(E[i]==0&&D[i]!=0){Z[D[i]]=0;continue;}
		if(E[i]==1){
			for(j=i+1;j<=N;j++){
		        if(E[j]==0&&D[j]!=0&&Z[D[j]]==0&&W[D[j]]!=x+i){Z[D[j]]=1;break;}
		        if(E[j]==1)W[D[j]]=x+i;
		        }
		    if(j<=N)continue;
		    for(j=2001;j<=4000;j++)
		        if(Z[j]==0){Z[j]=1;break;}
		    continue;
		    }
		if(E[i]==0){
			for(j=i+1;j<=N;j++){
				if(E[j]==1&&D[j]!=0&&Z[D[j]]==1&&W[D[j]]!=x+i){Z[D[j]]=0;break;}
				if(E[j]==0)W[D[j]]=x+i;
			    }
			if(j<=N)continue;
			for(j=i+1;j<=N;j++)W[D[j]]=x+i;
			for(j=1;j<=4000;j++)
				if(W[j]!=x+i&&Z[j]==1){Z[j]=0;break;}
			if(j<=4000)continue;
			for(j=N;j>i;j--)
				if(E[j]==0&&D[j]!=0&&Z[D[j]]==1){Z[D[j]]=0;break;}
		    }
	    }
	return 1;
}
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&Test);int i,j,l,r;char c;
	while(Test--){
		scanf("%d",&N);C=0;
		for(i=1;i<=N;i++){
			c=getchar();
			while(c!='E'&&c!='L')c=getchar();
			E[i]=(c=='E');scanf("%d",&D[i]);C+=E[i];C-=1-E[i];
		    }
		l=max(0,-C);r=5000;
		while(l+1<r){
			if(Pan(l+r)/2==1){l=(l+r)/2;continue;}
			r=(l+r)/2;continue;
		    }
		if(l>4000){printf("OTHER\n");continue;}
		printf("%d\n",l+C);
	    }
	return 0;
}

