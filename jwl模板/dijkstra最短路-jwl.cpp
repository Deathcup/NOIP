#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e6,M=1e7,INF=214748364;
int read(){
	int res=0,w=1;char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') w=-1;
		ch=getchar();	
	}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*w;
}
int n,m,s;
int tot,head[N],to[M],nex[M],data[M];
int dist[N];
void add(int x,int y,int z){
	to[++tot]=y;
	data[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
struct node{
	int p,d;
	bool operator<(const node tt)const{
		return d>tt.d;
	}
};
void dijkstra(int x){
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[x]=0; 
	priority_queue<node> heap;
	heap.push(node{x,0});
	while(1){
		while(!heap.empty()&&heap.top().d!=dist[heap.top().p]) heap.pop();
		if(heap.empty()) break;
		node t=heap.top();heap.pop();
		for(int i=head[t.p];i;i=nex[i]){
			if(dist[to[i]]>dist[t.p]+data[i]){
				dist[to[i]]=dist[t.p]+data[i];
				heap.push(node{to[i],dist[to[i]]});
			}
		}
	}
}
int main(){
	n=read();m=read();s=read();
	int t1,t2,t3;
	for(int i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dijkstra(s);
	for(int i=1;i<=n;i++){
		if(dist[i]==INF) printf("2147483647 ");
		else printf("%d ",dist[i]);
	}
	putchar('\n'); 
}
