#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;
const int MOD=1e9+7;
int n;
long long m;
struct Matrix{
	int mtx[105][105];
	int n;
	Matrix(){
		memset(mtx,0,sizeof(mtx));
		n=0;
	}
	Matrix operator * (const Matrix &b)const{
		Matrix res;
		res.n=n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					res.mtx[i][j]=(res.mtx[i][j]+(long long)mtx[i][k]*b.mtx[k][j]%MOD)%MOD;
				}
			}
		}
		return res;
	} 
}E,R,ANS;
Matrix ksm(Matrix a,long long b){
	Matrix res=E;
	while(b){
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
void print(Matrix &b){
	for(int i=1;i<=b.n;i++){
		for(int j=1;j<=b.n;j++){
			printf("%d ",b.mtx[i][j]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d%lld",&n,&m);
	E.n=n;R.n=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&R.mtx[i][j]);
			if(i==j) E.mtx[i][j]=1;
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			E.mtx[i][j]=(i==j?1:0);
		}
	}*/
	ANS=ksm(R,m);
	print(ANS);
	return 0;
}
