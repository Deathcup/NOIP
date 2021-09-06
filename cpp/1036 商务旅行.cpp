#include <bits/stdc++.h>
using namespace std;
const int N=30005;
int n,m;
int tot,head[N],to[N*2],nex[N*2];
inline void add(int x,int y){
	to[++tot] = y;
	nex[tot] = head[x];
	head[x] = tot;
}
int TOT,HEAD[N],TO[N*2],DATA[N*2],NEX[N*2];
inline void ADD(int X,int Y,int Z){
	TO[++TOT] = Y;
	DATA[TOT] = Z;
	NEX[TOT] = HEAD[X];
	HEAD[X] = TOT;
}
int fa[N];
inline int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void merge(int x,int y){
	int r1 = find(x),r2 = find(y);
	fa[r2] = r1;
}
int dist[N];
inline void dfs(int x,int y){
	for(int i = head[x]; i ;i = nex[i]){
		if(to[i] == y) continue;
		dist[to[i]] = dist[x] + 1;
		dfs(to[i],x);
	}
}
bool vis[N];
int ans[N];
void Tarjan(int u){
	vis[u] = 1;
	fa[u] = u;
	for(int i = head[u]; i ;i = nex[i]){
		int &v=to[i];
		if(!vis[v]){
			Tarjan(v);
			merge(u,v);
		}
	}
	for(int i=HEAD[u];i;i=NEX[i]){
		int &v=TO[i];
		if(vis[v]){
			if(u==v) ans[DATA[i]]=0;
			int lca = find(v);
			if(ans[DATA[i]]) continue;
			ans[DATA[i]] = dist[u] + dist[v] - 2*dist[lca];
		}
	}
}
int main(){
	cin>>n;
//	for(int i=1;i<=n;i++){
//		fa[i] = i;
//	}
	int t1,t2;
	for(int i = 1;i <= n-1; i++){
		cin>>t1>>t2;
		add(t1,t2);
		add(t2,t1);
	}
	dfs(1,-1);
	cin>>m;
	t1=1;
	for(int i = 1;i <= m; i++){
		cin>>t2;
		ADD(t1,t2,i);
		ADD(t2,t1,i);
		t1 = t2;
	}
	Tarjan(1);
	int sum=0;
	for(int i = 1;i <= m; i++){
		sum+=ans[i];
	}
	cout<<sum<<endl;
}
