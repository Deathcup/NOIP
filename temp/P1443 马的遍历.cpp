#include <bits/stdc++.h>
using namespace std;
const int N=401;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int sx,sy;
int dist[N][N];
int n,m;
struct node{
	int x,y,step;
};
void bfs(int sx,int sy){
	queue<node> q;
	node node_t,node_now;
	node_t.x=sx;node_t.y=sy;node_t.step=0;
	dist[sx][sy]=0;
	q.push(node_t);
	while(!q.empty()){
		node_now=q.front();q.pop();
		int tx,ty;
		for(int i=0;i<8;i++){
			tx=node_now.x+dx[i];
			ty=node_now.y+dy[i];
			if(dist[tx][ty]!=-1||tx>n||tx<1||ty>m||ty<1)	continue;
			node_t.x=tx;node_t.y=ty;node_t.step=node_now.step+1;
			dist[tx][ty]=node_t.step;
			q.push(node_t);
		}
	}	
}
int main(){
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	memset(dist,-1,sizeof(dist));
	bfs(sx,sy);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d", dist[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
