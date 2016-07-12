#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

const int N=10005;

char s[N];
int n,ans;
long long cnt;
bitset <N> b,tmp;

bool pd()
{
	if ((n==1)&&(s[0]=='1')) return 0;
	return 1;
}

int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s),flag=0; n=len;
//	bitset <(unsigned int) n> b,tmp;
	for (int i=len-1; i>=0; i--) b[len-i-1]=(s[i]-'0');
	while (b!=1)
	{
//		cout << 'x' << endl;
		ans++;
//		if ((!flag)&&(n<=18)) {cout << "gg" << ans << endl; return 0;flag=1;}
//		cout << "b="; for (int i=20-1; i>=0; i--) cout << b[i]; cout << endl; system("pause");
//		cout << b << endl; system("pause");
		if (!b[0]) 
		{
			n--;
			b>>=1; 
			cnt++;
		}
		else
		{
			tmp=(b<<1);
			tmp[0]=1;
			b=b^tmp;
			tmp=((b^tmp)&(tmp));
			cnt+=4;
			n++;
			while (tmp!=0)
			{
//				cout << "b="; for (int i=20-1; i>=0; i--) cout << b[i]; cout << endl; 
//				cout << "f="; for (int i=20-1; i>=0; i--) cout << tmp[i]; cout << endl; 
				tmp<<=1;
				b=b^tmp;
				tmp=((b^tmp)&(tmp));
				cnt+=4;
//				cout << "b="; for (int i=20-1; i>=0; i--) cout << b[i]; cout << endl; 
//				cout << "f="; for (int i=20-1; i>=0; i--) cout << tmp[i]; cout << endl;  cout << endl;
//				cout << 'a' << ' ' << (tmp==0) << endl;
				if (tmp==0) break;
//				cout << 'b' << endl;
			}
//			cout << 'c' << n << endl;
			if (b[n]==1) n++;
//			cout << 'd' << endl;
		}
	}
//	cout << cnt << endl;
	printf("%d\n",ans);
	return 0;
}
			  	
			
				
	
	
	
	
	
	
	
	
	
	
	
	
	/*getline(cin,s);
	n=s.size();
	int maxx=n;
	while (pd())
	{
		ans++;
//		cout << s << endl; system("pause");
		if (s[n-1]=='0') 
		{
			n--;
			s.erase(n,1);
			cnt++;
		} 
		else
		{
			ss=s;
			s.insert(n,"1");
			ss.insert(0,"0");
			n++;
			int tmp=0;
			for (int i=n-1; i>=0; i--)
			{
				int x=(s[i]-'0')+(ss[i]-'0')+tmp;
				tmp=0;
				if (x>1) 
				{
					tmp=1; 
					x-=2;
				}
				s[i]=((char) (x+'0'));
				cnt++;
			}
			if (tmp==1)
			{
				s.insert(0,"1");
				n++;
				cnt++;
			}
		}
		maxx=max(maxx,n);
	}
	cout << cnt << endl;
	cout << maxx << endl;
	cout << ans << endl;
	return 0;
}*/
