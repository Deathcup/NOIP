#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,t,t1,ans;
bool a[N][N],vis[N];
int master[N];
bool hungary(int x){
	for(int i=1;i<=m;i++){
		if(a[x][i]&&!vis[i]){
			vis[i]=1;
			if(!master[i]||hungary(master[i])){
				master[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		while(t--){
			cin>>t1;
			a[i][t1]=1;
		}
	}
	for(int i=1;i<=n;i++){
		fill(vis,vis+N,0);
		if(hungary(i)) ans++;
	}
	cout<<ans<<endl;
}
