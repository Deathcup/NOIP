#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
LL n,m,p;
LL ksm(LL a,LL b,LL p){
	LL res=1,base=a;
	while(b){
		if(b&1) res=(res*base)%p;
		b>>=1;
		base=(base*base)%p;
	}
	return res;
}
LL inv(LL x,LL p){
	return ksm(x,p-2,p);
}
LL C(LL a,LL b,LL p){
	if(a<b) return 0;
	if(b==0||b==a) return 1;
	if(b>a-b) b=a-b;
	LL up=1,down=1,res=1;
	for(int i=1;i<=b;i++){
		up=((a-i+1))%p;
		down=(i)%p;
		res=(res*up*inv(down,p))%p;
	}
//	cout<<up<<endl;
//	cout<<down<<endl; 
	return res;
}
LL Lucas(LL a,LL b,LL p){
	if(a<b) return 0;
	if(b==0||b==a) return 1;
	LL res=1;
	while(a&&b&&res){
		res=(res*C(n%p,m%p,p))%p;
		a/=p;
		b/=p;
	}
	return res;
}
LL lucas(LL a,LL b,LL p){
	if(b==0) return 1;
	return C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
int main(){
	while(cin>>n>>m>>p){
		cout<<lucas(n,m,p)<<endl;
	}
} 
