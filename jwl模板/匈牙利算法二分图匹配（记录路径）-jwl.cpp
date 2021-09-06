#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int g[N][N];
int master[N];
bool vis[N];
int n,m,ans;
bool dfs(int u){
	for(int v=1;v<=m;v++){
		if(g[u][v]){
			if(!vis[v]){
				vis[v]=1;
				if(master[v]==0||dfs(master[v])){
					master[v]=u;
					return 1;
				}
			}
		}
	}
	return 0;
}
int read(){
	int res=0,w=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*w;
}
int main(){
	m=read();n=read();
	int t1,t2;
	while(1){
		t1=read();t2=read();
		if(t1==-1&&t2==-1) break;
		g[t1][t2]=1;g[t2][t1]=1;
	}
	for(int i=m+1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	if(ans==0){
		puts("No Solution!");
		return 0;
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++){
		if(master[i])
		cout<<i<<" "<<master[i]<<endl;
	}
	return 0;
}
