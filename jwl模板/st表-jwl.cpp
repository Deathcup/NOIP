#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e6;
int n,m,st[N][20];
void init(){
	for(int j=1;j<=19&&(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)<=n+3;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
} 
int RMQ(int x,int y){
	int k=log(y-x+0.5)/log(2.0);
	return max(st[x][k],st[y-(1<<k)+1][k]);
}
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		st[i][0]=read();
	}
	init(); 
	int t1,t2;
	while(m--){
		t1=read();t2=read();
		printf("%d\n",RMQ(t1,t2));
	}
}
