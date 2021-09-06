#include<cstring>
#include<cstdio>
using namespace std;
const int mx=1000010;
int n,m,k,cnt,dui[mx],q,rk[mx],f[mx],head[mx*2];
bool vis[mx];
struct node{
    int to,ne;
}e[mx*2];
inline int rad(){
    int x=0,f=1; char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-f;    ch=getchar();
    }
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
inline void uni(int x,int y){
    x=find(x),y=find(y);
    f[x]=y;
}
inline int link(int x,int y){
    e[++cnt].to=y,e[cnt].ne=head[x],head[x]=cnt;
}
int main(){
    n=rad(),m=rad(); int x,y;
    for(int i=0;i<n;i++) f[i]=i;
    for(int i=1;i<=m;i++)    x=rad(),y=rad(),link(x,y),link(y,x);
    q=rad();
    for(int i=1;i<=q;i++)    dui[i]=rad(),vis[dui[i]]=1;
    cnt=n-q;
    for(int i=0;i<n;i++)
        if(!vis[i]){
            for(int j=head[i];j;j=e[j].ne)
                if(!vis[e[j].to])
                    if(find(i)!=find(e[j].to)) uni(i,e[j].to),cnt--;
        }
    
    dui[q+1]=cnt;
    for(int i=q;i>=1;i--){
        x=dui[i];
        for(int j=head[x];j;j=e[j].ne){
            y=e[j].to;
            if(find(x)==find(y) || vis[y]==1) continue;
            uni(x,y),cnt--;
        }
        vis[x]=0; dui[i]=++cnt;
    }
    for(int i=1;i<=q+1;i++) printf("%d\n",dui[i]);
    return 0;
}
