#include<iostream>
#include<cstdio>
using namespace std;
bool c[9][9];
int n,a[9],ans;
void dfs(int x){
	if(x==n+1){
		ans++;	
	}
	else{
		bool cc;
	for(int i=1;i<=4;i++)
	{
		cc=1;
		for(int j=1;j<=x;j++)
		{
			if(c[x][j]==1&&a[j]==i)
			{
				cc=0;
				break;
			}
		}
		if(cc==0) continue;
		a[x]=i;
		dfs(x+1);
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
