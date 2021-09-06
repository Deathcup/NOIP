#include <bits/stdc++.h>
using namespace std;
const int N=101;
const int dx[8]={0,0,1,-1,1,-1,1,-1};
const int dy[8]={1,-1,0,0,1,-1,-1,1};
char c[N][N];
char u[8]={'p','y','i','z','h','o','n','g'};
bool vis[N][N];
int n;
bool dfs(int x,int y,int step){
	if(c[x][y]!=u[step]) return 0;
	if(step==7&&c[x][y]==u[step]) {
		vis[x][y]=1;
		return 1;
	}
	if(step==1){
		int tx=x,ty=y;
		bool cc=0;
		for(int i=0;i<8;i++){
			for(int j=1;j<=7;j++){
				tx=x+dx[i];
			}
		}
	}
	bool cc=0,bb=0;
	for(int i=0;i<8;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>n||ty>n||tx<1||ty<1) continue;
		bool flag=dfs(tx,ty,step+1);
		if(flag==1) cc=1;
	}
	if(cc==1&&bb==1) vis[x][y]=1;
//	return 0;
}
void Dfs(int x,int y){
	if(c[x][y]!='y') return;
	int tx,ty;
	for(int i=0;i<8;i++){
		tx=x;
		ty=y;
		bool cc=0;
		for(int j=2;j<=7;j++){
			tx+=dx[i];
			ty+=dy[i];
			if(c[tx][ty]!=u[j]) break;
			if(j==7) cc=1;
		}
		tx=x;ty=y;
		if(cc){
			vis[tx][ty]=1;
			for(int j=2;j<=7;j++){
				tx+=dx[i];
				ty+=dy[i];
				vis[tx][ty]=1;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			Dfs(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]) cout<<"*";
			else cout<<c[i][j];
		}
		cout<<endl;
	}
}
/*
7
yizhong
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg
*/
