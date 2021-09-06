#include <bits/stdc++.h>
using namespace std;
const int N=50005,M=75005;
int tot,head[N],nex[N*2],to[N*2],data[N*2];
inline void add(int x,int y,int z){
	to[++tot]=y;data[tot]=z;
	nex[tot]=head[x];head[x]=tot;
}
int q_tot,q_head[M],q_nex[M*2],q_to[M*2],q_data[M*2];
inline void qadd(int x,int y,int z){
	q_to[++q_tot]=y;q_data[q_tot]=z;
	q_nex[q_tot]=q_head[x];q_head[x]=q_tot;
}
int n,m,ans[M];
int dist[N];
void dfs(int x,int fa){
	for(int i=head[x];i;i=nex[i]){
		if(to[i]==fa) continue;
		dist[to[i]]=dist[x]+data[i];
		dfs(to[i],x);
	}
}
int fa[N];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void merge(int u,int v){
	int r1=find(u),r2=find(v);
	fa[r2]=r1;
}
bool vis[N];
void Tarjan(int x){
	vis[x]=1;
	for(int i=head[x];i;i=nex[i]){
		if(!vis[to[i]]){
			Tarjan(to[i]);
			merge(x,to[i]);			
		}
	}
	for(int i=q_head[x];i;i=q_nex[i]){
		if(vis[q_to[i]]){
			int lca=find(q_to[i]);
			ans[q_data[i]]=dist[x]+dist[q_to[i]]-2*dist[lca];
		}
	}
}
void debug(){
	cout<<"debug"<<endl;
	for(int i=0;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<"end"<<endl;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int t1,t2,t3;
	for(int i=1;i<=n-1;i++){
		cin>>t1>>t2>>t3;
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	dfs(0,-1);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		qadd(t1,t2,i);
		qadd(t2,t1,i);
	}
//	debug();	
	Tarjan(0);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
}
