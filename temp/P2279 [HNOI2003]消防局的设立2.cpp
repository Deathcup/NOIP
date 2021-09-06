#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,sp,ans;
int tot,head[N],nex[N*2],to[N*2];
int st[N][20],fa[N];
bool vis[N];
struct node{
    int d,id;
}deep[N];
bool cmp(node x,node y){
    return x.d>y.d;
}
void add(int x,int y){
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
int read(){
    int res=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
    return res;
}
void dfs_deep(int x,int y){
    for(int i=head[x];i;i=nex[i]){
        if(to[i]==y) continue;
        fa[to[i]]=x;
        deep[to[i]].d=deep[x].d+1;
        dfs_deep(to[i],x);
    }
    return;
}
void fillflood(int x,int y,int res){
    vis[x]=1;
    if(res==0) return;
    for(int i=head[x];i;i=nex[i]){
        if(to[i]==y) continue;
        fillflood(to[i],x,res-1);
    }
    return;
}
int find(int x,int ret)
{
    if(!ret)return x;
    else return find(fa[x],ret-1);
}
int main(){
    n=read();
    int t1;
    for(int i=2;i<=n;i++){
        t1=read();
        add(i,t1);
        add(t1,i);
    }
    deep[1].d=1;
    for(int i=1;i<=n;i++){
        deep[i].id=i;
    }
    fa[1]=1;
    dfs_deep(1,-1);
    sort(deep+1,deep+1+n,cmp);
    st[1][0]=1;	
    for(int i=1;i<=n;i++){
        int now=deep[i].id;
        if(vis[now]) continue;
        int zz=find(now,2);
        fillflood(zz,-1,2);
        ans++;
    }
    printf("%d\n",ans);
}
