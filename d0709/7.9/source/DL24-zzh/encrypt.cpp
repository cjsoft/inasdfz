#include<cstdio>
#include<cstring>
#include<algorithm>


#define maxLen 200000

char str[maxLen];
int s[maxLen];
int height[maxLen],sa[maxLen],rank[maxLen];
int len;
int st[20][maxLen];
int prelog[maxLen];

void radix(int str[],int a[],int b[],int n,int m){
	static int count[maxLen];
	memset(count,0,sizeof(count));
	for (int i=0;i<n;i++) count[str[i]]++;
	for (int i=1;i<=m;i++) count[i]+=count[i-1];
	for (int i=n-1;i>=0;i--) b[--count[str[a[i]]]]=a[i];
}

void suffix_array(int str[],int sa[],int n,int m){
	static int a[maxLen],b[maxLen];
	for (int i=0;i<n;i++) rank[i]=i;
	radix(str,rank,sa,n,m);
	rank[sa[0]]=0;
	for (int i=1;i<n;i++) rank[sa[i]]=rank[sa[i-1]]+(str[sa[i]]!=str[sa[i-1]]);
	for (int i=1;i<n;i=i<<1){
		for (int j=0;j<n;j++){
			a[j]=rank[j]+1;
			b[j]=j+i>=n? 0 : rank[j+i]+1;
			sa[j]=j;
		}
		radix(b,sa,rank,n,n);
		radix(a,rank,sa,n,n);
		rank[sa[0]]=0;
		for (int j=1;j<n;j++){
			rank[sa[j]]=rank[sa[j-1]]+(a[sa[j-1]]!=a[sa[j]] || b[sa[j-1]]!=b[sa[j]]);
		}
	}
}

void calc_height(int str[],int sa[],int h[],int n){
	int k=0;
	h[0]=0;
	for (int i=0;i<n;i++){
		k= k==0?0:k-1;
		if (rank[i]!=0) while (str[i+k]==str[sa[rank[i]-1]+k]) k++;
		h[rank[i]]=k;
	}
}

void RMQstart(){
	prelog[1]=0;
	for (int i=2;i<len;i++){
		prelog[i]=prelog[i-1];
		if ((1<<(prelog[i]+1))==i) ++prelog[i];
	}
    // (int i=1;i<len;i++) printf("%d ",prelog[i]);
    //printf("\n");
	for (int i=1;i<len;i++) st[0][i]=height[i];
	for (int j=0;(1<<(j+1))<=len-1;j++){
		for (int i=1;i<=len-(1<<(j+1));i++) st[j+1][i]=std::min(st[j][i],st[j][i+(1<<j)]);
	}/*
	for (int j=0;j<=2;j++){
        printf("%d:",j);
        for (int i=1;i<len;i++) printf("%d ",st[j][i]);
        printf("\n");
	}*/
	//for (int j=1; j<<1 <= len-1; j=j<<1)
	//	for (int i=1;i<=len-(j<<1);i++);
}


int lcp(int a,int b){
	a=rank[a];
	b=rank[b];
	if (a>b) std::swap(a,b);
	//printf("$%#@$%d %d\n",a,b);
	int len=b-a;
	++a;
	//int QaQ=log2(len);
	int QaQ=prelog[len];
	//printf("%d\n",QaQ);
	//printf("%d\n",st[6][1]);
	return std::min(st[QaQ][a],st[QaQ][b-(1<<QaQ)+1]);
}



int main(){
    freopen("encrypt.in","r",stdin);
    freopen("encrypt.out","w",stdout);
	scanf("%s",str);
	len=strlen(str);
	for (int i=0;i<len;i++) s[i]=str[i];
	suffix_array(s,sa,len,123);
	calc_height(s,sa,height,len);
	RMQstart();
	//printf("%d~~\n",lcp(1,0));
	//printf("%d!!!%d\n",rank[0],rank[1]);
	//for (int i=0;i<len;i++) printf("%d ",sa[i]+1);
	//printf("\n");
	//for (int i=1;i<len;i++) printf("%d ",height[i]);
	int i=0;
	while (i<len){
		int TAT=0;
		int p=0;
		for (int j=0;j<i;j++){
			int tmp=lcp(i,j);
			if (tmp>TAT) {
				TAT=tmp;
				p=j;
			}
		}
		if (TAT>0){
			printf("%d %d ",TAT,p);
			i+=TAT;
		}
		else {
			printf("-1 %d ",str[i]);
			++i;
		}
	}

	return 0;
}
