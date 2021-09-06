#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int size=100001;
int n,a[size],ans;
int dp[size][2];
inline int work(){
	dp[0][0]=1;dp[0][1]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		if(i!=1&&a[i]<a[i-1]){
			dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
		}
		dp[i][1]=dp[i-1][1];
		if(i!=1&&a[i]>a[i-1]){
			dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
		}
}
}
int main(){
    std::ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	work();
	ans=max(dp[n][0],dp[n][1]);
	cout<<ans;
	return 0;
}
