#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define u first
#define v second
#define N 100010
using namespace std;
long long p,q,b=1e9+9,P[N],s,K[N],k,S[N*25],G;
int n,a[N],i,j,l[N],m[N],r[N],L[N*25],R[N*25],T[N],M,x,g[N*25];
void B(int&x,int y,int l,int r,int p)
{
	int m=l+r>>1;
	if(L[x=++M]=L[y],R[x]=R[y],l==r)S[x]=S[y]+K[l],g[x]=g[y]+1;
	else p>m?B(R[x],R[y],m+1,r,p):B(L[x],L[y],l,m,p),S[x]=S[L[x]]*P[r-m]+S[R[x]];
}
int C(int a,int b,int c,int d,int l,int r)
{
	if(l==r)return g[b]-g[a]>g[d]-g[c]||g[b]-g[a]==g[d]-g[c]&&i<j;
	int m=l+r>>1;
	return S[L[b]]-S[L[a]]==S[L[d]]-S[L[c]]?C(R[a],R[b],R[c],R[d],m+1,r):C(L[a],L[b],L[c],L[d],l,m);
}
struct D{bool operator()(const pii&a,const pii&b){return C(T[i=b.u-1],T[b.v],T[j=a.u-1],T[a.v],1,n);}};
set<pii,D>E;pii f,t[N];
main()
{
	freopen("lian.in","r",stdin);freopen("lian.out","w",stdout);
	for(cin>>n>>p>>q,i=P[0]=1;i<=n;i++)P[i]=b*P[i-1],K[i]=(rand()<<15)+rand()+1;
	for(G=1ll*n*(n+1)/2,i=1;i<=n;i++)scanf("%d",a+i),l[i]=i,r[i]=n,B(T[i],T[i-1],1,n,a[i]);
	while(1)
	{
		for(s=0,i=1;i<=n;i++)s+=r[i]-l[i]+1;
		if(s<2)break;
		for(k=(((1ll*rand()<<15)+rand()<<15)+rand())%s+1,s=0,i=1;i<=n;i++)if(k>r[i]-l[i]+1)k-=r[i]-l[i]+1;
		else
		{
			k+=l[i]-1;
			break;
		}
		for(x=l[j=1]-1;j<=n;m[j]=x,s+=x-l[j]+1,j++)
		{
			if(x<l[j]-1)x++;
			while(x<r[j]&&C(T[i-1],T[k],T[j-1],T[x+1],1,n))x++;
		}
		if(s<=G-q)for(G-=s,i=1;i<=n;i++)l[i]=m[i]+1;
		else for(i=1;i<=n;i++)r[i]=m[i];
	}
	for(x=1;x<=n;x++)if(l[x]<=n)E.insert(mp(x,l[x]));
	for(x=1;x<=q-p+1;x++)if(t[x]=f=*E.begin(),E.erase(E.begin()),l[f.u]<n)E.insert(mp(f.u,++l[f.u]));
	for(i=q-p+1;i;i--)printf("%d %d\n",t[i].u,t[i].v);
}//Di Zhi Suo Hang , Cong Wo Zuo Qi
