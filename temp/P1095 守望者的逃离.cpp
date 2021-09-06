#include<bits/stdc++.h>
const int N=300000+50;
using namespace std;
int dp[N],n,s,t;
int main(){
	cin>>n>>s>>t; 
    dp[0]=0;
    for (int i=1;i<=t;++i)
        if (n>=10){
            dp[i]=dp[i-1]+60;
            n-=10;
        }
        else{
            dp[i]=dp[i-1];
            n+=4;
        }
    for (int i=1;i<=t;++i){
        if (dp[i]<dp[i-1]+17) dp[i]=dp[i-1]+17;
        if (dp[i]>=s){
            printf("Yes\n%d",i);
            return 0;
        }
    } 
    printf("No\n%d",dp[t]); 
    return 0;
}
