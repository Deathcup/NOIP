#include<iostream>
#include<cstdio>
#define IL inline
#define fp(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=10005,MOD=9997;
int n,m,k;
IL int ksm(int x,int y){
	int r=1,base=x;
	while(y){
		if(y&1) r=(base*r)%MOD;
		base=(base*base)%MOD;
		y>>=1;
	}
	return r;
}
int main(){
	while(cin>>n>>m)
	cout<<ksm(n,m);
}
