#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=(1<<25),key=25;
vector<int>ans;
struct bignum{
	int A[150],len;
	void set(int k1){
		memset(A,0x00,sizeof A);
		len=1; A[1]=k1;
	}
	void chen(int k1){
		for (int i=1;i<=len;i++) A[i]*=k1;
		for (int i=1;i<=len;i++)
			if (A[i]>=N){
				A[i+1]+=(A[i]>>key);
				A[i]&=(N-1);
			}
		while (A[len+1]) len++;
	}
	int check(int k1){
		return A[k1/key+1]&(1<<k1%key);
	}
	void print(){
	//	cout<<"asd "<<len<<endl;
	//	for (int i=len;i;i--) cout<<A[i]<<" "; cout<<endl;
		while (len){
			int x=0;
			for (int i=len;i;i--){
				int pre=x; x=((x<<key)+A[i])%10;
				A[i]=((pre<<key)+A[i])/10;
			}
			ans.push_back(x);
			while (len&&A[len]==0) len--;
		}
	//	cout<<ans.size()<<endl;
		for (int i=ans.size();i;i--) putchar('0'+ans[i-1]);
		putchar('\n');
	}
}ten,A[500010];
void add(bignum &k1,bignum &k2){
	k1.len=max(k1.len,k2.len);
	for (int i=1;i<=k1.len;i++) k1.A[i]+=k2.A[i];
	for (int i=1;i<=k1.len;i++)
		if (k1.A[i]>=N){
			k1.A[i+1]+=(k1.A[i]>>key);
			k1.A[i]&=(N-1);
		}
	while (k1.A[k1.len+1]) k1.len++;
}
int len,K,pd[510000];
int main(){
	scanf("%d",&K); len=1; A[1].set(0); ten.set(1);
	for (int now=0;;now++){ 
		int pre=len;
		for (int i=1;i<=pre;i++){
			if (pd[i]) continue;
			A[len+1]=A[i]; add(A[len+1],ten);
			if (A[len+1].check(now)){
				len++,K--;
				if (K==0){
					A[len].print(); return 0;
				}
			}
			if (A[i].check(now)) pd[i]=1;
		}
		ten.chen(10);
	}
}
