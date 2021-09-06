#include<bits/stdc++.h>
using namespace std;
const int N=205;
stack<int> sta;
int g[N][N];
int n,cnt[N];
void dfs(int u){
	for(int v=1;v<=N;v++){
		if(g[u][v]){
			g[u][v]-=1;
			g[v][u]-=1;
			dfs(v);
		}
	}
	sta.push(u);
}
int main(){
	cin>>n;
	int t1,t2,minn=2147483645;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		g[t1][t2]+=1;
		g[t2][t1]+=1;
		cnt[t1]^=1;
		cnt[t2]^=1;
	}
	int tot=0;
	int k=2147483645;
	for(int i=1;i<=N;i++){
		if(cnt[i]){
			tot++;
			k=min(k,i);
		}
	}
	if(tot==0){
		dfs(minn);
	}
	else if(tot==2){
		dfs(k);
	}
	else{
		puts("No Solution");
		return 0;
	}
	while(!sta.empty()){
		printf("%c",sta.top());
		sta.pop();
	}
	putchar('\n');
	return 0;
}
