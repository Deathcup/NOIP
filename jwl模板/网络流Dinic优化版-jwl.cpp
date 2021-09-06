#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e6+5,M=1e6*2+5,INF=2147483645;
int n,m,s,t;
int tot=1,head[N],to[M],nex[M],data[N];
int depth[N],cur[N];
void add(int x,int y,int z){
    to[++tot]=y;
    data[tot]=z;
    nex[tot]=head[x];
    head[x]=tot;
}
int read(){
    int res=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
    return res;
}
bool bfs(){
    queue<int> q;
    q.push(s);
    for(int i=1;i<=n;i++) depth[i]=0;
    depth[s]=1;
    int u;
    while(!q.empty()){
        u=q.front();q.pop();
        if(u==t) return 1;
        for(int i=head[u];i;i=nex[i]){
            if(depth[to[i]]==0&&data[i]>0){
                depth[to[i]]=depth[u]+1;
                q.push(to[i]);
            }
        }
    }
    return 0;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    for(int &i=cur[u];i;i=nex[i]){
        if(data[i]!=0&&depth[to[i]]==depth[u]+1){
            int res=dfs(to[i],min(flow,data[i]));
            if(res>0){
                data[i]-=res;
                data[i^1]+=res;
                return res;
            }
        }
    }
    return 0;
}
int dinic(){
    int ans=0;
    while(bfs()){
    	for(int i=1;i<=n;i++){
    		cur[i]=head[i];
    	} 
        while(int tt=dfs(s,INF)){
            ans+=tt;
        }
    }
    return ans;
}
int main(){
    n=read();m=read();s=read();t=read();
    int t1,t2,t3;
    for(int i=1;i<=m;i++){
        t1=read();t2=read();t3=read();
        add(t1,t2,t3);
        add(t2,t1,0);
    }
    printf("%d\n",dinic());
}
