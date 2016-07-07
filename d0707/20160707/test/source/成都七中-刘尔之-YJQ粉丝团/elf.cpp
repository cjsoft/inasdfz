#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

ll a[40];
char s[42],z[42];
int p[42],d[42][1<<20];
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	int n,l,m1=0,m2=0;scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%s",s);ll o=0;
		for(int j=0;j<40;j++)o=o<<1|s[j]-'0';
		for(int j=39;~j;j--)if(o>>j&1)
			if(a[j])o^=a[j];else{a[j]=o;break;}
	}
	for(int i=0;i<40;i++)if(!a[i])i<20?m2++:m1++;
	for(int i=0;i<40;i++)for(int j=i+1;j<40;j++)
		if(a[j]>>i&1)a[j]^=a[i];
	scanf("%d%s",&l,s+1);
	for(int i=1;i+i<=l;i++)swap(s[i],s[l-i+1]);
	for(int i=2;i<=l;i++){
		for(p[i]=p[i-1];p[i]&&s[p[i]+1]^s[i];p[i]=p[p[i]]);
		p[i]+=s[p[i]+1]==s[i];}
	for(int i=0;i<1<<m2;i++)for(int j=0;j<1<<20-m2;j++){
		ll o=0;int c=1,x=0;
		for(int k=0,l1=0,l2=0;k<20;k++)
			if(!a[k])o^=(i>>l1++&1)<<k;
			else if(j>>l2++&1)o^=a[k];
		for(int k=1;k<=20;k++)z[k]=o>>k-1&1;
		for(int k=1;k<=20;k++,c++){
			for(c--;c&&s[c+1]^z[k]+'0';c=p[c]);
			c+=s[c+1]==z[k]+'0';if(c==l)x=1;}
		for(c--;c;c=p[c])if(c^l)d[c][i]++;
		if(x)d[l][i]++;
	}
	for(int i=1;i+i<=l;i++)swap(s[i],s[l-i+1]);
	for(int i=2;i<=l;i++){
		for(p[i]=p[i-1];p[i]&&s[p[i]+1]^s[i];p[i]=p[p[i]]);
		p[i]+=s[p[i]+1]==s[i];}
	ll ans=0;
	for(int i=0;i<1<<20-m1;i++){ll o=0,w=0;int c=1,x=0;
		for(int j=0,l1=0;j<20;j++)if(a[j+20])if(i>>l1++&1)o^=a[j+20];
//		for(int i=39;~i;i--)printf("%d",o>>i&1);printf("\n");
		for(int j=19;~j;j--)if(!a[j])w=w<<1|o>>j&1;
		for(int k=1;k<=20;k++)z[k]=o>>40-k&1;
		for(int k=1;k<=20;k++,c++){
			for(c--;c&&s[c+1]^z[k]+'0';c=p[c]);
			c+=s[c+1]==z[k]+'0';if(c==l)x=1;}
		if(c--,x)ans+=1<<20-m2;
		else if(d[l-c][w])ans+=d[l-c][w];
		else ans+=d[l][w];
	}
	cout<<(ans<<m1+m2+n-40);
}
