#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
#define size 200001
int a[size],n,q,st[size][30];
void init(){
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)<=n+1;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int RMQ(int x,int y){
	int k=log(y-x+1)/log(2.0);
	return max(st[x][k],st[y-(1<<k)+1][k]);
}
inline int read(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	init();
	q=read();
	while(q--){
		int tl,tr;
		tl=read();tr=read();
		write(RMQ(tl,tr));
		putchar('\n');
	}
	return 0;
}
