#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
long long A[1<<20],B[1<<21],*Ans[1<<21];
void Solve(long long *b,long long **a,int size,int pnt)
{
	if(size==1)
	{
		*a[0]=b[0];
		return;
	}
	//printf("%d %d\n",size,pnt);
	//for(int i=0;i<size;i++)printf("%d ",b[i]);puts("");
	long long *NewB=b+size,**NewA=Ans+(pnt+size),help;
	//puts("BP1");
	for(int i=0;i<(size>>1);i++)NewB[i]=(b[i<<1]+b[(i<<1)+1]-b[size-1]+b[size-2])/2,NewA[i]=a[i<<1];
	//puts("BP2");
	Solve(NewB,NewA,size/2,pnt+size);
	//puts("BP3");
	help=NewB[(size>>1)-1];
	//puts("BP4");
	for(int i=0;i<(size>>1);i++)NewB[i]=b[size-1]-b[i<<1]-(help-NewB[i]),NewA[i]=a[(i<<1)+1];
	//puts("BP5");
	Solve(NewB,NewA,size/2,pnt+size);
	//puts("BP6");
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int n=read();
	for(int i=0;i<n;i++)B[i]=read(),Ans[i]=&A[i];
	Solve(B,Ans,n,0);
	for(int i=0;i<n;i++)printf("%d ",A[i]);
}
