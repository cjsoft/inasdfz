#include<bits/stdc++.h>
using namespace std;
#define PA pair<int,int>
#define MP make_pair
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n,m;
int sa[100005],sb[100005],ls[200005];
int op[100005];
LL ans;
queue<int>in[100005],ou[100005];
int w;
int p1[100005],p2[100005];
int top=0;
void insert1(int s1,int s2)
{
	top++;
	p1[top]=s1,p2[top]=s2;
}
void del1(int s1,int s2)
{
	for(int i=1;i<=top;i++)
	    if(p1[i]==s1&&p2[i]==s2)
	       {if(i==top)top--;
	        else swap(p1[i],p1[top]),swap(p2[i],p2[top]),top--;
		   }
}
int que1(int l,int r)
{
	int ma=0;
	for(int i=1;i<=top;i++)
	    if(p1[i]>=l&&p1[i]<=r)
	        ma=max(ma,p2[i]);
	return ma;
}
int que2(int l,int t)
{
	int ss=0;
	for(int i=1;i<=top;i++)
	    if(p1[i]>=l&&p2[i]>t)
	        ss++;
	return ss;
}
vector<int>a[600005];
int que3(int l,int r)
{
	if(l>r)return 0;
	int ma=0;
	for(l+=w-1,r+=w+1;l^r^1;l>>=1,r>>=1)
	   {//cout<<l<<" "<<r<<endl;
	    if(!(l&1))if(!a[l+1].empty())ma=max(ma,*(a[l+1].end()-1));
	    if((r&1))if(!a[r-1].empty())ma=max(ma,*(a[r-1].end()-1));
	    
	   }
	return ma;
}
int que4(int l,int t)
{
	int ss=0;
	for(l+=w-1;l>1;l>>=1)
	   {if(!(l&1))ss+=(a[l+1].end()-upper_bound(a[l+1].begin(),a[l+1].end(),t));
	    //cout<<l<<endl;
	   }
	return ss;
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)ls[++ls[0]]=sa[i]=read();
	for(int i=1;i<=n;i++)ls[++ls[0]]=sb[i]=read();
	ls[++ls[0]]=1000000001;
	sort(&ls[1],&ls[ls[0]+1]);
	for(int i=1;i<=n;i++)
	    sa[i]=(upper_bound(&ls[1],&ls[ls[0]+1],sa[i])-ls-1),
	    sb[i]=(upper_bound(&ls[1],&ls[ls[0]+1],sb[i])-ls-1);
	m=read();
	for(int i=1;i<=m;i++)
	   {int u=read(),v=read(),s=read();
	    op[i]=(upper_bound(&ls[1],&ls[ls[0]+1],s)-ls-1);
	    in[u].push(i);ou[v].push(i);
	   }
	for(w=1;w<n*2+5;w<<=1);
	if(n>2000)
	   {
	   	for(int i=1;i<=m;i++)
	   	   {int j=w+op[i];
	   	    while(j)
	   	       a[j].push_back(i),j>>=1;
		   }
		for(int i=1;i<=w*2;i++)
		    if(!a[i].empty())
		        sort(a[i].begin(),a[i].end());
		for(int i=1;i<=n;i++)
		   {
		    if(sa[i]<sb[i])
			   {int t=que3(sa[i],sb[i]-1);
			    if(t==0)
			       {if(que4(sb[i],t)&1)ans+=ls[sb[i]];
			        else ans+=ls[sa[i]];
				   }
				else
			       if(que4(sb[i],t)&1)ans+=ls[sa[i]];
			       else ans+=ls[sb[i]];
			   }
		    else
		       {int t=que3(sb[i],sa[i]-1);
			    if(que4(sa[i],t)&1)ans+=ls[sb[i]];
			    else ans+=ls[sa[i]];
			   }
	   	   }cout<<ans<<endl;
	   	return 0;
	   }
	for(int i=1;i<=n;i++)
	   {for(;!in[i].empty();in[i].pop())
	       insert1(op[in[i].front()],in[i].front());
		if(sa[i]<sb[i])
		   {int t=que1(sa[i],sb[i]-1);
		    if(t==0)
		       {if(que2(sb[i],t)&1)ans+=ls[sb[i]];
		        else ans+=ls[sa[i]];
			   }
			else
		       if(que2(sb[i],t)&1)ans+=ls[sa[i]];
		       else ans+=ls[sb[i]];
		   }
	    else
	       {int t=que1(sb[i],sa[i]-1);
		    if(que2(sa[i],t)&1)ans+=ls[sb[i]];
		    else ans+=ls[sa[i]];
		   }
		for(;!ou[i].empty();ou[i].pop())
	       del1(op[ou[i].front()],ou[i].front());
	   }
	cout<<ans<<endl;
	return 0;
}

