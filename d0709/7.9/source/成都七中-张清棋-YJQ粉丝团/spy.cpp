#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
#define maxn 3020

typedef double real;
real matrix[maxn][maxn],ans[maxn];
int n,b[maxn];
bitset <32> bit;

void init(){
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= n ; j++){
			bit = ((i - 1) | (j - 1)) ^ (i - 1);
			matrix[i][j] = (bit.count() + 1) % 2;
		}
		matrix[i][n + 1] = b[i];
	}
}

void gauss(){
	for (int i = 1 ; i <= n ; i++){
		int x = i;
		for (int j = i + 1 ; j <= n ; j++){
			if ( matrix[j][i] > matrix[x][i] ){
				x = j;
			}
		}
		if ( !matrix[x][i] ) continue;
		for (int j = 1 ; j <= n + 1 ; j++) swap(matrix[x][j],matrix[i][j]);
		for (int j = i + 1 ; j <= n ; j++){
			if ( !matrix[j][i] ) continue;
			real tmp = matrix[j][i] / matrix[i][i];
			for (int k = 1 ; k <= n + 1	; k++){
				matrix[j][k] -= matrix[i][k] * tmp;
			}
		}	
	}
	for (int i = n ; i >= 1 ; i--){
		ans[i] = matrix[i][n + 1];
		for (int j = i + 1 ; j <= n ; j++)
			ans[i] -= matrix[i][j] * ans[j];
		ans[i] /= matrix[i][i];
	}
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++) scanf("%d",&b[i]);
	init();
	gauss();
	for (int i = 1 ; i <= n ; i++) printf("%d ",(int)ans[i]);
	return 0;
}
