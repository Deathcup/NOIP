#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2005;
int n,ans;
int tot,head[N],to[N],nex[N];
int fa[N];
struct node{
	int dis,id;
}rk[N];
bool cmp(node x,node y){
	return x.dis>y.dis;
}
bool vis[N];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void dfs(int u,int y){
	for(int i=head[u];i;i=nex[i]){
		const int &v=to[i];
		if(v==y) continue;
		fa[v]=u;
//		rk[v].id=v;
		rk[v].dis=rk[u].dis+1;
		dfs(v,u);
	}
}
void fillflood(int u,int y,int res){
	vis[u]=1;
	if(res==0) return;
	for(int i=head[u];i;i=nex[i]){
		const int &v=to[i];
		if(v==y) continue;
		fillflood(v,u,res-1);	
	}
}
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();
	int t1;
	for(int i=2;i<=n;i++){
		t1=read();
		add(i,t1);
		add(t1,i);
	}
	fa[1]=1;
    for(int i=1;i<=n;i++){
        rk[i].id=i;
    }
//	rk[1].id=1;
	rk[1].dis=1;
	dfs(1,-1);
	sort(rk+1,rk+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(!vis[rk[i].id]){
			ans++;
			int tmp=fa[fa[rk[i].id]];
			fillflood(tmp,-1,2);
		}
	}
	printf("%d\n",ans);	
}

