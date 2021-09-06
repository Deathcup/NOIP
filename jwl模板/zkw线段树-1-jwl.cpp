//×î´óÖµ 
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e7;
int n,m,M,tree[N<<2];
void build(int x){  
    for(M=1;M<x;M<<=1);  
    for(int i=M+1;i<=M+x;i++) scanf("%d",&tree[i]);  
    for(int i=M-1;i;--i) tree[i]=max(tree[i<<1],tree[i<<1|1]);  
}  
void change(int x,int c){
	x=M+x;
	tree[x]+=c;
	while(x) tree[x>>=1]=max(tree[x<<1],tree[x<<1|1]);
}
int query(int x,int y){  
	int res=0;
    for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1){
		if(~x&1) res=max(res,tree[x^1]);
		if(y&1) res=max(res,tree[y^1]);
    }
    return res;
}  
int main(){
	scanf("%d%d",&n,&m);
	build(n);
	int t1,t2;
	while(m--){
		scanf("%d%d",&t1,&t2);
		printf("%d\n",query(t1,t2));
	}
	return 0;
}
