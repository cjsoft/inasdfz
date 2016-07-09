#include<stdio.h>
#include<cstring>
#include<memory.h>
#include<iostream>
using namespace std;

char a[500005];
int t1[500005],t2[500005],s1,s2;
int N,m,i,j,sa[500005],cnt[500005];
int rank[500005],height[500005],ss;

void qsa()
{
	int *x=t1,*y=t2,k,p;
	N=strlen(a)+1;m=128;
	for(i=0;i<N;i++)cnt[x[i]=a[i]]++;
	for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
	for(i=N-1;~i;i--)sa[--cnt[x[i]]]=i;
	for(k=1;k<=N;k*=2)
	{
		p=0;
		for(i=N-k;i<N;i++)y[p++]=i;
		for(i=0;i<N;i++)
			if(sa[i]>=k)y[p++]=sa[i]-k;
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<N;i++)cnt[x[y[i]]]++;
		for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
		for(i=N-1;~i;i--)sa[--cnt[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(i=1;i<N;i++)	
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++);
		if(p>=N)break;
		m=p;
	}
}

void qhe()
{
	int i,j,k;
	for(i=0;i<N;i++)rank[sa[i]]=i;
	for(i=0,k=0;i<N-1;i++)
	{
		if(k)k--;
		j=sa[rank[i]-1];
		while(a[i+k]==a[j+k])k++;
		height[rank[i]]=k;
	}
}

int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",a);
	qsa();
	qhe();
	for(i=0;i<N-1;)
	{
		j=rank[i];
		ss=height[j];
		s2=-1,s1=a[i];
		while(height[j])
		{
			if(sa[j-1]<i)
			{
				if(ss>s2)s1=sa[j-1],s2=ss;
				else if(ss==s2&&sa[j-1]<s1)s1=sa[j-1];
			}
			j--,ss=min(ss,height[j]);
			if(ss<s2)break;
		}
		j=rank[i]+1;
		ss=height[j];
		while(height[j])
		{
			if(sa[j]<i)
			{
				if(ss>s2)s1=sa[j],s2=ss;
				else if(ss==s2&&sa[j]<s1)s1=sa[j];
			}
			j++,ss=min(ss,height[j]);
			if(ss<s2)break;
		}
		printf("%d %d ",s2,s1);
		if(s2==-1)i++;
		else i+=s2;
	}
//	printf("\n%d",height[]);
	return 0;
}
