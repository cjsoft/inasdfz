#include<bits/stdc++.h>
#define A(x,y,z) e[++t]=y,l[t]=h[x],h[x]=t,c[t]=z,e[++t]=x,l[t]=h[y],h[y]=t,c[t]=0
#define N 2333333
using namespace std;
char o[9];
int a[N],w[N],e[N],l[N],v[N],f[N],c[N],h[N],t,A,T,i,j,n,s,d[N];
void Init()
{
	t=1;
	memset(h,0,sizeof(h));
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
}
int Sap(int x,int F)
{
	if(x==T)return F;
	int r=0,t,i;
	for(i=h[x];i;i=l[i])if(c[i]&&f[x]==f[e[i]]+1)if(t=Sap(e[i],min(F-r,c[i])),c[i]-=t,c[i^1]+=t,(r+=t)>=F||f[0]>T)return r;
	if(!--v[f[x]])f[0]=T+1;++v[++f[x]];
	return r;
}
main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	for(cin>>A;A--;)
	{
		for(cin>>n,T=n+1,s=0,Init(),i=1;i<=n;i++)scanf("%s%d",o,w+i),a[i]=d[i]=o[0]=='E';
		for(i=1;i<=n;i++)if(a[i]%2&&w[i])
		{
			for(j=i+1;j<=n&&!(a[j]%2&&w[j]==w[i]);j++)if(!a[j]&&w[j]==w[i])
			{
				a[i]=a[j]=2;
				break;
			}
			if(j>n)continue;
			if(a[j]%2&&w[j]==w[i])for(s++;j>i;j--)if(!a[j]&&!w[j])A(i,j,1);
		}
		else if(!a[i]&&w[i])
		{
			for(j=i-1;j&&!(!d[j]&&w[j]==w[i]);j--);
			if(!d[j]&&w[j]==w[i])for(s++;j<i;j++)if(a[j]&&!w[j])A(i,j,1);
		}
		for(i=1;i<=n;i++)if(w[i])A(0,i,1);else A(i,T,1);
		while(f[0]<=T)s-=Sap(0,1<<30);
		if(s)puts("OTHER");
		else
		{
			for(Init(),i=1;i<=n;i++)if(d[i]&1)
			{
				A(0,i,1);s++;
				for(j=i;j<=n;j++)if(!d[j])if(!w[j]||!w[i]||w[i]==w[j])A(i,j,1);
			}
			else A(i,T,1);
			while(f[0]<=T)s-=Sap(0,1<<30);
			cout<<s<<endl;
		}
	}
}
//SapDaFaHao
