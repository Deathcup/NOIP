#include<iostream>
#include<cstdio>
using namespace std;
int f[150001],n,m,t1,t2,t3,ans;
inline int read(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
int find(int x)
{
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}
void init(){
	for(int i=1;i<=3*n;i++){
		f[i]=i;
	}
}
void merge(int x,int y){
	int tx=find(x),ty=find(y);
	f[tx]=ty;
}
void solve(int d,int x,int y){
	if(d==1){
		if(find(x+n)==find(y)||find(x+2*n)==find(y)){
			ans++;return;
		}
		merge(x,y);
		merge(x+n,y+n);
		merge(x+2*n,y+2*n);
	}
	if(d==2){
		if(find(x)==find(y)||find(x+2*n)==find(y)){
			ans++;return;
		}
		merge(x+n,y);
		merge(y+2*n,x);
		merge(y+n,x+2*n);
	}
}
int main(){
	n=read();m=read();
	init();
	for(int i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		if(t2>n||t3>n){
			ans++;continue;
		}
		if(t1==2&&t2==t3){
			ans++;continue;
		}
		solve(t1,t2,t3);
	}
	cout<<ans<<endl;
}
