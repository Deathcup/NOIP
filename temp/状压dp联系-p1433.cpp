#include <bits/stdc++.h>
using namespace std;
const int N=17;
double d[N][N];
double dp[N][(1<<N)];
struct node{
    double x,y;
}p[N];
int n;
int read(){
    int data=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) data=data*10+ch-'0',ch=getchar();
    return data;
}
bool vis[N];
int issure(int A,int bit){
	return A&(1<<bit);
}
int zip(int A,int bit){
	return A|(1<<bit);
}
int del(int A,int bit){
	return A^(1<<bit);
}
void dfs(int x,int A){
	if(dp[x][A]!=-1) return;
	dp[x][A] = (double)1e9+0.0;
	for(int i = 1;i <= n;i++){
		if(i == x) continue;
		if(!issure(A,i)) continue;
		int t = del(A,x);
		dfs(i,t);
		dp[x][A] = min(dp[x][A],dp[i][t]+d[x][i]);
	}
}
void debug();
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    p[0].x=0;p[0].y=0;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j) d[i][j] = d[j][i]=0;
            else d[i][j] = d[j][i] = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        }
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=(1<<(n+1))+1;j++){
    		dp[i][j]=-1;
    	}
    }
 //	memset(dp,-1.0,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;i++) dp[i][(1<<i)+1] = d[0][i]; 
//    for(int i=1;i<=n;i++) cout<<dp[i][(1<<i)+1]<<endl;
//    cout<<"*"<<endl;
//    for(int i=1;i<=n;i++)
//    cout<<dp[i][(1<<(n+1))-1]<<endl;
    for(int i=1;i<=n;i++) dfs(i,(1<<(n+1))-1);
	double ans = (double)1e9+0.0;
    for(int i=1;i<=n;i++){
    	if(dp[i][(1<<(n+1))-1]!=-1)
    	ans = min(ans,dp[i][(1<<(n+1))-1]);
    };
//    debug();
    printf("%.2lf",ans);
}
void debug(){
	int x=4;
	cout<<issure(5,2)<<endl;
//	cout<<del(5,2)<<endl;
//	cout<<issure(del(5,2),2)<<endl;
}
