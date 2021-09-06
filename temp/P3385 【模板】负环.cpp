#include<bits/stdc++.h>
using namespace std;
const int N=200001,M=400002;
int tot,head[N],to[M],nex[M],data[M];
int d[N],flag=0;
bool in[N];
int T,n,m,w,t1,t2,t3;
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
	memset(in,0,sizeof(in));
	stack<int> q;
	d[x]=0;
	q.push(x);
	in[x]=1;
	int now;
	while(!q.empty()){
		now=q.top();q.pop();
//		in[now]=0;
		for(int i=head[now];i;i=nex[i]){
			int &v=to[i];
			if(d[now]+data[i]<d[v]){
				d[v]=d[now]+data[i];
				if(!in[v]){
					in[v]=1;
					q.push(v);
				}
				else{
					flag=1;
					return 1;
				}
			}
		}
	}
	return 0;
}
void DFS_SPFA(int u){

    if(flag) return;
    in[u]=1;
    for(int i=head[u];i;i=nex[i]){
        if(flag) return;
        int v=to[i];
        if(d[u]+data[i]<d[v]){
            d[v]=d[u]+data[i];
            if(in[v]){
                flag=1;
                return;
            }else{
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
        memset(in,0,sizeof(in));
        memset(d,0,sizeof(d));
        memset(head,0,sizeof(head));
        int x,y,z;
        tot=0;
        read(n);read(m);read(w);
        for(int j=1;j<=m;j++){
            read(x);read(y);read(z);
            add(x,y,z);add(y,x,z);
        }
        for(int j=1;j<=w;j++){
            read(x);read(y);read(z);
            add(x,y,-z);
        }
        flag=0;
        for(int i=1;i<=n;i++){
        	DFS_SPFA(i);
        	if(flag==1) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
