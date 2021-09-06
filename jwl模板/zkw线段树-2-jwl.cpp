//Çø¼äºÍ 
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e7;
int n,m,M,tree[N<<2];
void build(int x){  
    for(M=1;M<x;M<<=1);  
    for(int i=M+1;i<=M+x;i++) scanf("%d",&tree[i]);  
    for(int i=M-1;i;--i) tree[i]=tree[i<<1]+tree[i<<1|1];  
}  
void change(int x,int c){
	x=M+x;
	tree[x]+=c;
//	while(x) tree[x>>=1]=tree[x<<1]+tree[x<<1|1];
}
/*int change(int x,int y,int c){  
    for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1){
		if(~x&1) tree[x^1]+=k;
		if(y&1) tree[y^1]+=k;
    }
    return res;
}  */
int query(int x,int y){  
	int res=0;
    for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1){
		if((~x)&1) res+=tree[x^1];
		if(y&1) res+=tree[y^1];
    }
    return res;
}  
int main(){
	scanf("%d%d",&n,&m);
	build(n);
	int t1,t2,t3,t4;
	while(m--){
		scanf("%d",&t1);
		if(t1==2){
    		for(int i=M-1;i;--i) tree[i]=tree[i<<1]+tree[i<<1|1];  
			scanf("%d%d",&t2,&t3);
			printf("%d\n",query(t2,t3));			
		}
		else{
			scanf("%d%d%d",&t2,&t3,&t4);
			for(int i=t2;i<=t3;i++){
				change(i,t4);
			}
		}
	}
	return 0;
}
