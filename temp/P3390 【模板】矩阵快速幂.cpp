#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=10e9+7;
int n;
long long k;
struct Matrix{
	int n,mtx[105][105];
	Matrix(){
		n=0;
		memset(mtx,0,sizeof(mtx));
	}
	Matrix operator * (const Matrix &tt)const{
		Matrix res;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					res.mtx[i][j]=(res.mtx[i][j]+(long long)mtx[i][k]*tt.mtx[k][j]%MOD)%MOD;
				}
			}
		}
		res.n=n;
		return res;
	}
}E,b;
Matrix ksm(Matrix b,long long b){
	Matrix res=E;
	while(b){
		if(b&1) res=res*b;
		b>>=1;
		b=b*b;
	}
	return res;
}
void write(Matrix &res){
    for (int i=1;i<=res.n;i++) {
        for (int j=1;j<=res.n;j++){
        	cout<<res.mtx[i][j]<<" ";
        } 
        cout<<endl;
    }
}
int main(){
	cin>>n>>k;
	b.n=n;
	for(int i=1;i<=b.n;i++){
		for(int j=1;j<=b.n;j++){
			cin>>b.mtx[i][j];
		}
	}
	E.n=n;
	for(int i=1;i<=E.n;i++){
		for(int j=1;j<=E.n;j++){
			E.mtx[i][j]=(i==j?1:0);
		}
	}
	Matrix ans=ksm(b,k);
	write(ans);
}
