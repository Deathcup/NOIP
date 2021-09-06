#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int tree[N<<2];
int n,m,p,M;
void build(){
	for(M=1;M<n;M<<=1);
	for(int i=M+1;i<=M+n;i++)	scanf("%d",&tree[i]);
	for(int i=M-1;i;i--) tree[i]=(tree[i<<1]+tree[i<<1|1])%p; 
}
void jia(int x,int y){
	x=M+x;
	tree[x]=(tree[x]+y)%p;
//	while(x) tree[x>>=1]=(tree[x<<1]+tree[x<<1|1])%p;
}
void cheng(int x,int y){
	x=M+x;
	tree[x]=(y%p*tree[x]%p)%p;
//	while(x) tree[x>>=1]=(tree[x<<1]+tree[x<<1|1])%p;
}
int query(int x,int y){
	int res=0;
	for(x=M+x-1,y=M+y+1;x^y^1;x>>=1,y>>=1){
		if(~x&1) res=(res+tree[x^1])%p;
		if(y&1)  res=(res+tree[y^1])%p;
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	build();
	int t1,t2,t3,t4;
	while(m--){
		scanf("%d",&t1);
		if(t1==1){
			scanf("%d%d%d",&t2,&t3,&t4);
			for(int i=t2;i<=t3;i++){
				cheng(i,t4);
			}
		}
		else if(t1==2){
			scanf("%d%d%d",&t2,&t3,&t4);
			for(int i=t2;i<=t3;i++){
				jia(i,t4);
			}
		}
		else{
			for(int i=M-1;i;i--) tree[i]=(tree[i<<1]+tree[i<<1|1])%p; 
			scanf("%d%d",&t2,&t3);
			printf("%d\n",query(t2,t3)%p);
		}
	}
}
