#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

const int N=42;



int n,m,nxt[N],fail[N][2],b[N],inv,c[N],d[N];
long long ans,f[2][150000][N];
bitset<N> a[N],now;	
char s[N];

void dfs(int x)
{
	if (x==n)
	{
		int flag=0,tmp=-1;
		for (int i=0; i<40; i++)
		{
			tmp=fail[tmp+1][now[i]];
			if (tmp==m-1) {flag=1; break;}
		}
		if (flag) ans++;
		return;
	}
	now^=a[x];
	dfs(x+1);
	now^=a[x];
	dfs(x+1);
}

void G()
{
	int tmp=0;
	for (int i=0; i<40; i++)
	{
//		cout << a[0][0] << 'a' << endl;
		for (int j=tmp; j<n; j++)
		  if (a[j][i]==1)
		  {
		  	swap(a[j],a[tmp]);
//		  	cout << j << endl;
		  	break;
		  }
		if (a[tmp][i]==0) continue;
//		cout << i << ' ' << tmp << endl;
//		for (int j=0; j<n; j++) {for (int k=0; k<40; k++) cout << a[j][k]; cout << endl;} cout << endl; system("pause");
		for (int j=tmp+1; j<n; j++) 
		  if (a[j][i]==1)
		    a[j]^=a[tmp];
		b[tmp]=i; 
		tmp++;
		if (tmp==n) break;
	}
	while (n>0)
	{
		int flag=0;
		for (int i=0; i<40; i++) 
		  if (a[n-1][i]==1)
		  {
		  	flag=1;
		  	break;
		  }
//		cout << n << ' ' << flag << endl;
		if (flag) break;
		n--; inv++;
	}
	for (int i=n-1; i>0; i--)
	  for (int j=i-1; j>=0; j--)
	    if (a[j][b[i]]==1)
	      a[j]^=a[i];
//	for (int i=0; i<n; i++) {for (int j=0; j<40; j++) cout << a[i][j]; cout << endl;}
}
	

int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%s",s);
		for (int j=0; j<40; j++) a[i][j]=(s[j]-'0');
	}
	scanf("%d",&m);
	scanf("%s",s);
	int tmp=-1;
	nxt[0]=-1;
	for (int i=1; i<m; i++)
	{
		while (tmp>=0)
		  if (s[tmp+1]==s[i]) break; else
		  tmp=nxt[tmp];
		if (s[tmp+1]==s[i]) tmp++;
		nxt[i]=tmp;
	}
	if (s[0]=='0') fail[0][0]=0; else fail[0][0]=-1;
	if (s[0]=='1') fail[0][1]=0; else fail[0][1]=-1;
//	fail[0][0]=fail[0][1]=-1;
	for (int i=1; i<m; i++) 
	{
		int k=s[i]-'0';
		fail[i][k]=i;
		fail[i][k^1]=fail[nxt[i-1]+1][k^1];
//		cout << i << ' ' << fail[i][0] << ' ' << fail[i][1] << ' ' << nxt[i] << endl;
	}
	G();
//	for (int i=0; i<m; i++) cout << i << ' ' << nxt[i] << endl;
	ans=0;
//	cout << n << endl;
	if (n<=22) dfs(0);
	else
	{
		for (int i=0; i<n; i++) c[b[i]]=1;
//		cout << "n=" << n << endl;
//		for (int i=0; i<40; i++) cout << i << ' ' << c[i] << endl;
		for (int i=n-1; i>=0; i--)
		{
//			for (int j=0; j<40; j++) cout << a[i][j]; cout << endl;
			for (int j=b[i]+1; j<40; j++) 
			  if (!c[j])
//			  {cout << a[i][j];
			    d[i]=((d[i]<<1)|(a[i][j]));
//				} cout <<'a'<< endl;
//			cout << i << ' ' << d[i] << endl;
		}
		int S=(1<<(40-n));
		int tmp=0,g=0,SS=S;
		f[0][0][0]=1;
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<S; j++)
			  for (int k=0; k<=min(m-1,i)+1 ; k++)
			    f[g^1][j][k]=0;
			if ((b[tmp]==i)&&(tmp<n))
			{
				//cout << i << ' ' << tmp << ' ' << d[tmp] << 'a'<< endl; 
				for (int j=0; j<S; j++)
		  	      for (int k=0; k<=min(m-1,i); k++) //{if (f[g][j][k]!=0) cout << i << ' ' << j << ' ' << k << "     " << j << ' ' << fail[k][1]+1 << 'a' << endl;
		  	        f[g^1][j^d[tmp]][fail[k][1]+1]+=f[g][j][k];//}
		  	    for (int j=0; j<S; j++)
		  	      for (int k=0; k<=min(m-1,i); k++) //{if (f[g][j][k]!=0) cout << i << ' ' << j << ' ' << k << "     " << j << ' ' << fail[k][0]+1 << 'b' << endl;
		  	        f[g^1][j][fail[k][0]+1]+=f[g][j][k];//}
		  	    tmp++;
		  	}
		  	else
		  	{
//		  		cout << 'a' << endl;
		  		for (int j=0; j<S; j++)
		  		  for (int k=0; k<=min(m-1,i); k++)
		  		    f[g^1][j][fail[k][0]+1]+=f[g][j][k];
		  		for (int j=(S>>1); j<S; j++)
		  		  for (int k=0; k<=min(m-1,i); k++)
		  		    f[g^1][j-(S>>1)][fail[k][1]+1]+=f[g][j][k];
//		  		for (int j=0; j<S; j++)
//		  		  for (int k=0; k<=min(m-1,i); k++) //{ if ((i==3)&&(j==50637)&&(k==3)) cout << "      " << j << ' ' << fail[k][((j&(S>>1))>0)]+1 << endl; 
//		  		    f[g^1][j][fail[k][((j&(SS>>1))>0)]+1]+=f[g][j][k];//}
//		  		for (int j=(S>>1); j<S; j++)
//		  		  for (int k=0; k<=min(m-1,i)+1; k++)
//		  		    f[g^1][j-(S>>1)][k]+=f[g^1][j][k];
//		  		for (int j=(S>>1); j<S; j++)
//		  		  for (int k=0; k<=min(m-1,i)+1; k++)
//		  		    f[g^1][j][k]=0;
//		  		S>>=1;
//		  		cout << S << endl;
				S>>=1;
//				SS>=1;
		  	}
//			if (i==2) cout << "        " << f[g^1][50637][3] << endl;
		  	if (i+1>=m)
		  	{
		  		long long gg=0;
		  		for (int j=0; j<S; j++) gg+=f[g^1][j][m];
		  		ans+=gg*(((long long) 1<<(n-tmp)));
		  	}
		  	for (int k=0; k<=m; k++)
		  	{
		  		long long gg=0;
		  		for (int j=0; j<S; j++) gg+=f[g^1][j][k];
//		  		cout << i << ' ' << k << ' ' << gg << endl;
		  	}
//		  	cout << i << ' ' << ans << endl;
//		  	cout <<endl;
		  	g^=1;
		} 
	}
	for (int i=0; i<inv; i++) ans<<=1;
	printf("%lld\n",ans);
	return 0;
}
