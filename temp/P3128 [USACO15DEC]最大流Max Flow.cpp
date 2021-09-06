#include<bits/stdc++.h>
using namespace std;
const int N=50005,INF=2147483645;
int n,k,s,t;
int tot=1,head[N],to[N*2],nex[N*2],data[N*2];
void add(int x,int y,int z){
	to[++tot]=y;
	data[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
int depth[N];
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
bool bfs(){
	queue<int> Q;
	for(int i=1;i<=n;i++) depth[i]=0;
	depth[s]=1;
	Q.push(s);
	int u;
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		for(int i=head[u];i;i=nex[i]){
			if(data[i]>0&&depth[to[i]]==0){
				depth[to[i]]=depth[u]+1;
				Q.push(to[i]);
			}
		}
	}
	if(depth[t]==0) return 0;
	else return 1;
}
int dfs(int u,int flow){
	if(u==t) return flow;
	for(int i=head[u];i;i=nex[i]){
		if(data[i]>0&&depth[to[i]]==depth[u]+1){
			int res=dfs(to[i],min(flow,data[i]));
			if(res>0){
				data[i]-=res;
				data[i^1]+=res;
				return res;
			}
		}
	}
	return 0;
}
int dinic(){
	int res=0;
	while(bfs()){
		while(int tt=dfs(s,INF)){
			res+=tt;
		}
	}
	return res;
}
int main(){
	n=read();k=read();
	int t1,t2;
	for(int i=1;i<=n-1;i++){
		t1=read();t2=read();
		add(t1,t2,1);
		add(t2,t1,0);
	}
	int maxn=-1;
	for(int i=1;i<=k;i++){
		s=read();t=read();
		maxn=max(maxn,dinic());
	}
	printf("%d\n",maxn);
}
