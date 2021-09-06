#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
bool a[101],b[201],c[201];
void dfs(int x){
	if(x==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]&&!b[i+x]&&!c[x+n-i]){
			a[i]=b[i+x]=c[x+n-i]=1;
			dfs(x+1);
			a[i]=b[i+x]=c[x+n-i]=0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ans;	
}
