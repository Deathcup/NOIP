#include<bits/stdc++.h>
using namespace std;
int c[101][101];
int n,m,a[20];
bool vis[101];
void init(){
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			c[i][j]+=c[i-1][j];
			if(j-1>=0)
			c[i][j]+=c[i-1][j-1];
		}
	}	
}
bool check(){
	int ans=0;
	for(int i=0;i<=n-1;i++){
		ans+=c[n-1][i]*a[i+1];
	}
	if(ans==m) return 1;
	else return 0;
}
void dfs(int x){
	if(x==0) cout<<"bug"<<endl;
	if(x==n+1){
		if(check()){
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
			exit(0);
		}
		else return;
	}
	else{
    	int i=1;
    	if (x>n-x+1) i=a[n-x+1]+1;
		for(;i<=n;i++){
			if(vis[i]==0){
				a[x]=i;
				vis[i]=1;
				dfs(x+1);
				vis[i]=0;
				a[x]=0;
			}
		}
	} 
}
int main(){
	cin>>n>>m;
	init();
	dfs(1);
	return 0;
}
/*
1
1 1
1 2 1
1 3 3 1*/
