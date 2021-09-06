#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005,M=100005;
int n,m,fa[N],ans;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct node{
	int u,v,t;
}e[M];
bool cmp(node x,node y){
	return x.t<y.t;
}
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].t=read();
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		u=find(u);v=find(v);
		if(u==v) continue;
		fa[u]=v;
		cnt++;
		if(cnt==n-1){
			ans=e[i].t;
			break;
		}
	}
	if(ans==0) puts("-1");
	else printf("%d\n",ans);
}

