#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e5*2;
stack<int> sta;
int n,m,a[N],ans;
int tot,head[N],nex[M],to[M];
vector<int> e[N];
int dfn[N],low[N],timer,color[N],color_num,rd[N],sum[N],f[N];
bool in[N];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void tarjan(int u){
	dfn[u]=low[u]=++timer;
	in[u]=1;
	sta.push(u);
	for(int i=head[u];i;i=nex[i]){
		const int v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		int res=0;
		color_num++;
		while(sta.top()!=u){
			int now=sta.top();
			sta.pop();
			in[now]=0;
			color[now]=color_num;
			res+=a[now];
		}
		int now=sta.top();
		sta.pop();
		in[now]=0;
		color[now]=color_num;
		res+=a[now];
		sum[color_num]=res;
	}
}
void dfs(int x){ 
    if(f[x]) return;
    f[x]=sum[x];
    int maxsum = 0;
    for(int i=0;i<e[x].size();i++){
    	const int v=e[x][i];
        if(!f[v]) dfs(v);
        maxsum=max(maxsum,f[v]);
    }
    f[x]+=maxsum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int t1,t2;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&t1,&t2);
		add(t1,t2);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=nex[i]){
			const int v=to[i];
			if(color[u]!=color[v]){
				rd[color[v]]++;
				e[color[u]].push_back(color[v]);
			}
		}
	}
	for(int i=1;i<=color_num;i++){
		if(!rd[i]){
			dfs(i);
			ans=max(ans,f[i]);
		}
	}
	printf("%d\n",ans);
} 
