#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
int n,m;
struct zkw{
	int tree[N<<2],mark[N<<2];
	int bit,lb;
	zkw(){
		bit=0;lb=0;
		memset(tree,0,sizeof(tree));
		memset(mark,0,sizeof(mark));
	}
	int getlong(int x){
		int i=0;
		while(x>>=1) i++;
		return i;
	}	
	void build(int x){
		for(bit=1;bit-2<x;bit<<=1);
		lb=getlong(bit);
		for(int i=bit+1;i<=bit+x;i++) scanf("%d",&tree[i]);
		for(int i=bit-1;i;i--) tree[i]=tree[i<<1]+tree[i<<1|1];
	}
	void up(int x,int y){
		int tmp=1<<(lb-getlong(x));
		while(x>>=1) tree[x]+=y*tmp;
	}
	int get(int x){
		int tmp=1<<(lb-getlong(x));
		int res=tree[x]+mark[x]*tmp;
		do{
			x>>=1;
			res+=mark[x]*tmp;
		}while(x);
		return res;
	}
	void jia(int x,int y,int z){
		for(x+=bit-1,y+=bit+1;x^y^1;x>>=1,y>>=1){
			if(~x&1){
				mark[x^1]+=z;
				up(x^1,z);
			}
			if(y&1){
				mark[y^1]+=z;
				up(y^1,z);
			}
		}
	}
	int query(int x,int y){
		int res=0;
		for(x+=bit-1,y+=bit+1;x^y^1;x>>=1,y>>=1){
			if(~x&1) res+=get(x^1);
			if(y&1) res+=get(y^1);
		}
		return res;
	}
}seg;
int main(){
	scanf("%d%d",&n,&m);
	seg.build(n);
	int t1,t2,t3,t4;
	while(m--){
		scanf("%d",&t1);
		if(t1==1){
			scanf("%d%d%d",&t2,&t3,&t4);
			seg.jia(t2,t3,t4);
		}
		else{
			scanf("%d%d",&t2,&t3);
			printf("%d\n",seg.query(t2,t3));
		}
	}
}

