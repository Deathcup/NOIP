#include<iostream>
#include<cstdio>
using namespace std;
bool c[9][9];
int n,a[9],ans;
void dfs(int x){
	if(x==n+1) return;
	bool ch[5]={1,1,1,1,1};
	for(int i=1;i<=x;i++){
		if(c[i][x]==1) ch[a[i]]=0;
	}
	for(int i=1;i<=4;i++){
		if(ch[i])
		{
			if(x==n) ans++;
			a[x]=i;
			dfs(x+1);
			a[x]=0;
		}
	}
	
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	dfs(1);
	cout<<ans;
}
