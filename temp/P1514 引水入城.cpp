#include <bits/stdc++.h>
using namespace std;
const int N=501;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int a[N][N];
int dp[N];
int n,m;
bool vis[N][N],in[N];
struct node{
	int l,r;
}b[N];
bool cmp(node x,node y){
	return x.l<y.l;
}
int tot;
int minn,maxn,end_ans;
inline void dfs(int x,int y){
	vis[x][y]=1;
	if(x==n){
		minn=min(minn,y);
		maxn=max(maxn,y);
	}
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(vis[tx][ty]||tx>n||ty>m||tx<1||ty<1) continue;
		if(a[x][y]>a[tx][ty]) dfs(tx,ty);
	}
	return;
}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		minn=m+1,maxn=-1;
		memset(vis,0,sizeof(vis));
		dfs(1,i);
		if(minn==m+1&&maxn==-1) continue;
		for(int j=minn;j<=maxn;j++){
			in[j]=1;
		}
		b[i].l=minn;
		b[i].r=maxn;
	}
	for(int i=1;i<=m;i++){
		if(!in[i]) end_ans++;
	}
	if(end_ans){
		puts("0");
		printf("%d\n",end_ans);
		return 0;
	}
	sort(b+1,b+1+m,cmp);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
    for (int i=1;i<=m;i++){
        if (a[1][i]<a[1][i-1]) continue;
        for (int j=1;j<=b[i].r;j++){
            dp[j]=min(dp[j],dp[b[i].l-1]+1);
        }
    }
	puts("1");
	printf("%d\n",dp[m]);
}
