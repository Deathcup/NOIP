#include<bits/stdc++.h>
using namespace std;
const int N=10001,INF=2147483647;
int n,m,q,t1,t2,t3,fa[N],d[N],deep[N];
int f[N][21];
bool vis[N],in[N];
struct node{
	int u,v,c;
}e[N*5];
struct tre{
	int to,c;
};
vector<tre> tree[N];
bool cmp(node x,node y){
	return x.c>y.c;
}
void swap_(int x,int y){
    int t=x;
    x=y;
    y=t;
}
inline int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void init(){
    for(int  j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
                f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
void kruskal(){
	sort(e+1,e+1+m,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		t1=find(e[i].u);t2=find(e[i].v);
		if(t1!=t2){
			fa[t1]=t2;
			k++;
			tree[e[i].u].push_back((tre){e[i].v,e[i].c});
			tree[e[i].v].push_back((tre){e[i].u,e[i].c});
			
		}			
		if(k==n-1) return;
	}
}
int LCA(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int  j=19;j>=0;j--){
        if(deep[f[x][j]]>=deep[y]) x=f[x][j];
    }
    if(x==y) return x;
    for(int j=19;j>=0;j--){
        if(f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
    }
    return f[x][0];
}
void dfs(int x){
	in[x]=1;
	for(int i=0;i<tree[x].size();i++){
		tre t=tree[x][i];
		if(!in[t.to]){
			deep[t.to]=deep[x]+1;
			d[t.to]=min(d[x],t.c);
			f[t.to][0]=x;
			dfs(t.to);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].c;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		d[i]=INF;
	}
	kruskal();
	cin>>q;
	int last=-1;
	deep[1]=1;
	f[1][0]=1;
	dfs(1);
	init();
//	for(int i=1;i<=n;i++){
//		cout<<i<<":";
//		for(int j=0;j<tree[i].size();j++){
//			cout<<tree[i][j].to<<" ";
//		}
//		cout<<endl;
//	}

	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int t=LCA(t1,t2);
		if(d[t1]!=INF&&d[t2]!=INF&&d[t]!=INF) cout<<d[t]<<endl;
		else cout<<"-1"<<endl;
//		if(d[t1]!=INF&&d[t2]!=INF&&d[t]!=INF){
//			int ans=min()
//			cout<<ans<<endl;		
//		}
//		else cout<<"-1"<<endl;
	}
}
