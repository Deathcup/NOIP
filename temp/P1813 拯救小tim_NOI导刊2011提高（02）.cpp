#include<bits/stdc++.h>
using namespace std;
const int N=101,M=1001,inf=2147483647;
struct node{
	int c,st,et;
}data[M];
int head[N],to[M],nex[M],tot;
inline void add(int x,int y,int b,int e,int cc){
	to[++tot]=y;data[tot].c=cc;data[tot].st=b;data[tot].et=e;
	nex[tot]=head[x];head[x]=tot;
}
int n,m,s,t,dist[N],vis[N];
void spfa(int time){
	memset(vis,0,sizeof(vis));
	fill(dist,dist+N,inf);
//	memset(dist,inf,sizeof(vis));
	queue<int> q;
	dist[s]=time;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		vis[now]=0;
		if(dist[now]!=inf)
		for(int i=head[now];i;i=nex[i]){
			int maxt;
			maxt=max(data[i].st,dist[now]);
			if(maxt+data[i].c<dist[to[i]]&&maxt+data[i].c<=data[i].et){
				dist[to[i]]=maxt+data[i].c;			
				if(!vis[to[i]]){
					q.push(to[i]);
					vis[to[i]]=1;					
				}


			}
		}
	}
}
int main(){
	cin>>n>>m>>s>>t;
	int x,y,b,e,cc;
	int mint=inf,maxt=-1;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>b>>e>>cc;
	  	if(b>e)swap(b,e);
	  	if(b+cc>e)continue;
	  	if(x==s)
	  	{
	  	  mint=min(mint,b);
		  maxt=max(maxt,e-cc);  	
		}
		add(x,y,b,e,cc);
	}
	int ans=inf;
	for(int i=mint;i<=maxt;i++){
		spfa(i);
		if(dist[t]==inf) break;
		ans=min(ans,dist[t]-dist[s]);
	}
	if(ans==inf) cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
}
