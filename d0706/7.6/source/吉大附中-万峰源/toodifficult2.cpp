#include<bits/stdc++.h>
#define N 110000
using namespace std;
typedef long long ll;
char str[N];
vector<int>a[26];
void out(int x,int deep)
{
	if(deep<0)	return ;
	out(x>>1,deep-1);
	printf("%c",'0'+(x&1));
}
int cmp(int x,int y)
{
	if(x==y)	return 0;
	while(str[x]==str[y])
		x++,y++;
	return str[x]<str[y];
}
int main()
{
	freopen("toodifficult2.in","r",stdin);
	freopen("toodifficult.out","w",stdout);
	for(int c=0;c<10;c++)
	{
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++)
		{
			a[str[i]-'a'].push_back(i+1);
//			cerr<<str[i]-'a'<<' '<<i+1<<endl;
		}
		for(int i=0;i<26;i++)
		{
			cerr<<c<<" "<<i<<endl;
			sort(a[i].begin(),a[i].end(),cmp);
			for(auto x : a[i])
			{
				out(x,15);
			}
			if(i!=25)
				printf("1111111111111111");
			a[i].clear();
		}
		puts("");
	}
	return 0;
}
