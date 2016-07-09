#include<cstdio>

int main(){
	int n=4;
	for(int i=0;i<n;i++,printf("\n"))for(int j=0;j<n;j++){
		int x=(i|j)^i,y=1;
		for(int k=0;k<2;k++)if(x>>k&1)y^=1;
		printf("%d ",y);
	}
}
