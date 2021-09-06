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
bool in[N];
void spfa(int x){
	queue<int> Q;
	for(int i=0;i<=n+1;i++) in[i]=0,dist[i]=INF;
	dist[x]=0;
	Q.push(x);
	in[x]=1;
	int u;
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		in[u]=0;
		for(int i=head[u];i;i=nex[i]){
			if(dist[to[i]]>dist[u]+data[i]){
				dist[to[i]]=dist[u]+data[i];
				if(!in[to[i]]){
					Q.push(to[i]);
					in[to[i]]=1;
				}
			}
		}
	}
	return;
}
int main(){
	n=read();m=read();s=read();
	int t1,t2,t3;
	for(int i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
//		add(t2,t1,t3);
	}
	spfa(s);
	for(int i=1;i<=n;i++){
		if(dist[i]==INF) printf("2147483647 ");
		else printf("%d ",dist[i]);
	}
	putchar('\n'); 
}
