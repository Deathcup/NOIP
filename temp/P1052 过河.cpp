#include<bits/stdc++.h>
using namespace std;
const int N=1001,INF=214748364;
int a[N];
int dp[300001];
int l,m,s,t;
bool stone[300001];
int read(){
    int data=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) data=data*10+ch-'0',ch=getchar();
    return data;
}
int main(){
	l=read();s=read();t=read();m=read();
	for(int i=1;i<=m;++i){
		a[i]=read();
	}
	sort(a+1,a+1+m);
	int k=0,last=0;
    for (int i=1;i<=m;++i)
    {
        if (a[i]-a[i-1]>2520)
            k+=(a[i]-a[i-1])-(a[i]-a[i-1])%2520;
        stone[a[i]-k]=1;
    }
/*	for(int i=1;i<=m;++i){
		d=a[i]-a[i-1];
		d%=2520;
		last+=d;
		stone[last]=1;
	}*/
	fill(dp+1,dp+300000,INF);
	dp[0]=0;
	for(int i=1;i<=252000;++i){
		for(int j=t;j>=s;--j){
			if(i-j>=0)
			dp[i]=min(dp[i],dp[i-j]+stone[i]);
		}
	}
/*	int ans=INF;
	for(int i=l;i<=l+t;++i){
		ans=min(ans,dp[i]);
	}*/
	cout<<dp[252000]<<endl;
}
