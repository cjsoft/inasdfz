#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 53,mod = 998244353;

int f[N][N][N];
int ans[N][N];
int n;
int add(int a,int b){a += b;if (a >= mod ) a -= mod;return a;}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	f[1][1][0] = 1;
	f[2][1][1] = 1;
	f[3][2][1] = 1;
	for (int i = 3;i <= n;i++){
		for (int a = 1;a < i-1;a++)
			for (int j = 1;j < i-a;j++)
				for (int k = 0;k < i-a;k++) 
					if (f[i-a][j][k])
					for (int b = 1;b <= a;b++)
						for (int c = 0;c < a;c++){
							int x = i-a,y = j+c,z = k+max(b,c);
							
							//if (i == 3 && y == 1 && z == 2) printf("%d %d %d %d %d %d\n",x,j,k,a,b,c);
							f[i][y][z] = add(f[i][y][z],(ll)f[x][j][k]*f[a][b][c]%mod);
						}
		
		for (int j = 1;j < i;j++)
			for (int k = 0;k < i;k++)
				f[i+1][k+1][max(j,k)] = add(f[i+1][k+1][max(j,k)],f[i][j][k]);
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= i;j++)
			for (int k = 0;k < i;k++)
				ans[i][max(j,k)] = add(ans[i][max(j,k)],f[i][j][k]);
	
	for (int i = 1;i <= n;i++){
		for (int j = 0;j <= n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
