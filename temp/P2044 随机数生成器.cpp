#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
//const LL MOD=1e9+7;
LL m,a,c,t1,t2,q,MOD;
LL ksc(LL x,LL b,LL p){
	if(x>b) swap(x,b);
	LL res=0,base=1;
	while(b){
		if(b&1) res=(res+base*x)%p; 
		b>>=1;
		base=(base+base)%p;
	}
	return res;
}
struct Matrix{
	LL n,mtx[5][5];
	Matrix(){
		n=0;
		memset(mtx,0,sizeof(mtx));
	} 
	Matrix operator * (const Matrix &b)const{
		Matrix res;
		res.n=n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					res.mtx[i][j]=(res.mtx[i][j]%m+ksc(mtx[i][k],b.mtx[k][j],m))%m;
		return res;	
	}
}E,D,R;
Matrix ksm(Matrix A,LL b){
	Matrix res=E;
	while(b){
		if(b&1) res=res*A;
		A=A*A;
		b>>=1;
	}
	return res;
}
LL read(){
	LL res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	m=read();a=read();c=read();t1=read();q=read();MOD=read();
	D.n=2;
	D.mtx[1][1]=t1;D.mtx[1][2]=c;
	D.mtx[2][1]=0;D.mtx[2][2]=0;
	R.n=2;
	R.mtx[1][1]=a;R.mtx[1][2]=0;
	R.mtx[2][1]=1;R.mtx[2][2]=1;
	E.n=2;
	E.mtx[1][1]=1;E.mtx[1][2]=0;
	E.mtx[2][1]=0;E.mtx[2][2]=1;
	Matrix ans=ksm(R,q);
	ans=D*ans;
	printf("%lld\n",ans.mtx[1][1]%MOD);
}
