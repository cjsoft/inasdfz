#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int A[2005],B[2005],C[2005];
struct node
{
	int L,R;	
	bool operator < (const node& ths) const
	{
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		for(int i=L;i<=R;i++)B[i-L]=A[i];
		for(int i=ths.L;i<=ths.R;i++) C[i-ths.L]=A[i];
		sort(B,B+R-L+1);
		sort(C,C+ths.R-ths.L+1);
		for(int i=0;i<min(R-L+1,ths.R-ths.L+1);i++)
		{
			if(B[i]<C[i]) return 1;
			if(B[i]>C[i]) return 0;
		}
		if(R-L+1!=ths.R-ths.L+1)return R-L+1>ths.R-ths.L+1;
		return L<ths.L;
	}
}a[4000000+5];
int tot;
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int n=read(),p=read(),q=read();
	for(int i=1;i<=n;i++) A[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			a[tot++]=(node){i,j};
	sort(a,a+tot);
	for(int i=p-1;i<q;i++) printf("%d %d\n",a[i].L,a[i].R);
	//printf("%lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

