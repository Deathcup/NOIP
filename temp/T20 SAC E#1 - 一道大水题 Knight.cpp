#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<queue>
using namespace std;
int to[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
int dx[8]={1,1,1,-1,-1,-1,0,0},dy[8]={1,0,-1,1,0,-1,1,-1};
int n,ans;
struct node{
	int x,y;
}point[20];
struct node2{
	int xx,yy,step;
	node pi[20];
};
int tot,sx,sy,ex,ey;
char m[51][51];
bool vis[51][51];
bool check(int x,int y)  
{  
    if(x<0 || y<0 || x>=n || y>=n)  
    return 0;  
    if(vis[x][y])  
    return 0;  
    return 1;  
}  
bool kill(node2 u,int px,int py){
	for(int i=1;i<=tot;i++){
		if(u.pi[i].x!=0&&u.pi[i].y!=0){
			int tx=u.pi[i].x,ty=u.pi[i].y;
			if(m[tx][ty]=='K'){
				for(int i=0;i<8;i++){
					int tox=tx+to[i][0];
					int toy=ty+to[i][1];
					if(tox<1||toy<1||tox>n||toy>n) continue;
					if(tox==px&&toy==py) return 1;
				}
			}
			if(m[tx][ty]=='X'){
				for(int i=0;i<8;i++){
					int tox=tx+dx[i];
					int toy=ty+dy[i];
					if(tox<1||toy<1||tox>n||toy>n) continue;
					if(tox==px&&toy==py) return 1;
				}
			}
			if(m[tx][ty]=='C'){
				for(int i=1;i<=n;i++){
					if(i==ty) continue;
					if(tx==px&&i==py) return 1;
				}
				for(int i=1;i<=n;i++){
					if(i==tx) continue;
					if(i==px&&i==py) return 1;
				}
			}
			if(m[tx][ty]=='B'){
				for(int i=1;i<=n;i++){
					if(i==ty) continue;
					if(tx+ty-i==px&&i==py) return 1;
				}
				for(int i=1;i<=n;i++){
					if(i==ty) continue;
					if(tx-ty+i==px&&i==py) return 1;
				}
			}
			if(m[tx][ty]=='Q'){
				for(int i=1;i<=n;i++){
					if(i==ty) continue;
					if(tx+ty-i==px&&i==py) return 1;
				}
				for(int i=1;i<=n;i++){
					if(i==ty) continue;
					if(tx-ty+i==px&&i==py) return 1;
				}
				for(int i=1;i<=n;i++){
					if(i==ty) continue;
					if(tx==px&&i==py) return 1;
				}
				for(int i=1;i<=n;i++){
					if(i==tx) continue;
					if(i==px&&i==py) return 1;
				}
			}
			if(m[tx][ty]=='P'){
				if(tx+1==px&&(ty+1==py||ty-1==py)) return 1;
			}
		}
	}
	return 0;
}
void bfs(){
	queue<node2> q;
	node2 a,nex;
	a.xx=sx;a.yy=sy;
	a.step=0;
	for(int i=1;i<=tot;i++)
	a.pi[i]=point[i];
	q.push(a);
	if(kill(a,sx,sy)){
		printf("%d",0);
		return;
	}
	while(!q.empty()){
		a=q.front();q.pop();
		int ax=a.xx,bx=a.yy;
		for(int i=0;i<8;i++){
			int ttx=ax+to[i][0];
			int tty=bx+to[i][1];
			if(ttx<1||tty<1||ttx>n||tty>n) continue;
			if(ttx==ex&&tty==ey){
				ans=a.step+1;
				return;
			}
			if(!kill(a,ttx,tty)){
				for(int k=1;k<=tot;k++){
					nex.pi[k]=a.pi[k];
				}
				for(int j=1;j<=tot;j++){
					if(a.pi[j].x==ttx&&a.pi[j].y==tty){
						nex.pi[j].x=0;
						nex.pi[j].y=0;
					}	
				}
				nex.xx=ttx;
				nex.yy=tty;
				nex.step=a.step+1;
				q.push(nex);
			}
		}
	}
}
int main(){
	cin>>n;
	m[0][0]='.';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			scanf("%c",&m[i][j]);
			cin>>m[i][j];
			if(m[i][j]!='.')
			point[++tot].x=i;
			point[tot].y=j; 
			if(m[i][j]=='O') sx=i,sy=j;
			if(m[i][j]=='X') ex=i,ey=j;
		}
	}
	bfs();
	cout<<ans<<endl;
}
