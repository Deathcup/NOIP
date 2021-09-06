#include <bits/stdc++.h>
using namespace std;
const int N=101;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct node
{
	int x,y,h;
}p[N*N];
bool cmp(node x,node y){
	return x.h>y.h;
}
int p_tot;
int n,m;
int a[N][N],tx,ty,ans;
int dp[N][N];
bool vis[N][N],in[N][N],cc;
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
inline int dfs(int x,int y){
	if(dp[x][y]) return dp[x][y];
	cc=0;
	for(int i=0;i<4;i++){
		tx=x+dx[i];
		ty=y+dy[i];
		if(a[tx][ty]>=a[x][y]||tx>n||tx<1||ty>m||ty<1) continue;
		int t=dfs(tx,ty);
		dp[x][y]=max(dp[x][y],t+1);
		ans=max(ans,dp[x][y]);
		cc=1;
	}
	if(!cc) return 1;
	else return dp[x][y];
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(a[i][j]);
			p[++p_tot].x=i;
			p[p_tot].y=j;
			p[p_tot].h=a[i][j];
		}
	}
	sort(p+1,p+1+p_tot,cmp);;
	for(int i=1;i<=p_tot;i++){
		if(!dp[p[i].x][p[i].y]){
			dfs(p[i].x,p[i].y);
		}
	}
	cout<<ans<<endl;
}
