#include <bits/stdc++.h>
using namespace std;
const int N=1001;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool d[N][N];
int color[N][N],color_tot,colorans[N*N];
int n,m,sx,sy;
inline void readi(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
inline void readb(bool &x){
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	if(ch=='0') x=0;else x=1;	
}
inline void bfs(int x,int y){
	color_tot++;
	color[x][y]=color_tot;
	int cnt=1;
	queue<std::pair<int,int> > q;
	q.push(make_pair(x,y));
	color[x][y]=color_tot;
	while(!q.empty()){
	//	cnt++;
		int ssx=q.front().first,ssy=q.front().second;
		q.pop();
	//	color[ssx][ssy]=color_tot;
		for(int i=0;i<4;i++){
			int tx=ssx+dx[i];
			int ty=ssy+dy[i];
			if(color[tx][ty]!=0||d[tx][ty]==d[ssx][ssy]||tx<1||ty<1||tx>n||ty>n) continue;
			q.push(make_pair(tx,ty));
			color[tx][ty]=color_tot;
			cnt++;
		}
	}
	colorans[color_tot]=cnt;
	return;
}
int main(){
	readi(n);readi(m);
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
				readb(d[i][j]);
		}
	}
/*	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
				if(!color[i][j])
				bfs(i,j);
		}
	}
	cout<<endl;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
				printf("%-3d",color[i][j]);
		}
		cout<<endl;
	}
	for(int i=1;i<=color_tot;i++){
		printf("%-3d",colorans[i]);
	}*/
	while(m--){
		readi(sx);readi(sy);
		if(!color[sx][sy]){
			bfs(sx,sy);
			printf("%d\n",colorans[color[sx][sy]]);
		}
		else{
			printf("%d\n",colorans[color[sx][sy]]);
		}
	}
}


