#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,q;
int tot,head[N],to[N],data[N],next[N];
int dis[N];
inline void add(int x,int y,int z){
	to[++tot]=y;
	data[tot]=z;
	next[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=next[i]){
		if(to[i]==fa) continue;
		dis[to[i]]=dis[x]^data[i];
		dfs(to[i],x);
	}
}
int main(){
	scanf("%d",&n);	
	int t1,t2,t3;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&t1,&t2);
		cout<< (dis[t1]^dis[t2]) << endl;	
	}
}

