#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int g[21][21],mi[21][21];
int m,n,k,cnt,ans;
struct node{
	int p,x,y;
}data[401];
bool cmp(node a,node b){
	return a.p>b.p;
}
int main(){
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]){
				data[++cnt]=node{g[i][j],i,j};
				g[i][j]=min(min(i,m+1-i),min(j,n+1-j));
			}
		}
	}
	sort(data+1,data+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		k-=
	}
}
