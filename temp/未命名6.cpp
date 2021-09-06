#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int size=10001;
struct qnode{
	int node,dis;
	bool operator <(const qnode b)const{
		return dis>b.dis;
	}
};
priority_queue<qnode> q;
int dist[size],n,m,p,t1,t2,t3;
bool in[size];
struct node2{
	int to,c;
};
vector<node2> edge[size*10];
void add(int x,int y,int z){
	node2 t;
	t.to=y;
	t.c=z;
	edge[x].push_back(t);
}
void dijkstra(int x){
	memset(in,0,sizeof in);
	memset(dist,0x7f,sizeof dist);
	dist[x]=0;
	while(!q.empty()){
		qnode now_node=q.top();q.pop();
		int now =now_node.node;
		if(in[now]) continue;
		in[now]=1;
		for(int i=0;i<edge[now].size();i++){
			if(!in[edge[now][i].to]&&dist[now]+edge[now][i].c<dist[edge[now][i].to]){
				dist[edge[now][i].to]=dist[now]+edge[now][i].c;
				q.push((qnode){edge[now][i].to,dist[edge[now][i].to]});
			}
		}
	}

}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		add(t1,t2,t3);
	}
	dijkstra(p);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}
