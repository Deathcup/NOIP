#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int mod=2;
LL t,up,down;
LL n,m;
inline LL fpow(LL a,LL b,LL p){
	LL base=a;LL r=1;
	while(b){
		if(b&1) r=base*r%p;
		base=base*base%p;
		b>>=1;
	} 
	return r;
}
LL inv(LL x){
	return fpow(x,mod-2,mod);
}
LL c(LL a,LL b){
    if(b < 0)return 0;  
    if(a < b)return 0;  
    if(b > a-b) b = a-b;  

	up=1;down=1;
	for(int i=0;i<b;i++){
		up=up*(n-i)%mod;
		down=down*(1+i)%mod;
	}
	return (up%mod*inv(down)%mod)%mod;
}
LL lucas(LL a,LL b){
	if(b==0) return 1;
	return c(a%mod,b%mod)*lucas(a/mod,b/mod)%mod;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<lucas(n,m)<<endl;
	}
}
