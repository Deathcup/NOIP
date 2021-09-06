#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,cnt;
int tot,head[N],to[N<<1],nex[N<<1];
int root,dfn[N],low[N],timer;
bool isge[N];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
void tarjan(int u,int fa){
	dfn[u]=low[u]=++timer;
	int child=0;
	for(int i=head[u];i;i=nex[i]){
		const int &v=to[i];
		if(v==fa) continue;
		if(!dfn[v]){
			child++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&!isge[u]){
				cnt++;isge[u]=1;
			}
		}
		else if(v!=fa){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(u==root&&child==1){
		cnt--;
		isge[u]=0;
	}
}
int main(){
	n=read();m=read();
	int t1,t2;
	for(int i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
		add(t2,t1);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			root=i;
			tarjan(root,-1);
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++){
		if(isge[i]) printf("%d ",i);
	}
	return 0;
}
