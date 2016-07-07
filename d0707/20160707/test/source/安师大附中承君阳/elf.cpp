#include<bits/stdc++.h>
using namespace std;
long long a,b[44],q[44],x,S,m,f[2][41][65536];
int n,i,j,k,l,t,p[44],r,la[44],y[44],now;
char s[44];
void Turn(){for(scanf("%s",s),a=0,j=0;j<l;j++)a=a*2+s[j]-48;}
void out(long long x,int y){if(y)out(x/2,y-1),cout<<x%2;}
void Dfs(int i,long long x)
{
	if(i==t)
	{
		for(j=0;j<41-l;x>>=1,j++)if(!(x&m^a))
		{
			S++;
			break;
		}
	}
	else Dfs(i+1,x^q[i]),Dfs(i+1,x);
}
main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	for(cin>>n,l=40,i=1;i<=n;i++)for(Turn(),j=39;~j;j--)if(a>>j&1)if(b[j])a^=b[j];
	else
	{
		b[j]=a;
		break;
	}
	for(j=39;j;j--)for(k=j-1;~k;k--)if(b[j]>>k&1)b[j]^=b[k];
	for(j=39;~j;j--)if(b[j])q[t++]=b[j];else p[r++]=j;
	if(cin>>l,m=(1ll<<l)-1,Turn(),t<25)for(Dfs(0,0),i=1;i<=n-t;i++)S*=2;
	else
	{
		for(la[0]=j=-1,i=1;i<l;i++)
		{
			while((~j)&&(s[j+1]!=s[i]))j=la[j];
			if(s[j+1]==s[i])j++;
			la[i]=j;
		}
		for(i=39;~i;i--)for(j=0;j<r;j++)if(b[i]>>p[j]&1)y[i]|=1<<j;
		f[0][0][0]=1;
		int o=0,e=1;
		for(i=39;~i;i--)
		{
			if(memset(f[e],0,sizeof(f[e])),b[i])
			{
				for(j=0;j<l;j++)for(k=0;k<(1<<r);k++)if(f[o][j][k])
				{
					if(s[j]&1)
					{
						f[e][j+1][k^y[i]]+=f[o][j][k];
						if(j)f[e][la[j-1]+1][k]+=f[o][j][k];
						else f[e][0][k]+=f[o][j][k];
					}
					else
					{
						if(j)f[e][la[j-1]+1][k^y[i]]+=f[o][j][k];
						else f[e][0][k^y[i]]+=f[o][j][k];
						f[e][j+1][k]+=f[o][j][k];
					}
				}
				for(k=0;k<(1<<r);k++)if(f[o][l][k])
				{
					f[e][l][k^y[i]]+=f[o][l][k];
					f[e][l][k]+=f[o][l][k];
				}
			}
			else
			{
				for(j=0;j<l;j++)for(k=0;k<(1<<r);k++)if(f[o][j][k])
				{
					if((k>>now&1)==(s[j]&1))f[e][j+1][k]+=f[o][j][k];
					else if(j)f[e][la[j-1]+1][k]+=f[o][j][k];
					else f[e][0][k]+=f[o][j][k];
				}
				for(k=0;k<(1<<r);k++)if(f[o][l][k])f[e][l][k]+=f[o][l][k];
				now++;
			}
			swap(o,e);
		}
		for(j=0;j<1<<r;j++)S+=f[o][l][j];
	}
	cout<<S;
}//233333333333
