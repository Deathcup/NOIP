#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;
const int N=1e6+5,INF=2147483645;
int n,m;
struct zkw{
	int mintree[N<<2],maxtree[N<<2];
	int bit=0;
	void build(int x){
		for(bit=1;bit-2<x;bit<<=1);
		for(int i=1;i<=bit*2;i++){
			mintree[i]=INF;
			maxtree[i]=-INF;	
		}
		for(int i=bit+1;i<=bit+x;i++) scanf("%d",&mintree[i]),maxtree[i]=mintree[i];
		for(int i=bit-1;i>=1;i--) mintree[i]=min(mintree[i<<1],mintree[i<<1|1]),maxtree[i]=max(maxtree[i<<1],maxtree[i<<1|1]);
	}
	int query_min(int x,int y){
		int res=INF;
		for(x+=bit-1,y+=bit+1;x^y^1;x>>=1,y>>=1){
			if(~x&1) res=min(res,mintree[x^1]);
			if(y&1)  res=min(res,mintree[y^1]);
		}
		return res;
	}
	int query_max(int x,int y){
		int res=-INF;
		for(x+=bit-1,y+=bit+1;x^y^1;x>>=1,y>>=1){
			if(~x&1) res=max(res,maxtree[x^1]);
			if(y&1)  res=max(res,maxtree[y^1]);
		}
		return res;
	}
}seg;
int main(){
	scanf("%d%d",&n,&m);
	seg.build(n);
	for(int i=m;i<=n;i++){
		printf("%d ",seg.query_min(i-m+1,i));
	}
	printf("\n");
	for(int i=m;i<=n;i++){
		printf("%d ",seg.query_max(i-m+1,i));
	}
	printf("\n");
}
