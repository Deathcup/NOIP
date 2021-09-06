#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
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
bool spfa(int x){
    memset(d,0,sizeof(d));
    memset(sum,0,sizeof(sum));
    queue<int> q;
    d[x]=0;
    q.push(x);
    sum[x]++;
    in[x]=1;
    int now;
    while(!q.empty()){
        now=q.front();q.pop();
        in[now]=0;
        for(int i=head[now];i;i=nex[i]){
            if(d[now]+data[i]<d[to[i]]){
                d[to[i]]=d[now]+data[i];
                if(!in[to[i]]){
                    sum[to[i]]++;
                    if(sum[to[i]]>n) return 1;
                    in[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    return 0;
}
int main(){
    read(T);
    while(T--){
        tot=0;
        memset(to,0,sizeof(to));
        memset(head,0,sizeof(head));
        memset(nex,0,sizeof(nex));
        memset(data,0,sizeof(data));
        read(n);read(m);
        for(int i=1;i<=m;i++){
            read(t1);read(t2);read(t3);
            add(t1,t2,t3);
            if(t3>=0) add(t2,t1,t3);
        }
        flag=0;
        for(int i=1;i<=n;i++){
            if(spfa(i)){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"YE5"<<endl;
        else cout<<"N0"<<endl;
    }
}
