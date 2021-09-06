#include<bits/stdc++.h>
using namespace std;
unsigned long long  c[50][50]; 
int n,a,b;
void pre(){
	for(int i=0;i<=40;i++) c[i][0]=1;
	for(int i=0;i<=40;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
int main(){
	cin>>n>>a>>b;
	pre();
	cout<<c[a+n][n]*c[b+n][n]<<endl;
}
