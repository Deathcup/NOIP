
#include<bits/stdc++.h>
using namespace std;
const int N=2505;
int e[N][N];
int sum[N][N];
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int n,m;
int ans=0;
bool vis1[N][N],vis2[N][N];
struct node{
	int x,y;
};
queue<node> Q;
int cal(int sx,int sy,int ex,int ey){
    return sum[ex][ey]-sum[sx-1][ey]-sum[ex][sy-1]+sum[sx-1][sy-1];
}
bool check1(int x,int y,int res){
	int tx=x,ty=y;
	for(int i=2;i<=n;i++){
		tx=tx-1;
		ty=ty-1;
		if(e[tx][ty]==0){
			return 0;
		}
	}
	if(cal(tx,ty,x,y)!=res){
		return 0;
	}
	return 1;
}
void dfs(int x,int y,int res){
	vis1[x][y]=1;
	bool cc=0;
	int tx=x+1;
	int ty=y+1;
	if(check1(tx,ty,res)&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
		cc=1;
		dfs(tx,ty,res+1);
	}
	if(!cc){
		ans=max(ans,res);
	}
	return;
}
void dfs2(int x,int y,int res){
	vis2[x][y]=1;
	bool cc=0;
	int tx=x+1;
	int ty=y-1;
	if(check1(tx,ty,res)&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
		cc=1;
		dfs2(tx,ty,res+1);
	}
	if(!cc){
		ans=max(ans,res);
	}
	return;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			e[i][j]=(bool)read();
			sum[i][j]=e[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if(e[i][j]==1){
				Q.push(node{i,j});				
			}
		}
	}
	cout<<cal(1,1,3,3)<<endl;	
/*	while(!Q.empty()){
		node now=Q.front();
		Q.pop();
		if(!vis1[now.x][now.y]){
			dfs(now.x,now.y,1);
		}
		if(!vis2[now.x][now.y]){
			dfs2(now.x,now.y,1);
		}
	}
	printf("%d\n",ans);*/
}
