#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,t1,t2;
int fa[100001];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty) fa[tx]=ty;
}
bool query(int x,int y){
	if(find(x)==find(y)) return 1;
	else return 0;
}
inline int read(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int main(){
	n=read();m=read();q=read();
	init();
	for(int i=1;i<=m;i++){
		t1=read(),t2=read();
		merge(t1,t2);
	}
	for(int i=1;i<=q;i++){
		t1=read();t2=read();
		if(query(t1,t2))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

}
