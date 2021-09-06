#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e6,M=1e6*2;
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int n,m,deep[N],st[N][20];
int tot,head[N],to[M],nex[M];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void getdeep(int x,int y){
	for(int i=head[x];i;i=nex[i]){
		if(to[i]==y) continue;
		deep[to[i]]=deep[x]+1;
		st[to[i]][0]=x;
		getdeep(to[i],x);
	}
}
void init_lca(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
int LCA(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int j=19;j>=0;j--){
		if(deep[st[x][j]]>=deep[y]) x=st[x][j];
	}
	if(x==y) return x;
	for(int j=19;j>=0;j--){
		if(st[x][j]!=st[y][j]) x=st[x][j],y=st[y][j];
	}
	return st[x][0];
}
int main(){
	n=read();
	int t1,t2;
	for(int i=1;i<=n-1;i++){
		t1=read();t2=read();
		add(t1,t2);
		add(t2,t1);
	}
	deep[1]=1;
	getdeep(1,-1);
	init_lca();
	m=read();
	while(m--){
		t1=read();t2=read();
		printf("%d\n",LCA(t1,t2));
	}
}
