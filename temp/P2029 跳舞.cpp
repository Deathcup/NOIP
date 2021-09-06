#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int s[N],b[N];
int dp[N][N];
int n,t,ans;
int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)	cin>>s[i];
    for(int i=1;i<=n;i++)	cin>>b[i];
    for(int i=1;i<=n;i++)	dp[i][0]=dp[i-1][0]-s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i-1][j]-s[i],dp[i-1][j-1]+s[i]);
            if(j%t==0&&i!=1) dp[i][j]=max(dp[i-1][j]-s[i],dp[i-1][j-1]+s[i]+b[i]);
	    }
    }
    for(int i=0;i<=n;i++) ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
}
