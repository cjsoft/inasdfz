#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
inline void readi(int &x);
const int maxn=30005,M=998244353;

int n,K,m;

int A[maxn],f[6];

void BF()
{
	register int tp,l,r,x,s,t,i;
	for(int qi=1;qi<=m;qi++)
	{
		readi(tp),readi(l),readi(r);
		if(tp<=2)readi(x);
		if(tp==1)
		{
			for(i=l;i<=r;i++)
				A[i]=(A[i]+x)%K;
		}
		if(tp==2)
		{
			for(i=l;i<=r;i++)
				A[i]=(A[i]*x)%K;
		}
		if(tp==3)
		{
			for(i=0;i<=K;i++)
				f[i]=(i==K);
			s=1;
			for(i=l;i<=r;i++)
			{
				t=(s+s-f[A[i]])%M;
				f[A[i]]=s;
				s=t<0?t+M:t;
			}
			printf("%d\n",(s+M-1)%M);
		}
	}
}

void init()
{
	readi(n),readi(K),readi(m);
	for(int i=1;i<=n;i++)
		readi(A[i]);
}

typedef int Mat[6][6];
Mat tt;
LL temp[6][6];

void mult(Mat &a,Mat &b,Mat &c)
{
	int i,j,k;
	for(i=0;i<=K;i++)
		for(j=0;j<=K;j++)
		{
			temp[i][j]=0;
			for(k=0;k<=K;k++)
				temp[i][j]+=(LL)a[i][k]*b[k][j];
		}
	for(i=0;i<=K;i++)
		for(j=0;j<=K;j++)
			c[i][j]=temp[i][j]%M;
}

struct node
{
	int dta;
	Mat s;
	node *lc,*rc;
	
	inline void tagdta(int d)
	{
		dta+=d;
		for(int i=0;i<=K;i++)
			for(int j=0;j<=K;j++)
				tt[i==K?K:(i+d)%K][j==K?K:(j+d)%K]=s[i][j];
		memcpy(s,tt,sizeof(s));
	}
	
	inline void update()
	{
		mult(lc->s,rc->s,s);
	}
	
	void downdate()
	{
		if(dta)
		{
			lc->tagdta(dta);
			rc->tagdta(dta);
			dta=0;
		}
	}
	
	void Add(int l,int r,const int &a,const int &b,const int &d)
	{
		if(l>=a&&r<=b)tagdta(d);
		else
		{
			int mid=l+r>>1;
			downdate();
			if(a<=mid)lc->Add(l,mid,a,b,d);
			if(b>mid)rc->Add(mid+1,r,a,b,d);
			update();
		}
	}
	
	void Mul(int l,int r,const int &a,const int &b,const int &c)
	{
	}
	
	void Get(int l,int r,const int &a,const int &b,Mat &res)
	{
		if(l>=a&&r<=b)
		{
			mult(res,s,res);
			return;
		}
		int mid=l+r>>1;
		downdate();
		if(a<=mid)lc->Get(l,mid,a,b,res);
		if(b>mid)rc->Get(mid+1,r,a,b,res);
	}
	
}ndl[maxn*4],*ns=ndl,*root;

node* build(int l,int r)
{
	node *x=++ns;
	if(l==r)
	{
		for(int i=0;i<=K;i++)
		{
			x->s[i][i]++;
			x->s[i][A[l]]++;
		}
		x->s[A[l]][A[l]]--;
		return x;
	}
	x->lc=build(l,l+r>>1);
	x->rc=build(l+r+2>>1,r);
	mult(x->lc->s,x->rc->s,x->s);
	return x;
}

void work()
{
	root=build(1,n);
	int tp,l,r,x,i,ans;
	Mat s;
	for(int qi=1;qi<=m;qi++)
	{
		readi(tp),readi(l),readi(r);
		if(tp<=2)readi(x);
		if(tp==1)
		{
			root->Add(1,n,l,r,x);
		}
		if(tp==2)
		{
			root->Mul(1,n,l,r,x);
		}
		if(tp==3)
		{
			memset(s,0,sizeof(s));
			for(int i=0;i<=K;i++)
				s[i][i]=1;
			root->Get(1,n,l,r,s);
			ans=0;
			for(int i=0;i<K;i++)
				ans=(ans+s[K][i])%M;
			if(ans<0)ans+=M;
			printf("%d\n",ans);
		}
	}
}

//#include<ctime>
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int CT;
	for(cin>>CT;CT--;)
	{
		init();
		if(max(n,m)<=10000)BF();
		else work();
	}
	//cout<<clock()<<endl;
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c-'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';}

