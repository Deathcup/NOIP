#include<iostream>
#include<cstdio>
using namespace std;
const int INF=2147483646;
int map[301][301],dep[301][301];
int f[301];
int n,p,t1,t2,t;
unsigned long long q;
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int main(){
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=INF;
			dep[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
		map[i][i]=0;
	}
	for(int i=1;i<=p;i++){
		cin>>t;
		if(t==1){
			cin>>t1>>t2;
			map[t1][t2]=1;
			dep[t2][t1]=1;
		}
		if(t==2){
			cin>>t1>>t2;
			map[t2][t1]=1;
			dep[t1][t2]=1;
		}
		if(t==3){
			cin>>t1>>t2;
			map[t1][t2]=1;
			dep[t1][t2]=1;
			map[t2][t1]=1;
			dep[t2][t1]=1;
			int u=find(t1),v=find(t2);
			if(t1!=t2){
				f[t1]=t2;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(map[i][k]!=INF&&map[k][j]!=INF)
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
				if(dep[i][k]!=INF&&dep[k][j]!=INF)
				dep[i][j]=min(dep[i][j],dep[i][k]+dep[k][j]);
			}
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}*/
	while(q--){
		cin>>t1>>t2;
		int u=find(t1),v=find(t2);
		if(u==v) cout<<"Balance"<<endl;
		else if(map[t2][t1]==INF&&map[t1][t2]!=INF&&dep[t1][t2]==INF&&dep[t2][t1]!=INF) cout<<"Left"<<endl;
		else if(map[t1][t2]==INF&&map[t2][t1]!=INF&&dep[t2][t1]==INF&&dep[t1][t2]!=INF) cout<<"Right"<<endl;
		else cout<<"Unknown"<<endl; 
	}
}
