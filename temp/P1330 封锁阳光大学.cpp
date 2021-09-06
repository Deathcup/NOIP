#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=100005,INF=2147483645;
int tot,head[N],nex[M],to[M];
int n,m,ans;
int color[N];
bool vis[N];
queue<int> q;
int w,b;
int read(){
	int data=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) data=data*10+ch-'0',ch=getchar();
	return data;
}
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void bfs(){
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=1;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(color[v]==color[u]){
				w=-1;b=-1;
				break;
			}
			if(!vis[v]){
				q.push(v);
				color[v]=(color[u]+1)%2;
				if(color[v]==1) b++;
				else w++;
			}
		}
	}
}
int main(){
	n=read();m=read();
	for(int t1,t2,i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
		add(t2,t1);
	}
	bool flag=0;
	memset(color,-1,sizeof(color));
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			w=0;b=1;
			color[i]=1;
			q.push(i);
			bfs();
			if(w==-1){
				flag=1;
				break;
			}
			ans+=min(w,b);
		}
	}
	if(flag==1) puts("Impossible");
	else cout<<ans<<endl;
}

