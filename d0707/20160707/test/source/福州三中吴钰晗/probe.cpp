#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while(('0'<=ch&&ch<='9')){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n,m,S,T,TT;
int be[1010],ce[1010],bn[4000005],bv[4000005],bl[4000005],bw=1;
void put(int u,int v,int l)
{ //cout<<u<<" "<<v<<"_"<<l<<endl;
	bw++;bn[bw]=be[u];ce[u]=be[u]=bw;bv[bw]=v;bl[bw]=l;
}
int en[1005],id[1005];
int d[1005];
int spfa()
{
	queue<int>q;
	for(int i=1;i<=T;i++)
	    d[i]=1000000,be[i]=ce[i];
	d[S]=1;
	for(q.push(S);!q.empty();)
	   {int u=q.front();q.pop();
	    for(int i=be[u];i;i=bn[i])
	        if(d[bv[i]]>d[u]+1&&bl[i])
	           {d[bv[i]]=d[u]+1;
	            q.push(bv[i]);
			   }
	   }
	return d[T]!=1000000;
}
int dinic(int u,int f)
{
	if(u==T)
	    return f;
	int sum=0;
	for(int &i=be[u];i&&f;i=bn[i])
	    if(d[bv[i]]==d[u]+1&&bl[i])
	       {int s=dinic(bv[i],min(f,bl[i]));
	        f-=s;sum+=s;
	        bl[i]-=s;bl[i^1]+=s;
		   }
	return sum;
}
int spfa2()
{
	queue<int>q;
	for(int i=1;i<=T;i++)
	    d[i]=1000000,be[i]=ce[i];
	d[n+2]=1;
	for(q.push(n+2);!q.empty();)
	   {int u=q.front();q.pop();
	    for(int i=be[u];i;i=bn[i])
	        if(d[bv[i]]>d[u]+1&&bl[i])
	           {d[bv[i]]=d[u]+1;
	            q.push(bv[i]);
			   }
	   }
	return d[T]!=1000000;
}
int ll[1005],rr[1005];
int ps[100005];
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	TT=read();
	while(TT--)
	   {n=read();
	    for(int i=1;i<=n;i++)
	       {char z[5];scanf("%s",z);
	        en[i]=(z[0]=='E');
	        id[i]=read();
	       }
	    for(int i=1;i<=n;i++)
	       {ll[i]=0;rr[i]=n+1;
	        for(int j=1;j<=n;j++)
	            {
				 if(id[i]==id[j]&&i!=j&&id[i])
	               {if(i<j)
	                   rr[i]=min(rr[i],j);
	                else
	                   ll[i]=max(ll[i],j);
				   }
				}
		   }
	    S=n+3,T=n+4;
		
		for(int i=1;i<=n;i++)
		   {
		    if(en[i])
			   {ps[++ps[0]]=bw+1;put(S,i,1),put(i,S,0);
			    if(rr[i]==n+1)put(i,n+2,1),put(n+2,i,0);//cout<<i<<" "<<n+1<<endl;
			    continue;
			   }
			else
			   {ps[++ps[0]]=bw+1;put(i,T,1),put(T,i,0);
			   }
			for(int j=i-1;j>=1;j--)
		       {if(en[j])
		           {if(id[i]&&id[j])
		               if(id[i]!=id[j])
		                   continue;
		            if(ll[i]>j)break;
		            if(rr[j]<i)continue;
		            //cout<<j<<" "<<i<<endl;
					put(j,i,1);
		            put(i,j,0);
				   }
			   }
			if(ll[i]==0)put(n+1,i,1),put(i,n+1,0);//cout<<0<<" "<<i<<endl;
		   }
		int f2=0,ab;
	    put(n+2,T,n*2),put(T,n+2,0);ab=bw;
		while(spfa())f2+=dinic(S,1000000);
		while(spfa2())bl[ab]-=dinic(n+2,1000000);
		put(S,n+1,n*2),put(n+1,S,0);
		while(spfa())f2+=dinic(S,1000000);
		while(spfa2())bl[ab]-=dinic(n+2,1000000);
		int ans=0;
		for(int i=1;i<=ps[0];i++)
		    if(bl[ps[i]]!=0)
		       ans=1;//cout<<bv[ps[i]^1]<<" "<<bv[ps[i]]<<endl;
		//for(int i=2;i<=bw;i++)
		//    if(bl[i])cout<<bv[i^1]<<"_"<<bv[i]<<endl;
		if(ans)printf("OTHER\n");
		else printf("%d\n",bl[ab]);
		ps[0]=0;bw=1;
		for(int i=1;i<=T;i++)
		    be[i]=ce[i]=0;
	   }
	return 0;
}
