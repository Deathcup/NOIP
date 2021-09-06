#include<bits/stdc++.h>
using namespace std;
const int N=200001,M=400002;
int tot,head[N],to[M],nex[M],data[M];
int d[N],sum[N],flag=0;
bool in[N];
int T,n,m,t1,t2,t3;
inline void add(int x,int y,int z){
    to[++tot]=y;data[tot]=z;
    nex[tot]=head[x];head[x]=tot;
}
inline void read(int &x){
    x=0;int w=1;char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') w=-1,ch=getchar();
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
    x=x*w;
}
void DFS_SPFA(int u){
    if(flag) return;
    in[u]=1;
    for(int i=head[u];i;i=nex[i]){
        if(flag) return;
        int v=to[i];
        if(d[v]>d[u]+data[i]){
            d[v]=d[u]+data[i];
            if(in[v]){
                flag=1;
                return;
            }
			else{
                DFS_SPFA(v);
            }
        }
    }
    in[u]=0;
    return;
}
int main(){
    read(T);
    while(T--){
        tot=0;
        flag=0;
        memset(in,0,sizeof(in));
   		memset(d,0,sizeof(d));
        memset(head,0,sizeof(head));
        read(n);read(m);
        for(int i=1;i<=m;i++){
            read(t1);read(t2);read(t3);
            add(t1,t2,t3);
            if(t3>=0) add(t2,t1,t3);
        }
        for(int i=1;i<=n;i++){
            DFS_SPFA(i);
            if(flag)	break;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
