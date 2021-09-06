#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int size=10001,INF=2147483647;
queue<int> q;
int dist[size],n,m,p;
bool in[size];
struct node{
	int to,c;
};
vector<node> edge[size*10];
void add(int x,int y,int z){
	node t;
	t.to=y;
	t.c=z;
	edge[x].push_back(t);
}
void init(){
	for(int i=1;i<=n;i++){
		dist[i]=INF;
	}
}
void spfa(int x){
	dist[x]=0;
	in[x]=1;
	q.push(x);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		in[now]=0;
		for(int i=0;i<edge[now].size();i++){
			node t=edge[now][i];
			if(t.c+dist[now]<dist[t.to]){
				dist[t.to]=dist[now]+t.c;
				if(in[t.to]==0){
					q.push(t.to);
					in[t.to]=1;
				}
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
	init();
	spfa(p);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}


