#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100005;
char s[maxn];
int len,n,lans,pans;
int t[maxn],sa[maxn],cnt[maxn],wv[maxn],wa[maxn],wb[maxn],Rank[maxn],height[maxn];
void DA(int *r,int n,int m)
{
	int *x=wa,*y=wb,p;
	for(int i = 0; i < m; i++)cnt[i]=0;
	for(int i = 0; i < n; i++)cnt[x[i]=r[i]]++;
	for(int i = 1; i < m; i++)cnt[i]+=cnt[i-1];
	for(int i = n-1; i >= 0; i--)sa[--cnt[x[i]]]=i;
	for(int j = 1; j < n; j<<=1)
	{
		p=0;
		for(int i = n-j; i < n; i++) y[p++]=i;
		for(int i = 0; i < n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(int i = 0; i < n; i++) wv[i]=x[y[i]];
		for(int i = 0; i < m; i++) cnt[i]=0;
		for(int i = 0; i < n; i++) cnt[wv[i]]++;
		for(int i = 1; i < m; i++) cnt[i]+=cnt[i-1];
		for(int i = n-1; i >= 0; i--) sa[--cnt[wv[i]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(int i = 1; i < n; i++)
			x[sa[i]]=((y[sa[i]]==y[sa[i-1]])&&(y[sa[i]+j]==y[sa[i-1]+j]))?p-1:p++;
		if(p>=n)break;
		m=p;
	}
}
void calheight(int *r,int n)
{
	for(int i = 1; i <= n; i++)Rank[sa[i]]=i;
	//for(int i = 0; i <= n; i++)cout<<Rank[i]<<' ';
	//cout<<endl;
	int i,j,k=0;
	for(i=0; i < n; height[Rank[i]]=k,i++)
		for(k?k--:k=0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	//for(int i = 0; i <= n; i++)cout<<height[Rank[i]]<<' ';
	//cout<<endl;
}
void cal(int x)
{
	int temp=height[Rank[x]];lans=0;
	for(int i = Rank[x]; i >= 0; i--)
	{
		temp=min(temp,height[i]);
		if(temp<lans)break;
		if(temp==lans)pans=min(pans,sa[i-1]);
		//cout<<i<<' '<<sa[i-1]<<' '<<sa[i]<<' '<<temp<<endl;
		if(temp>lans && sa[i-1]<=x)lans=temp,pans=sa[i-1];
	}
	temp=height[Rank[x]+1];
	//cout<<Rank[x]+1<<endl;
	for(int i = Rank[x]+1; i <= len; i++)
	{
		temp=min(temp,height[i]);
		if(temp<lans)break;
		if(temp==lans)pans=min(pans,sa[i]);
		//cout<<i<<' '<<sa[i-1]<<' '<<sa[i]<<' '<<temp<<endl;
		if(temp>lans && sa[i]<=x)lans=temp,pans=sa[i];
	}
}
int main(void)
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	for(int i = 0; i < len; i++) t[i]=s[i]-'a'+1;
	//for(int i = 0; i < len; i++) printf("%d ",t[i]);
	//cout<<len<<endl;
	t[len]=0;
	DA(t,len+1,'a'+26);
	calheight(t,len);
	printf("-1 %d",s[0]);
	for(int i = 1; i < len; i+=max(lans,1))
	{
		cal(i);
		if(lans)printf(" %d %d",lans,pans);
		else printf(" -1 %d",s[i]);
	}
	printf("\n");
	return 0;
}
