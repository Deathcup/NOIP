#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6,INF=2147483645;
int n,k;
struct zkw{
	int segtree[N<<2];
	int bit;
	void build(int x){
		for(bit=1;bit<x;bit<<=1);
		for(int i=1;i<= bit<<1;i++) segtree[i]=INF;
		for(int i=bit+1;i<=bit+x;i++) scanf("%d",&segtree[i]);
		for(int i=bit-1;i>=0;i--) segtree[i]=min(segtree[i<<1],segtree[i<<1|1]);
	}
	int query(int x,int y){
		int res=INF;
		for(x+=bit-1,y+=bit+1;x^y^1;x>>=1,y>>=1){
			if(~x&1) res=min(res,segtree[x^1]);
			if(y&1)  res=min(res,segtree[y^1]); 
		}
		return res;
	}
}tree;
int main(){
//	zkw tree;
	scanf("%d%d",&n,&k);
	tree.build(n);
	for(int i=k;i<=n;i++){
		printf("%d\n",tree.query(i-k+1,i));
	}
}
