#include<bits/stdc++.h>
#define N 500010
using namespace std;
int n,i,k=1,H[N],A[N],R[2][N],v[N],o,j,t,e,L[N][20],M[N][20],S,r;char s[N];
main()
{
	freopen("encrypt.in","r",stdin);freopen("encrypt.out","w",stdout);
	for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;i++)v[s[i]]++;
	for(i=1;i<=128;i++)v[i]+=v[i-1];for(i=1;i<=n;i++)A[v[s[i]]--]=i;
	for(i=1;i<=n;i++)R[o][A[i]]=R[o][A[i-1]]+(s[A[i]]!=s[A[i-1]]);
	for(e=1;k<n;swap(e,o),k*=2)
	{
		for(i=1;i<=n;i++)v[R[o][H[i]=A[i]]]=i;
		for(i=n;i;i--)if(H[i]>k)A[v[R[o][H[i]-k]]--]=H[i]-k;
		for(i=n-k+1;i<=n;i++)A[v[R[o][i]]--]=i;
		for(i=1;i<=n;i++)R[e][A[i]]=R[e][A[i-1]]+(R[o][A[i-1]]!=R[o][A[i]]||R[o][A[i-1]+k]!=R[o][A[i]+k]);
	}
	for(i=k=1;i<=n;H[R[o][i++]]=k)for(k?k--:1;s[i+k]==s[A[R[o][i]-1]+k]&&i+k<=n;k++);
	for(i=n-1;~i;i--)for(L[i][0]=H[i+1],M[i][k=0]=A[i+1];i+(1<<k+1)<=n;k++)
		L[i][k+1]=min(L[i][k],L[i+(1<<k)][k]),M[i][k+1]=min(M[i][k],M[i+(1<<k)][k]);
	for(i=1;i<=n;)
	{
		for(j=R[o][i],t=S=n,e=19;~e;e--)if(j+(1<<e)<=n&&M[j][e]>i)t=min(t,L[j][e]),j+=1<<e;
		for(t=min(t,L[j][0]),e=19;~e;e--)if(j+(1<<e)<=n&&L[j][e]>=t)S=min(S,M[j][e]),j+=1<<e;
		for(j=R[o][i],r=n,e=19;~e;e--)if(j-(1<<e)>0&&M[j-(1<<e)-1][e]>i)r=min(r,L[j-(1<<e)][e]),j-=1<<e;
		if(r=min(r,L[j-1][0]),r>t)S=n;
		if(r>=t)for(e=19;~e;e--)if(j-(1<<e)>0&&L[j-(1<<e)][e]>=r)S=min(S,M[j-(1<<e)-1][e]),j-=1<<e;
		if(r=max(r,t),!r||S==n)printf("-1 %d ",s[i++]);else printf("%d %d ",r,S-1),i+=r;
	}
}
