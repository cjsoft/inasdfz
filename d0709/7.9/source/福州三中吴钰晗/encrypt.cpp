#include<bits/stdc++.h>
using namespace std;
int n;
char z[500005];
int sa[500005],h[500005],rank[500005];
int w,mi[1<<20];
int ll[500005][19],rr[500005][19],lo[500005];
inline int minh(int l,int r)
{
	if(l==100000000||r==100000000)return -2;
	
	int s=lo[r-l+1];//cout<<"minh"<<l<<" "<<r<<" "<<s<<" "<<ll[r][s]<<" "<<rr[l][s]<<endl;
	return min(ll[r][s],rr[l][s]);
	/*int ss=100000000;
	for(int i=l;i<=r;i++)ss=min(ss,h[i]);
	return ss;*/
}
void plu(int x,int s)
{
	for(x+=w;x;x>>=1)
	    mi[x]=min(mi[x],s);
}
int ps;
int wa[500005],wb[500005],wv[500005],ss[500005];
int r[500005];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&(a+l>n?0:r[a+l])==(b+l>n?0:r[b+l]);}
void hz(int *r,int *sa,int n,int m)
{
	int i,j,p,*x=wa,*y=wb;
	for(i=1;i<=n;i++)ss[x[i]=r[i]]++;
	for(i=2;i<=m;i++)ss[i]+=ss[i-1];
	for(i=n;i;i--)sa[ss[x[i]]--]=i;
	for(j=1,p=0;p<n;j<<=1,m=p)
	   {
		for(p=0,i=n-j+1;i<=n;i++)y[++p]=i; 
		for(i=1;i<=n;i++)if(sa[i]>j)y[++p]=sa[i]-j;
		for(i=1;i<=n;i++)wv[i]=x[y[i]];
		for(i=1;i<=m;i++)ss[i]=0;
		for(i=1;i<=n;i++)ss[wv[i]]++;
		for(i=2;i<=m;i++)ss[i]+=ss[i-1]; 
		for(i=n;i;i--)sa[ss[wv[i]]--]=y[i];
		for(swap(x,y),p=1,x[sa[1]]=1,i=2;i<=n;i++)
		    x[sa[i]]=(cmp(y,sa[i-1],sa[i],j)?p:++p);
	   }
	for(int i=1;i<=n;i++)rank[sa[i]]=i;
	for(int i=1;i<=n;i++)
	   {int k=h[rank[i-1]]-1,la=sa[rank[i]-1];//cout<<i<<" "<<la<<endl;
	    if(rank[i]==1){h[rank[i]]=0;continue;}
	    for(k=max(k,0);z[la+k]==z[i+k];k++);
	    h[rank[i]]=k;//cout<<k<<"_____"<<rank[i]<<" "<<h[rank[i]]<<endl;
	   }
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",&z[1]);n=strlen(z+1);
	//for(int i=1;i<=n;i++)sa[i]=i;
	//sort(&sa[1],&sa[n+1],cmp);
	//for(int i=1;i<=n;i++)rank[sa[i]]=i;
	//for(int i=2;i<=n;i++)
	//   {h[i]=high(sa[i-1],sa[i]);}
	for(int i=1;i<=n;i++)r[i]=z[i]-'a'+1;
	hz(r,sa,n,26);
	//   printf("sa: ");for(int i=1;i<=n;i++)printf("%d ",sa[i]);cout<<endl;
	//printf("HI: ");for(int i=1;i<=n;i++)printf("%d ",h[i]);cout<<endl;
	
	//printf("ra: ");for(int i=1;i<=n;i++)printf("%d ",rank[i]);cout<<endl;
	for(w=1;w<=n+3;w<<=1);
	for(int i=1;i<w*2;i++)mi[i]=100000000;
	
	for(int i=2;i<=n+1;i++)lo[i]=lo[i/2]+1;
	for(int i=1;i<=n;i++)ll[i][0]=rr[i][0]=h[i];
	for(int i=1;i<=lo[n+1];i++)
	    for(int j=1;j<=n;j++)
	       {ll[j][i]=ll[j][i-1];
	        rr[j][i]=rr[j][i-1];
	        if(j-(1<<i-1)>0)ll[j][i]=min(ll[j][i],ll[j-(1<<i-1)][i-1]);
	        if(j+(1<<i-1)<=n)rr[j][i]=min(rr[j][i],rr[j+(1<<i-1)][i-1]);
		   }
	ps=1;
	for(int i=1;i<=n;i++)
	   {int anw=100000000;
	    int len=0,wi=rank[i];//if(i==30)cout<<endl<<endl<<wi<<endl;
		for(int x=wi+w;x>1;x>>=1)
		   {if(x&1)
		       {int s=minh(mi[x-1]==100000000?100000000:rank[mi[x-1]]+1,wi);//cout<<"A";
			    if(s!=-2)
				   {int ss=0;
				    int y=x-1;
				    while(1)
				       {len=max(len,ss=minh(mi[y]==100000000?100000000:rank[mi[y]]+1,wi));
						//if(i==41)cout<<"B"<<ss<<endl;
						if(y>=w)break;
						if(mi[y*2+1]==100000000)
			       			y=y*2;
			       		else
			       		    y=y*2+1;
					   }
				    break;
				   }
			   }
		   }
		for(int x=wi+w;x>1;x>>=1)
		   {if(!(x&1))
		       {int s=minh(wi+1,mi[x+1]==100000000?100000000:rank[mi[x+1]]);//cout<<"B";
			    if(s!=-2)
				   {//if(i==41)cout<<s<<"B";
				    int y=x+1;
				    while(1)
				       {int ss=0;
					    len=max(len,ss=minh(wi+1,mi[y]==100000000?100000000:rank[mi[y]]));
					    //if(i==41)cout<<"A"<<ss<<endl;
						if(y>=w)break;
					    if(mi[y*2]==100000000)
			       			y=y*2+1;
			       		else
			       		    y=y*2;
					   }
				    break;
				   }
			   }
		   }
		/*for(int j=1;j<i;j++)
		   {
		    if(rank[j]<wi)
			   len=max(len,minh(rank[j]+1,wi));
			else
			   len=max(len,minh(wi+1,rank[j]));
		   }*/
		for(int x=wi+w;x>1;x>>=1)
		   {if(x&1)
		       {int s=minh(mi[x-1]==100000000?100000000:rank[mi[x-1]]+1,wi);
			    if(s!=-2)
				   {if(s==len)
				       {anw=min(anw,mi[x-1]);/*if(i==30)cout<<endl<<anw<<" "<<mi[x-1]<<"C"<<endl;*/}
					else
					   {int y=x-1;
					    while(1)
					       {if(y>=w)break;
						    int ss=minh(mi[y*2+1]==100000000?100000000:rank[mi[y*2+1]]+1,wi);
							if(ss==len||ss==-2)
				       			{//if(i==30&&ss!=-2)cout<<endl<<anw<<" "<<rank[mi[y*2+1]]<<" "<<mi[y*2+1]<<"B"<<endl;
								if(ss!=-2)anw=min(anw,mi[y*2+1]);y=y*2;}
				       		else
				       		    y=y*2+1;
						   }
					   	break;
					   }
				   }
			   }
		   }
		for(int x=wi+w;x>1;x>>=1)
		   {if(!(x&1))
		       {int s=minh(wi+1,mi[x+1]==100000000?100000000:rank[mi[x+1]]);
			    if(s!=-2)
				   {if(s==len)
				       {anw=min(anw,mi[x+1]);/*if(i==30)cout<<endl<<anw<<" "<<mi[x+1]<<"D"<<endl;*/}
					else
					   {int y=x+1;
					    while(1)
					       {if(y>=w)break;
						    int ss=minh(wi+1,mi[y*2]==100000000?100000000:rank[mi[y*2]]);
						    if(ss==len||ss==-2)
				       			{/*if(i==30)cout<<endl<<anw<<" "<<mi[y*2]<<"A"<<endl;*/if(ss!=-2)anw=min(anw,mi[y*2]);y=y*2+1;}
				       		else
				       		    y=y*2;
						   }
					   	break;
					   }
				   }
			   }
		   }
		if(ps==i)
		   {if(len<=0)
		        printf("-1 %d ",z[i]),ps++;
		    else
		        printf("%d %d ",len,anw-1),ps+=len;
		   }
	    plu(rank[i],i);
	    //cout<<endl<<endl;
	    //cout<<endl;if(i==41)break;
	   }
	return 0;
}
