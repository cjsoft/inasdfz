#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 4010,M = 310;
struct Node{
	int x,y;
	Node(){}
	Node(int x,int y):x(x),y(y){}
};
bool operator < (const Node &a,const Node &b){return a.x > b.x;}

priority_queue <Node> q[2];


int num[N],lnum;
ll d[M];
int b[M],c[M];
int a[N][M],len[N],nex[N];
int m,now,siz,tot,ad,f8[1010],power[9],p2[31];
int sum;
void cal(int);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&m);
	power[0] = 1;p2[0] = 1;
	for (int i = 1;i <= 8;i++) power[i] = power[i-1]*10;
	for (int i = 1;i <= 30;i++) p2[i] = p2[i-1]*2;
	for (int i = 1;i <= 1000;i++) f8[i] = (i-1)/8+1;
	
	a[0][1] = 0;len[0] = 1;tot = 0;nex[0] = 500000;
	a[1][1] = 1;len[1] = 1;tot = 1;nex[1] = 500000;ad = 1;
	now = 0;siz = 1;
	q[now].push(Node(0,0));
	q[now].push(Node(1,1));
	for (int i = 2;i <= 4000;i++) num[++lnum] = i;
	while (1){
		if (tot >= m) break;
		siz++;
//		cout << siz << ' ' << q[now].size() << ' '<< tot << ' ' << sum << endl;
		while (!q[now].empty()){
			Node x = q[now].top();q[now].pop();
	//		sum++;
			if (nex[x.y]>siz) {
				int u = num[lnum--];
				for (int j = 1;j <= f8[len[x.y]];j++)
					a[u][j] = a[x.y][j];
				for (int j = f8[len[x.y]]+1;j <= f8[siz];j++) a[u][j] = 0;
				int v = siz%8;if (v == 0) v = 8;v--;
				sum += f8[siz];
				a[u][f8[siz]] += power[v];				
				len[u] = siz; 
				tot++;
				q[now^1].push(Node(tot,u));ad = u;
				q[now^1].push(x);
			//	sum += 2;
				cal(u);
				if (tot >= m) break;
			}
			else{
				num[++lnum] = x.y;
			}
		}
		if (tot >= m) break;
		now ^= 1;
	}
	
	printf("%d",a[ad][f8[len[ad]]]);
	for (int i = f8[len[ad]]-1;i >= 1;i--) printf("%.8d",a[ad][i]);printf("\n"); 
	
	return 0;
}
void cal(int p){
	int cnt = 0,o = len[p]+1;
	for (int i = 1;i <= f8[len[p]];i++){
		c[++cnt] = a[p][i];
		d[cnt] = c[cnt];
	}

	for (int i = 0;i < len[p];i+= 30){
		int w = min(30,len[p]-i);
		w = p2[w];
		for (int j = cnt;j >= 1;j--){
			d[j-1] += d[j]%w*100000000;
			d[j] /= w;
		}
		sum += cnt;
		if (d[cnt] == 0) cnt--;
	}
	for (int i = 1;i <= cnt;i++)
		c[i] = d[i];
	
	sum += cnt;
	
	while(1){
		if ((c[1]&1)) break; 
		for (int i = cnt;i >= 1;i--){
			c[i-1] += (c[i]&1)*100000000;
			c[i] >>= 1;
		}
		if (c[cnt] == 0) cnt--;
		o++;
	}
	sum += o-len[p];
//	cout << o-len[p] << endl;
	nex[p] = o;
}
