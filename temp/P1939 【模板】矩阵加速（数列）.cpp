#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
int T;
LL m;
struct Matrix{
	LL n,mtx[105][105];
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
					res.mtx[i][j]=(res.mtx[i][j]%MOD+(mtx[i][k]%MOD*b.mtx[k][j]%MOD)%MOD)%MOD;
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
int readin(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
LL readl(){
	LL res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	T=readin();
	while(T--){
		m=readl();
		if(m==1){
			cout<<"1"<<endl;
			continue;
		}
		else if(m==2){
			cout<<"1"<<endl;
			continue;
		}
		else if(m==3){
			cout<<"1"<<endl;
			continue;
		}
		else if(m==4){
			cout<<"2"<<endl;
			continue;
		}
		D.n=4;
		D.mtx[1][1]=1;D.mtx[1][2]=1;D.mtx[1][3]=1;D.mtx[1][4]=2;
		D.mtx[2][1]=0;D.mtx[2][2]=0;D.mtx[2][3]=0;D.mtx[2][4]=0;
		D.mtx[3][1]=0;D.mtx[3][2]=0;D.mtx[3][3]=0;D.mtx[3][4]=0;
		D.mtx[4][1]=0;D.mtx[4][2]=0;D.mtx[4][3]=0;D.mtx[4][4]=0;		
		R.n=4;
		R.mtx[1][1]=0;R.mtx[1][2]=0;R.mtx[1][3]=0;R.mtx[1][4]=0;
		R.mtx[2][1]=1;R.mtx[2][2]=0;R.mtx[2][3]=0;R.mtx[2][4]=1;
		R.mtx[3][1]=0;R.mtx[3][2]=1;R.mtx[3][3]=0;R.mtx[3][4]=0;
		R.mtx[4][1]=0;R.mtx[4][2]=0;R.mtx[4][3]=1;R.mtx[4][4]=1;
		E.n=4;
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				E.mtx[i][j]=(i==j?1:0);
			}
		}
		Matrix ans=ksm(R,m-4);
		ans=D*ans;
		printf("%lld\n",ans.mtx[1][4]);
//		Matrix ans=D*R;
 //		for(int i=1;i<=4;i++){
//			for(int j=1;j<=4;j++)
//				cout<<ans.mtx[i][j]<<" ";
//			cout<<endl;
//		}
	}
	return 0;
}
