#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005
#define LL long long
using namespace std;
int n,sumedge,js,cc,cnt,m;
int head[maxn],dad[maxn][22],g[maxn][22],root[maxn],a[maxn],has[maxn];
LL ans,l,r,mid;
LL ecnt,inf;
struct B{
    int root;LL rest;
}b[maxn];
struct C{
    int pos;LL dis;
}c[maxn];
struct Edge{
    int x,y,z,nxt;
    Edge(int x=0,int y=0,int z=0,int nxt=0):
        x(x),y(y),z(z),nxt(nxt){}
}edge[maxn<<1];
void add(int x,int y ,int z){
    edge[++sumedge]=Edge(x,y,z,head[x]);
    head[x]=sumedge;
}
bool cmpb(B a ,B b){
    return a.rest<b.rest;
}
bool cmpc(C a,C b){
    return a.dis<b.dis;
}
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
void dfs(int x){
    for(int i=head[x];i;i=edge[i].nxt){
        int v=edge[i].y;
        if(v==dad[x][0])continue;
        dad[v][0]=x;g[v][0]=edge[i].z;
        if(x==1)root[v]=v;else root[v]=root[x];
        dfs(v);    
    }
}
void dfs_(int x){
    bool flag=false,all=true;
    for(int i=head[x];i;i=edge[i].nxt){
        int v=edge[i].y;
        if(v==dad[x][0])continue;
        flag=true;if(!has[v])all=false;
        dfs_(v);
    }
    if(flag&&all&&x!=1)has[x]=1;
}
bool check(LL lim){
    memset(has,0,sizeof(has));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cnt=js=0;
    for(int i=1;i<=m;i++){
        int u=a[i];LL tot=lim;
        for(int j=16;j>=0;j--){
            if(g[u][j]<=tot&&dad[u][j]!=0){
                tot-=g[u][j];
                u=dad[u][j];
            }
        }
        if(u==1){
            b[++cnt].rest=tot;
            b[cnt].root=root[a[i]];
        }else has[u]=1;
    }
    dfs_(1);
    for(int i=head[1];i;i=edge[i].nxt){
        int v=edge[i].y;
        if(has[v])continue;
        c[++js].pos=v;c[js].dis=edge[i].z;
    }
    if(js>cnt)return false;
    sort(b+1,b+cnt+1,cmpb);
    sort(c+1,c+js+1,cmpc);
    c[js+1].dis=0x7fffffff;
    int now=1;
    for(int i=1;i<=cnt;i++){
        if(has[b[i].root]==0)has[b[i].root]=1;
        else{
            while(has[c[now].pos])now++;
            if(b[i].rest>=c[now].dis)has[c[now++].pos]=1;
        }
        while(has[c[now].pos])now++;
    }
    return now>js;
}
void slove(){
    dfs(1);
    for(int j=1;j<=18;j++)
     for(int i=1;i<=n;i++)
      dad[i][j]=dad[dad[i][j-1]][j-1],
      g[i][j]=g[i][j-1]+g[dad[i][j-1]][j-1];
    l=0; r=500000;
    if(!check(r)) { printf("-1"); return ; }
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
        int x,y,z;
        x=read();y=read();z=read();
        add(x,y,z);add(y,x,z);
        if(x==1||y==1)cc++;
    }
    m=read();
    for(int i=1;i<=m;i++)a[i]=read();
    if(cc>m){printf("-1\n");return 0;}
    slove();
    cout<<ans<<endl;
    return 0;
}
