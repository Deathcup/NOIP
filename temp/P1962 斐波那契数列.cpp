#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long MOD=1e9+7;
long long m;
long long k;
struct Matrix{
	long long n,mtx[105][105];
	Matrix(){
		n=0;
		memset(mtx,0,sizeof(mtx));
	}
	Matrix operator * (const Matrix &tt)const{
		Matrix res;
		res.n=n;
		for(long long i=1;i<=res.n;i++){
			for(long long j=1;j<=res.n;j++){
				for(long long k=1;k<=res.n;k++)
					res.mtx[i][j]=(res.mtx[i][j]%MOD+(long long)(mtx[i][k]%MOD*tt.mtx[k][j]%MOD)%MOD)%MOD;
			}
		}
		res.n=n;
		return res;
	}
}E,a,b;
Matrix ksm(Matrix x,long long b){
	Matrix res=E;
	while(b){
		if(b&1) res=res*x;
		b>>=1;
		x=x*x;
	}
	return res;
}
void write(Matrix &res){
    for (long long i=1;i<=res.n;i++) {
        for (long long j=1;j<=res.n;j++)
        	cout<<res.mtx[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
	cin>>m;
	if(m==1){
		cout<<1<<endl;
		return 0;
	}
	if(m==2){
		cout<<1<<endl;
		return 0;
	}
	if(m==3){
		cout<<2<<endl;
		return 0;
	}
	b.n=3;
	b.mtx[1][1]=1;a.mtx[2][1]=0;a.mtx[3][1]=0;
	b.mtx[1][2]=1;a.mtx[2][2]=0;a.mtx[3][2]=0;
	b.mtx[1][3]=2;a.mtx[2][3]=0;a.mtx[3][3]=0;
	a.n=3;
	a.mtx[1][1]=0;a.mtx[2][1]=1;a.mtx[3][1]=0;
	a.mtx[1][2]=0;a.mtx[2][2]=0;a.mtx[3][2]=1;
	a.mtx[1][3]=0;a.mtx[2][3]=1;a.mtx[3][3]=1;
	E.n=3;
	for(long long i=1;i<=E.n;i++){
		for(long long j=1;j<=E.n;j++)
			E.mtx[i][j]=(i==j?1:0);
	}
	Matrix t=ksm(a,m-3);
	Matrix ans=b*t;
	cout<<ans.mtx[1][3]<<endl;
}
