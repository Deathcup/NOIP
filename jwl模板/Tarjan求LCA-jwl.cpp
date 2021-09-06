#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector> 
using namespace std;
const int N=1e6,M=1e6*2;
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int n,m,fa[N],ans[N]; 
int tot,head[N],to[M],nex[M];
struct node{
	int v,id;
};
vector<node> e[N];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool vis[N];
void merge(int x,int y){
	int r1=find(x),r2=find(y);
	if(r1!=r2)
	fa[r1]=r2;
}
void tarjan(int x){
	vis[x]=1;
	for(int i=head[x];i;i=nex[i]){
		if(!vis[to[i]]){
			tarjan(to[i]);
			merge(to[i],x);
		}
	}
	for(int i=0;i<e[x].size();i++){
		node tv=e[x][i];
		if(vis[tv.v]){
			ans[tv.id]=find(tv.v);
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	int t1,t2;
	for(int i=1;i<=n-1;i++){
		t1=read();t2=read();
		add(t1,t2);
		add(t2,t1);
	}
	m=read();
	for(int i=1;i<=m;i++){
		t1=read();t2=read();
		e[t1].push_back(node{t2,i});	
		e[t2].push_back(node{t1,i});
	}
	tarjan(1);
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}
