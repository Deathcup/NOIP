#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
const int SIZE=1000001;
int fa[SIZE],n,m,q,t1,t2,t3,num=1;
int f[SIZE][21],deep[SIZE],head[SIZE];
struct node{
	int to,next;
}edge[SIZE];
void swap_(int x,int y){
	int t=x;
	x=y;
	y=t;
}
inline void add_(int x,int y){
	edge[num].to=y;
	edge[num].next=head[x];
	head[x]=num++;
}
void dfs_(int x){
	for(int i=head[x];i!=-1;i=edge[i].next){
		int now=edge[i].to;
		if(deep[now]==0){
			deep[now]=deep[x]+1;
			f[now][0]=x;
			dfs_(now);
		}
	}
}
void init(){
	for(int  j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
int LCA_(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int  j=19;j>=0;j--){
		if(deep[f[x][j]]>=deep[y]) x=f[x][j];
	}
	if(x==y) return x;
	for(int j=19;j>=0;j--){
		if(f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	}
	return f[x][0];
}
inline int read(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1;
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	n=read();m=read();q=read();
	deep[q]=1;
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int  i=1;i<=n-1;i++){
		t1=read();t2=read();
		add_(t1,t2);
		add_(t2,t1);
	}
	dfs_(q);
	init();
	while(m--){
		t1=read();t2=read();
		write(LCA_(t1,t2));
		putchar('\n');
	}
}

