#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=50005,INF=2147483647;
int n,m,army[N],t1,t2,t3,t,k,cnt,b[N],b_tot,need_tot,minnum;
int head[N],to[N],next[N],tot,pre[N],ans=INF;
bool canmove[N],need[N],toll[N],infect[N],unsafe[N],cc;
ll data[N],dist[N],rest[N];
ll f[N][21][2];
struct node{
	int c,number;
}p[N];
bool cmp2(node x,node y){
	return x.c<y.c;
}
int p_tot;
bool cmp(int x,int y){
	return rest[x]<rest[y];
}
inline ll getlong();
inline void add(int x,int y,ll z){
	to[++tot]=y;
	data[tot]=z;
	next[tot]=head[x];
	head[x]=tot;
}
void dfs(int x){
	infect[x]=1;cc=0;
	for(int i=head[x];i!=-1;i=next[i]){
		cc=1;
		if(!toll[to[i]]&&to[i]!=f[x][0][0]){
			dfs(to[i]);
			if(infect[to[i]]){
				unsafe[x]=1;
			} 
		} 
	}
	if(cc==0) unsafe[x]=1;
}
/*void dfs_dist(int x,int y){
	for(int i=head[x];i!=-1;i=next[i]){
		if(to[i]!=y){
			dist[to[i]]=dist[x]+data[i];
			dfs_dist(to[i],x);
		}
	}
}*/
bool check(int x){
	fill(canmove,canmove+N,0);
	fill(pre,pre+N,0);
	fill(toll,toll+N,0);
	fill(rest,rest+N,0);
	fill(unsafe,unsafe+N,0);
	p_tot=b_tot=0;
	fill(b,b+N,0);
	fill(p,p+N,node{0,0});
	for(int i=1;i<=m;i++){
		t=army[i];k=x;
		for(int j=20;j>=0;j--){
			if(f[t][j][1]<k&&f[t][j][0]!=1&&f[t][j][0]!=0){
				k=k-f[t][j][1];
				t=f[t][j][0];
			}
			if(need[t]){
				t3=t;
				if(f[t][0][1]<k){
					k=k-f[t][j][1];
					t=f[t][j][0];
				}
				canmove[i]=1;
				pre[i]=t3;
				b[++b_tot]=i;
			} 
			else {
				if(f[t][0][1]<=k){
					k=k-f[t][0][1];
					t=f[t][0][0];					
				}
				toll[t]=1;
			}
			rest[i]=k;
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		if(need[i]){
			if(unsafe[i]){
				node nt;
				nt.c=f[i][0][1];
				nt.number=i;
				p[++p_tot]=nt;
			}
		}
	}
	sort(p+1,p+p_tot+1,cmp2);
	sort(b+1,b+1+b_tot,cmp);
/*	for(int i=1;i<=n;i++){
		cout<<toll[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<infect[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<unsafe[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=p_tot;i++){
		cout<<p[i].number<<" "<<p[i].c<<endl;
	}
	for(int i=1;i<=b_tot;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=b_tot;i++){
		if(unsafe[pre[b[i]]]) unsafe[pre[b[i]]]=0;
		else{
			for(int j=1;j<=p_tot;j++){
				if(unsafe[p[j].number]&&p[j].c<=rest[b[i]]){
					unsafe[p[j].number]=0;
					break;
				} 
			}
		}
	}
/*	for(int i=1;i<=n;i++){
		cout<<unsafe[i]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=p_tot;i++){
		if(unsafe[p[i].number]) return 0;
	}
	return 1;
/*	for(int i=1;i<=m;i++){
		cout<<rest[i]<<" ";
	}
	for(int i=1;i<=m;i++){
		cout<<canmove[i]<<" ";
	}*/
}
int main(){
	n=getlong();
	fill(head,head+N,-1);
	for(int i=1;i<=n-1;i++){
		t1=getlong();t2=getlong();t3=getlong();
		add(t1,t2,t3);
		f[t2][0][0]=t1;
		f[t2][0][1]=t3;
	}
	m=getlong();
	for(int i=head[1];i!=-1;i=next[i]) need[to[i]]=1,k++;
	need_tot=k;
	if(m<k){
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		army[i]=getlong();
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			f[i][j][0]=f[f[i][j-1][0]][j-1][0];
			f[i][j][1]=f[f[i][j-1][0]][j-1][1]+f[i][j-1][1];
		}
	}
//	cout<<f[5][][1];
//	cout<<check(1);
//	dfs_dist(1,0);
	int l=0,r=500000,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=min(ans,mid),r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
} 
inline ll getlong(){
	ll data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
/*
6
1 2 1
2 6 3
1 3 2
3 4 3
4 5 1
4
2 2 5 6
*/
