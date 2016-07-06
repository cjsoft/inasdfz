#include<bits/stdc++.h>
#define N 1100
using namespace std;
typedef long long ll;
const int alpha=95;
const char s[alpha+5]="a bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,./\\?;:\"<>[]{}()|-_=+*&^%$#@!~'`";
int rs[N];
string samstr[5];
map<int,string>mp;
int main()
{
	freopen("toodifficult1.out","w",stdout);
	for(int i=0;i<alpha;i++)
		rs[s[i]]=i;
	
	freopen("toodifficult1_simple.in","r",stdin);
	for(int i=0;i<5;i++)
		getline(cin,samstr[i],'\n');
	fclose(stdin);
	
	freopen("toodifficult1_simple.out","r",stdin);
	for(int i=0;i<5;i++)
	{
		string temp;
		getline(cin,temp,'\n');
		for(int a=0,b=0;a<samstr[i].size();a++,b+=8)
		{
			mp[rs[samstr[i][a]]]=string(temp.begin()+b,temp.begin()+b+8);
		}
	}
	fclose(stdin);
	
	freopen("toodifficult1.in","r",stdin);
	for(int i=0;i<10;i++)
	{
		string temp;
		getline(cin,temp,'\n');
		for(int a=0;a<temp.size();a++)
		{
			cout<<mp[rs[temp[a]]];
		}
		cout<<endl;
	}
	return 0;
}
