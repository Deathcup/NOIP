#include<bits/stdc++.h>
using namespace std;
const int N=100001,INF=2147483647;
int n,m,q;
int tot,head[N],to[N*5],nex[N*5],data[N*5];
int dis[N];
struct node_que{
	int point,dist;
	bool operator<(const node_que a) const
	{
		return this->dist>a.dist;
	}
};
inline int getint(){
    int data=0,w=1;char ch=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
    return data; 
}
inline void write(int x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void addd(int x,int y,int z){
	to[++tot]=y;
	data[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
void dijskra(int x){
	dis[x]=0;
	priority_queue<node_que> heap;
	heap.push(node_que{x,dis[x]});	
	while(1){
		int t=heap.top().dist; 
		while(!heap.empty()&&heap.top().dist!=dis[heap.top().point]) heap.pop();
		if(heap.empty()) break;
		node_que now=heap.top();heap.pop();
		for(int i=head[now.point];i!=-1;i=nex[i]){
			if(dis[to[i]]>dis[now.point]+data[i]){
				dis[to[i]]=dis[now.point]+data[i];
				heap.push(node_que{to[i],dis[to[i]]});
			}
		}
	}
}
int main(){
	n=getint();m=getint();q=getint();
	int u,v,c;
	for(int i=1;i<=n;i++){
		head[i]=-1;
		dis[i]=INF;
	}
	for(int i=1;i<=m;i++){
		u=getint();v=getint();c=getint();
		addd(u,v,c);
	}
	dijskra(q);
   for(int i=1;i<=n;i++) write(dis[i]),putchar(' ');
}
