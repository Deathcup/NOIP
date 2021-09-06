#include<bits/stdc++.h>
using namespace std;
const int dx[9]={1,1,1,-1,-1,-1,0,0,0};
const int dy[9]={0,1,-1,0,-1,1,1,-1,0};
const int N=10;
int n;
struct node{
	int in[N][N];
	bool operator <(const node v)const{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(in[i][j]!=v.in[i][j]) return in[i][j]<v.in[i][j];
			}
		}
	}
}vis;
map<node,int> h;
//int used[1000001];
int tot;
//int vis[N][N];
//int m[N][N];
int k;
int ans;
void dfs(int step){
	if(h.count(vis)) return;
	h[vis]=++tot;
	if(step==k+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis.in[i][j]){
				for(int k=0;k<9;k++){
					int tox=i+dx[k];
					int toy=j+dy[k];
					if(tox<1||toy<1||tox>n||toy>n) continue;
					vis.in[tox][toy]+=1;
				}
				dfs(step+1);
				for(int k=0;k<9;k++){
					int tox=i+dx[k];
					int toy=j+dy[k];
					if(tox<1||toy<1||tox>n||toy>n) continue;
					vis.in[tox][toy]-=1;
				}
			}
		}
	}
}
int main(){
	cin>>n>>k;
	dfs(1);
	cout<<ans<<endl;
}
