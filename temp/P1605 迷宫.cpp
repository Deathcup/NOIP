#include <bits/stdc++.h>
using namespace std;
const int N=10;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool vis[N][N],br[N][N];
int ans,n,m,T,sx,sy,ex,ey;
void  dfs(int x,int y){
	if(x==ex&&y==ey){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(br[x][y]||vis[tx][ty]||x>n||ty>m||tx<1||ty<1) continue;
		vis[tx][ty]=1;
		dfs(tx,ty);
		vis[tx][ty]=0;
	}
	return;
}
int main(){
 	cin>>n>>m>>T;
 	cin>>sx>>sy>>ex>>ey;
 	for(int t1,t2,i=1;i<=T;i++){
 		cin>>t1>>t2;
 		br[t1][t2]=1;
 	}
 	if(br[ex][ey]){
 		cout<<0<<endl;
 		return 0;
 	}
 	vis[sx][sy]=1;
	dfs(sx,sy);
 	cout<<ans<<endl;
 	return 0;
}
/*
3
s 1 0
1 1 0
0 0 e

3 3 0
1 1 3 3
*/
