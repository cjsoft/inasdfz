#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int S = 28;
const int BIT = (1<<S)-1;
const int maxn = 300005;
int a[maxn],s[maxn],len,L;
char str[maxn];
void div() {
	for (int i=len;i>=1;i--) {
		s[i-1]+=(s[i]&1)<<S;
		s[i]>>=1;
	}
	if (!s[len]) --len;
}
void add() {
	s[1]++;
	for (int i=1;i<=len;i++)
	if (s[i]>BIT) {
		s[i]=0;s[i+1]++;
	}
	if (s[len+1]) ++len;
}
void mul() {
	for (int i=1;i<=len;i++)
		s[i]*=3;
	for (int i=1;i<=len;i++) {	
		s[i+1]+=s[i]>>S;
		s[i]&=BIT;
	}
	if (s[len+1]) ++len;
}
bool comp() {
	return len==1&&s[1]==1;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("yi.in","r",stdin);
		freopen("yi.out","w",stdout);
	#endif
	scanf("%s",str);L=strlen(str);
	for (int i=1;i<=L;i++) a[i]=str[L-i]-'0';
	for (int i=1;i<=L;i+=S) {
		int sum=0;
		for (int j=0;j<S;j++)
			sum|=a[i+j]<<j;
		s[++len]=sum;
	}
	int cnt=0;
	while (!comp()) {
		if (s[1]&1) mul(),add();
		else div();++cnt;
	}
	printf("%d",cnt);
	return 0;
}
