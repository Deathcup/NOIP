#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int N=5001;
int n,m,u,v,t1,t2;
double t3;
double dist[N];
bool in[N];
struct node{
	int to;
	double data;
};
vector<node> e[N];
inline double getdouble(){
	double data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-w;
	while(ch!='.'&&ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	if(ch=='.'){
	ch=getchar();
	while(ch>='0'&&ch<='9') w*=0.1,data=data*10+ch-'0',ch=getchar();	
	}
	return data*w;	
}
inline int getint(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-w,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
inline void add(int x,int y,double z){
	node t;
	t.to=y;t.data=z;
	e[x].push_back(t);
}
void spfa(int x){
	queue<int> q;
	dist[x]=1.0;
	q.push(x);
	in[x]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		in[now]=0;
		for(int i=0;i<e[now].size();i++){
			if(dist[e[now][i].to]<dist[now]*e[now][i].data&&dist[now]!=-1){
				dist[e[now][i].to]=dist[now]*e[now][i].data;
				if(!in[e[now][i].to]){
					q.push(e[now][i].to);
					in[e[now][i].to]=1;
				}
			}
		}
	}
}

int main(){
	n=getint();m=getint();u=getint();v=getint();
	fill(dist,dist+N,-1);
	for(int i=1;i<=m;i++){
		t1=getint();t2=getint();t3=getdouble();
		add(t1,t2,t3);
	}
	spfa(u);
	if(dist[v]==-1){
		printf("orz");
	}
	else printf("%.4lf",dist[v]);
}
