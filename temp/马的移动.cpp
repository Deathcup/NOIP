#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=52;
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,-1,0,1,-1,0,1,-1};
int dkx[8]={1,1,-1,-1,2,2,-2,-2};
int dky[8]={2,-2,2,-2,1,-1,1,-1};
int n;
int ans,ex,ey,sx,sy;
char m[N][N];
bool vis[N][N];
struct node{
	int x,y,step;
};
int main(){
	cin>>n;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			cin>>m[i][j];
			if(m[i][j]=='X'){
				ex=i,ey=j;
				int tox,toy;
				for(int i=0;i<8;i++){
					tox=ex+dx[i];
					toy=ey+dy[i];
					if(tox<1||toy<1||tox>n||toy>n) continue;
					vis[tox][toy]=1;
				}
			} 
			if(m[i][j]=='O') sx=i,sy=j;
			if(m[i][j]=='K'){
				int tx=i,ty=j;
				int tox,toy;
				for(int i=0;i<8;i++){
					tox=tx+dkx[i];
					toy=ty+dky[i];
					if(tox<1||toy<1||tox>n||toy>n) continue;
					vis[tox][toy]=1;
				}
			}
		}
	}
	queue<node> q;
	node now,nex;
	now.x=sx;now.y=sy;
	now.step=0;
	q.push(now);
	while(!q.empty()){
		now=q.front();q.pop();
		int tx=now.x,ty=now.y;
		if(vis[tx][ty]) break;
		if(tx==ex&&ty==ey){
			ans=now.step;
			break;
		}
		int tox,toy;
		for(int i=0;i<8;i++){
			tox=tx+dkx[i];
			toy=ty+dky[i];
			if(tox<1||toy<1||tox>n||toy>n) continue;
			if(!vis[tox][toy]){
				nex.x=tox;nex.y=toy;
				nex.step=now.step+1;
				q.push(nex);
			}
		}
	}
	if(ans==0) cout<<-1<<endl;
	else cout<<ans<<endl;
}
