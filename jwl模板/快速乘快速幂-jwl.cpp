#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
LL n,m,mod;
LL ksc(LL a,LL b,LL p){
	if(a>b) swap(a,b);
	LL res=0,base=1;
	while(b){
		if(b&1) res=(res+base*a)%p; 
		b>>=1;
		base=(base*2)%p;
	}
	return res;
}
LL ksm(LL a,LL b,LL p){
	LL res=1,base=a;
	while(b){
		if(b&1) res=ksc(res,base,p)%p;
		b>>=1;
		base=ksc(base,base,p)%p;
	}
	return res;
}
int main(){
	printf("请依次输入 n m mod \n");
	while(cin>>n>>m>>mod){
		cout<<"快速乘："<<ksc(n,m,mod)<<endl;
		cout<<"快速幂："<<ksm(n,m,mod)<<endl;
	}
}
