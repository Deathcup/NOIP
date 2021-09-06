#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
int dp[N],f[N];
int main(){
	int n;
	cin>>n;
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=n;++i){
		dp[i]=(f[i-1]+dp[i-1]+dp[i-2])%10000;
		f[i]=(f[i-1]+2*dp[i-2])%10000;
	}
	cout<<dp[n]<<endl;
//	cout<<0x7fffffff<<endl;
}
