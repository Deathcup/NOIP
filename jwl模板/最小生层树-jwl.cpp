#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
const int N=200005;
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int n,m,fa[N],ans,cnt;
struct node{
	int u,v,c;
	bool operator<(const node tt)const{
		return c<tt.c;
	}
}e[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].c=read();
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		int r1=e[i].u,r2=e[i].v;
		r1=find(r1);r2=find(r2);
		if(r1==r2) continue;
		else{
			cnt++;
			ans+=e[i].c;
			fa[r1]=r2;
			if(cnt==n-1){
				break;
			}
		}
	}
	if(cnt==n-1) 
	printf("%d\n",ans);
	else puts("orz");
}
 
