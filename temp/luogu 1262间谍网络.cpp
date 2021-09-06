#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=3005,INF=2147483647;
int n,p,r,t1,t2,t3,k;
int tot,head[N*3],next[N*3],to[N*3];
int w[N],color[N],dfn[N],low[N],cost[N],timer,color_num,rd[N],ans;
bool vis[N],in[N];
stack<int> sta;
inline void add(int x,int y){
	to[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
void dfs(int x){
	vis[x]=1;k++;
	for(int i=head[x];i!=-1;i=next[i]){
		if(!vis[to[i]])	 dfs(to[i]);
	}
}
void tarjan(int x){
	dfn[x]=low[x]=++timer;
	in[x]=1;sta.push(x);
	for(int i=head[x];i!=-1;i=next[i]){
		if(!dfn[to[i]]){
			tarjan(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}
		else if(in[to[i]]) low[x]=min(low[x],dfn[to[i]]);
	}
	if(dfn[x]==low[x]){
		color_num++;
		while(sta.top()!=x){
			color[sta.top()]=color_num;
			cost[color_num]=min(cost[color_num],w[sta.top()]);
			in[sta.top()]=0;
			sta.pop();
		}
		color[sta.top()]=color_num;
		cost[color_num]=min(cost[color_num],w[sta.top()]);
		in[sta.top()]=0;
		sta.pop();
	}
}
int main(){
	cin>>n>>p;
	fill(head,head+N*3,-1);
	fill(w,w+N,INF);
	fill(cost,cost+N,INF);
	for(int i=1;i<=p;i++){
		cin>>t1>>t2;
		w[t1]=t2;
	}
	cin>>r;
	for(int i=1;i<=r;i++){
		cin>>t1>>t2;
		add(t1,t2);
	}
	for(int i=1;i<=n;i++){
		if(w[i]!=INF&&!vis[i]){
			dfs(i);
		}
	}
	if(k<n){
		cout<<"NO"<<endl;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				cout<<i<<endl;
				return 0;
			}
		}	
	} 
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
/*	for(int i=1;i<=n;i++){
		cout<<color[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		cout<<cost[color[i]]<<" ";
	}*/
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=-1;j=next[j]){
			if(color[i]!=color[to[j]])
			rd[color[to[j]]]++;
		}
	}
	for(int i=1;i<=color_num;i++){
		if(!rd[i]) ans+=cost[i];
	}
	cout<<"YES"<<endl;
	cout<<ans<<endl;
}
/* 
7
6
1 10
2 9
3 8
4 7
5 6
6 5
6
1 2
2 3
3 4
4 5
5 2
6 7
*/
