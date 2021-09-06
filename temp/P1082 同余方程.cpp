#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
void e_gcd(int a,int b,int &d,int &x,int &y){
	if(!b){
		d=a;
		x=1;y=0;
		return;
	}
	else{
		e_gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}
int main(){
	cin>>n>>m;
	int x,y;
	int gcd;
	e_gcd(n,m,gcd,x,y);
	while(x>0){
		x-=m;
	}
	while(x<0){
		x+=m;
	}
	cout<<x<<endl;
}
