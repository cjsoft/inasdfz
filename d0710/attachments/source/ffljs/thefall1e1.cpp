/*
Well begun is half done.
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;

const int M=13999;//2333*6+1

int n,ans,a[2500][2500],p[2500];
int	xds[2000*4];
int tell(int f1,int f2)
{	int ans=0;
	f1+=1023;
	f2+=1023;
	int f3=1;
	while (f1<=f2){
		while ((f1%(f3*2)==0)&&(f1+f3*2<=f2+1)){
			f3=f3<<1;
		}
		while (!((f1%f3==0)&&(f1+f3<=f2+1))){
			f3=f3>>1;
		}
		ans+=xds[f1/f3];
		f1=f1+f3;
	}
	return ans;
	
}

int sgn()
{
	int sz=1023;
	for (int i)
	int s=0;
	for(int i=1;i<n;i++){
		s+=tell()
		
	}
		//for(int j=i+1;j<=n;j++)
			//if(p[i]>p[j])s++;
	return s%2;
}

int main()
{
	int T,t;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			p[i]=i;
		ans=0;
		do
		{
			t=1;
			for(int i=1;i<=n;i++)
				t=t*a[i][p[i]]%M;
			if(sgn())ans=(ans-t+M)%M;
			else ans=(ans+t)%M;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<endl;
	}
	return 0;
}

