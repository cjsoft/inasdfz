#include<cstdio>
#include<cstring>
#define t 30
int a[300001],b[300001],l;
char s[300010];
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1),ans=0;l=(len-1)/t+1;
	for(int i=1;i<=len;i++)
		a[(len-i)/t+1]|=s[i]-'0'<<(len-i)%t;
	for(;l^1||a[1]^1;)if(ans++,a[1]&1){
		memcpy(b+1,a+1,l<<2);b[l+1]=0;
		for(int i=l;i;i--)a[i]<<=1,a[i+1]|=a[i]>>t&1,a[i]&=(1<<t)-1;
		l+=a[l+1];b[1]++;
		for(int i=1;b[i]>>t&1;i++)b[i+1]+=1,b[i]&=(1<<t)-1;
		for(int i=1;i<=l;i++)a[i]+=b[i],a[i+1]+=a[i]>>t&1,a[i]&=(1<<t)-1;
		l+=a[l+1];
	}
	else{
		for(int i=1;i<=l;i++)a[i]>>=1,a[i]|=(a[i+1]&1)<<t-1;
		l-=!a[l];
	}
	printf("%d",ans);
}
