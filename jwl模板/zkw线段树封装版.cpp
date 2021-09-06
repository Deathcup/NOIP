#include<iostream>
#include<cstdio>
using namespace std;
const int N=500000;
int n,m;
struct zkw{
	int tree[N<<2];
	int bit;
	void build(int x){
		for(bit=1;bit-2<x;bit<<=1);
		for(int i=bit+1;i<=bit+x;i++) scanf("%d",&tree[i]);
		for(int i=bit;i>=0;i--) tree[i]=tree[i<<1]+tree[i<<1|1]; 
	}
	void jia(int x,int y){
		x=x+bit;
		tree[x]+=y;
		while(x) tree[x>>=1]=tree[x<<1]+tree[x<<1|1];
	}
	int query(int x,int y){
		int res=0;
		for(x=bit+x-1,y=bit+y+1;x^y^1;x>>=1,y>>=1){
			if(~x&1) res+=tree[x^1];
			if(y&1) res+=tree[y^1];
		}
		return res;
	}
}seg; 
int main(){
	scanf("%d%d",&n,&m);
	seg.build(n);
	int t1,t2,t3;
	while(m--){
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==1){
			seg.jia(t2,t3);
		}
		else{
			printf("%d\n",seg.query(t2,t3));
		}
	}
	return 0;
}
