#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=100005;
LL tree[280000],mark[280000],lazy[28000];
LL n,m,M,lb;
LL p;
void build(){
	for(M=1;M-2<n;M<<=1);
	for(int i=M+1;i<=M+n;i++)	scanf("%lld",&tree[i]);
	for(int i=M-1;i;i--) tree[i]=tree[i<<1]+tree[i<<1|1]; 
}
int getdeep(int x){
	int i=0;
	while(x>>=1) i++;
	return i;
}
void up(int x,LL y){
	int tmp=1<<(lb-getdeep(x));
	while(x>>=1) tree[x]+=y*tmp;
}
LL get(LL x){
	LL tmp=1<<(lb-getdeep(x));
	LL res=tree[x]+mark[x]*tmp;
	do{
		x>>=1;
		res+=mark[x]*tmp;
	}while(x);
//	for(x<<=1;x;x>>=1) res+=mark[x]*tmp;
//	while(x>>=1) res+=mark[x]*tmp;
	return res;
}
void jia(int x,int y,LL z){
	for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1){
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
LL query(int x,int y){
	LL res=0;
	for(x=M+x-1,y=M+y+1;x^y^1;x>>=1,y>>=1){
		if(~x&1) res=(res+get(x^1));
		if(y&1)  res=(res+get(y^1));
	}
	return res;
}
int main(){
	scanf("%lld%lld",&n,&m);
	build();
	lb=getdeep(M);
	int t1,t2,t3;
	LL t4;
	while(m--){
		scanf("%d",&t1);
		if(t1==1){
			scanf("%d%d%lld",&t2,&t3,&t4);
			jia(t2,t3,t4);
		}
		else{
		//	for(LL i=M-1;i;i--) tree[i]=(tree[i<<1]+tree[i<<1|1])%p; 
			scanf("%d%d",&t2,&t3);
			printf("%lld\n",query(t2,t3));
		}
	}
}
