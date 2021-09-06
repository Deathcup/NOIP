#include<bits/stdc++.h>
using namespace std;
const int N=205,M=2005*2,INF=2147483645;

int n,m,s,t,num;
int tot=1,head[N],to[M],nex[M],data[M];
int depth[N],cur[N];

int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
 
void add(int x,int y,int z){
	to[++tot]=y;
	data[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}

bool bfs(){
	queue<int> Q;
	for(int i=0;i<=n+1;i++) depth[i]=0;
	depth[s]=1;
	Q.push(s);
	int u;
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		if(u==t) return 1;
		for(int i=head[u];i;i=nex[i]){
			const int &v=to[i];
			if(data[i]>0&&depth[v]==0){
				depth[v]=depth[u]+1;
			 	Q.push(v);	
			}
		}
	}
	return 0;
} 

int dfs(int u,int flow){
	if(u==t) return flow;
	for(int &i=cur[u];i;i=nex[i]){
		const int &v=to[i];
		if(data[i]!=0&&depth[v]==depth[u]+1){
			int res=dfs(v,min(flow,data[i]));
			if(res>0){
				data[i]-=res;
				data[i^1]+=res;
				return res;
			}
		}
	}
	return 0;
}

int dinic(){
	int res=0;
	while(bfs()){
		for(int i=1;i<=n;i++){
			cur[i]=head[i];
		}
		while(int tt=dfs(s,INF)){
			res+=tt;
		}
	}
	return res;
}
int main(){
	n=read();m=read();num=read();
//	scanf("%d%d%d",&n,&m,&num);
	s=1;t=n;
	int t1,t2,t3;
	for(int i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
//		scanf("%d%d%d",&t1,&t2,&t3);
		add(t1,t2,t3);
		add(t2,t1,0);
	} 
	int ans=dinic(),ans2;
	if(ans==0){
		puts("Orz Ni Jinan Saint Cow!");
		return 0;
	}
	if(num%ans==0) ans2=num/ans;
	else ans2=num/ans+1;
	printf("%d %d\n",ans,ans2);
}

