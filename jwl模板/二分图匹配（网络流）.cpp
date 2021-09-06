#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,INF=2147483645;
int tot=1,head[N],to[N],nex[N],data[N];
void add(int x,int y,int z){
	to[++tot]=y;
	data[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
int n,m,e,s,t;
int depth[N],cur[N];
bool bfs(){
	queue<int> Q;
	for(int i=0;i<=n+m+1;i++) depth[i]=0;
	depth[s]=1;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		if(u==t) return 1;
		for(int i=head[u];i;i=nex[i]){
			if(depth[to[i]]==0&&data[i]>0){
				depth[to[i]]=depth[u]+1;
				Q.push(to[i]);
			}
		}
	}
	return 0;
}
int dfs(int u,int flow){
	if(u==t) return flow;
	for(int i=head[u];i;i=nex[i]){
		const int &v=to[i];
		if(depth[v]==depth[u]+1&&data[i]!=0){
			int res=dfs(v,min(flow,data[i]));
			if(res>0){
				data[i]-=res;
				data[i^1]+=res;
				return res;
			}
		}
	}
	return 0;
}
int Dinic(){
	int res=0;
	while(bfs()){
/*		for(int i=0;i<=n+m+1;i++){
			cur[i]=head[i];
		}*/
		while(int tt=dfs(s,INF)){
			res+=tt;
		}
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&e);
	s=0;t=1;
	int t1,t2,t3;
	for(int i=1;i<=e;i++){
		scanf("%d%d",&t1,&t2);
		add(t1+1,t2+1+n,1);
		add(t2+1+n,t1+1,0);
	}
	for(int i=2;i<=n+1;i++){
		add(0,i,1);
		add(0,i,0);
	}
	for(int i=n+2;i<=m+n+1;i++){
		add(i,1,1);
		add(i,1,0);
	}
	printf("%d\n",Dinic());
}
