#include<iostream>
#include<ctime>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

string a;
string b;
int sum;
clock_t B,E;

void once(){
	int t=a.length();
	if (a[t-1]=='0'){
		
		int t2=t;
		for (int i=t-1;i>0;i--){
			if (a[i]!='0'){
				break;
			}
			t2--;
			//cout<<a[t2]<<" "<<t2<<endl;
		}
		sum+=t-t2;
		a.erase(t2,t-t2);
		//cout<<a<<endl;
		return;
	}
	if (a[t-1]=='1'){
		
		sum++;
		a.insert(0,1,'0');
		b=a;
		b.insert(0,1,'0');
		a.push_back('0');
		
		bool flag=0;
		
		for (int i=a.length()-1;i>=0;i--){
			int ct=0;
			if (a[i]=='1') ct++;
			if (b[i]=='1') ct++;
			if (flag) ct++;
			if (ct==0){
				a[i]='0';
			}
			if (ct==1){
				a[i]='1';
				flag=0;
			}
			if (ct==2){
				a[i]='0';
				flag=1;
			}
			if (ct==3){
				a[i]='1';
				flag=1;
			}
		}
		
		a[a.length()-1]++;
		
		for (int i=a.length()-1;i>0;i--){
			if (a[i]=='1') break;
			else{
				a[i]='0';
				a[i-1]++;
			}
		}
		//cout<<a<<endl;
		if (a[0]=='0') a.erase(0,1);
		
		//cout<<a<<endl;
	}
	
}

int main(){
	freopen ("yi.in","r",stdin);
	freopen ("yi.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a;
	while (a.length()!=1){
		once();
	}
	
	cout<<sum<<endl;
	
	return 0;
}











