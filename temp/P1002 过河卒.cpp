#include<bits/stdc++.h>
using namespace std;
long long dp[50][50];
bool c[50][50];
long long ex,ey,mx,my;
int main(){
	cin>>ex>>ey>>mx>>my;
	ex++;ey++;mx++;my++;
	dp[1][1]=1;
	c[mx][my]|=1;
	c[mx+1][my+2]|=1;
	c[mx+1][my-2]|=1;
	c[mx-1][my+2]|=1;
	c[mx-1][my-2]|=1;
	c[mx+2][my+1]|=1;
	c[mx+2][my-1]|=1;
	c[mx-2][my+1]|=1;
	c[mx-2][my-1]|=1;
	for(int i=1;i<=ex;i++){
		for(int j=1;j<=ey;j++){
			if(c[i-1][j]!=1){
				dp[i][j]+=dp[i-1][j];
			}
			if(c[i][j-1]!=1){
				dp[i][j]+=dp[i][j-1];
			}
		}
	}
	cout<<dp[ex][ey]<<endl;
}
