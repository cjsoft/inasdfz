#include<bits/stdc++.h>
#define N 100010
using namespace std;
int a[N],b[N],l[N],r[N],w[N],j,n,q,i;
long long F;
char c;
void G(int&x)
{
	for(c=getchar();c<48||c>57;c=getchar());
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
}
main()
{
	for(freopen("name.in","r",stdin),freopen("name.out","w",stdout),cin>>n,i=1;i<=n;i++)G(a[i]);
	for(i=1;i<=n;i++)G(b[i]);
	for(cin>>q,i=1;i<=q;i++)G(l[i]),G(r[i]),G(w[i]);
	for(i=1;i<=q;i++)for(j=l[i];j<=r[i];j++)if(a[j]<=w[i])a[j]^=b[j]^=a[j]^=b[j];
	for(i=1;i<=n;i++)F+=a[i];cout<<F;
}
