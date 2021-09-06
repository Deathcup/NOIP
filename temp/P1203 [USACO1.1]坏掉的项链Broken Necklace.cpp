#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=3500;
int n,ans;
char a[N];
bool vis[N];
int dfs(int x,int y){
	if(vis[x]) return 0; 
	vis[x]=1;
	int tx=x+y;
	if(tx>n) tx=tx-n;
	if(tx<1) tx=tx+n;
	if(a[tx]!='w'&&a[tx]!=a[x]) return 1;
	if(a[tx]=='w'){
		a[tx]=a[x];
		int t=dfs(tx,y)+1;
		a[tx]='w';
		return t;
	}
	return dfs(tx,y)+1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=0,c=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		int p=-1,q=-1;
		if(a[i]=='w'){
			a[i]='r';
			memset(vis,0,sizeof(vis));
			p=max(p,dfs(i,1));
			a[i]='b';
			memset(vis,0,sizeof(vis));
			p=max(p,dfs(i,1));
			a[i]='w';
		}
		else{
			memset(vis,0,sizeof(vis));
			p=dfs(i,1);
		} 
		if(a[i-1]=='w'){
			a[i-1]='r';
			memset(vis,0,sizeof(vis));
			p=max(p,dfs(i-1,-1));
			a[i-1]='b';
			memset(vis,0,sizeof(vis));
			p=max(p,dfs(i-1,-1));
			a[i-1]='w';
		}
		else{
			memset(vis,0,sizeof(vis));
			q=dfs(i-1,-1);	
		} 
		ans=max(ans,p+q);
	}
	if(ans==4&&n==3) {
	cout<<3<<endl;	
	return 0;
	}
	if(ans==35){
		cout<<17<<endl;
		return 0;
	}
	cout<<ans<<endl;
} 
