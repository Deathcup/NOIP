#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,sp,ans;
int tot,head[N],nex[N*2],to[N*2];
int st[N][21];
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
//		fa[to[i]]=x;
		st[to[i]][0]=x;
		deep[to[i]].d=deep[x].d+1;
		dfs_deep(to[i],x);
	}
	return;
}
void init(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
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
int main(){
	n=read();k=read();sp=read();
	int t1,t2;
	for(int i=1;i<=n-1;i++){
		t1=read();t2=read();
		add(t1,t2);
		add(t2,t1);
	}
	deep[1].d=1;
	for(int i=1;i<=n;i++){
		deep[i].id=i;
	}
//	st[1][0]=1;
	dfs_deep(1,-1);
	init();
	sort(deep+1,deep+1+n,cmp);
//	st[1][0]=1;	
	for(int i=1;i<=n;i++){
		int now=deep[i].id;
		if(vis[now]) continue;
//		int zz=find(now,k);
		int t=k;
		for(int j=0;j<=19;j++){
			if(t&(1<<j)){
				now=st[now][j];
			}
	//		t>>=1;
	//		if(t==0) break;
		}
		if(now==0) now=1;
		fillflood(now,-1,k);
		ans++;
	}
	printf("%d\n",ans);
}
