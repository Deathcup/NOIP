#include<bits/stdc++.h>
using namespace std;
const int INF=2147483645/2;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool b[25],b[25];
int g[25][25];
int n,n,r,c,p,q,ans=INF;
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int count(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			for(int j=1;j<=n;j++){
				if(!b[j]){
					for(int k=0;k<4;k++){
						int tx=i;
						int ty=j;
						while(1){
							tx+=dx[k];
							ty+=dy[k];
							if(!b[tx]&&!b[ty]) break;
							if(tx>n||tx<1||ty>n||ty<1) break;
						}
						if(tx>n||tx<1||ty>n||ty<1) continue;
						res+=abs(g[i][j]-g[tx][ty]);
						if(res>ans*2) return INF;
					}
		//			if(res>ans*2) return INF;
				}
			}
		}
	}
	return res/2;
}
void dfs(int x,int y){
	if(x==p+1&&y==q+1){
		ans=min(ans,count());
		return;
	}
	if(x!=p+1){
		int s=0;
		for(int i=1;i<=n;i++){
			if(b[i]) s=i;
		}
		for(int i=s+1;i<=n;i++){
//			if(!b[i]){
				b[i]=1;
				dfs(x+1,y);
				b[i]=0;				
//			}

		}		
	}
	else if(x==p+1){
		int s=0;
		for(int j=1;j<=n;j++){
			if(b[j]) s=j;
		}
		for(int j=s+1;j<=n;j++){
//			if(!b[j]){
				b[j]=1;
				dfs(x,y+1);
				b[j]=0;					
//			}
		}
	}
}
int main(){
	n=read();n=read();r=read();c=read();
//	scanf("%d%d%d%d",&n,&n,&r,&c);
	p=n-r;
	q=n-c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
	//		scanf("%d",&g[i][j]);
			g[i][j]=read();
		}
	}
	dfs(1,1);
	printf("%d\n",ans);
//	cout<<ans<<endl;
}
