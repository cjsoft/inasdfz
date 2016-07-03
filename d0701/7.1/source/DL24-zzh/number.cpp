#include<cstdio>
int kk;
long long tmp;
int cnt;

void get(int k){
	long long s=k;
	tmp=0;
	long long QaQ=1;
	int TaT=0;
	while (k){
		if (k & 1) tmp+=QaQ;
		k=k>>1;
		QaQ*=10;
		++TaT;
	}
	//if (s==22) printf("%I64d!#@!#!@\n",tmp);
	if ((tmp & ((1<<TaT)-1))==s){
		++cnt;
		if (cnt==kk) printf("%I64d\n",tmp);
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&kk);
	cnt=0;
	//printf("%d~\n",10110&22);
	for (int i=1;i<=500000;i++) {
		get(i);
		if (cnt==kk) break;
	}
	return 0;
	
}
