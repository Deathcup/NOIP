#include<bits/stdc++.h>
using namespace std;
const int N=200001;
//int tot,head[N],to[N],nex[N],data[N];
int d[N];
bool in[N],flag;
struct node{
	int u,v,c;
}e[N];
int T,n,m,tot;
inline void add(int x,int y,int z){
	e[++tot].u=x;e[tot].v=y;e[tot].c=z;
}
inline void read(int &x){
	x=0;int w=1;char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	x=x*w;
}
bool topsort(){
    memset(d,0x7f,sizeof(d));
	d[1]=0;
	for(int i=1;i<=n;i++){
		flag=0;
		for(int j=1;j<=tot;j++){
			if(d[e[j].v]>d[e[j].u]+e[j].c){
				flag=1;
				d[e[j].v]=d[e[j].u]+e[j].c;
			}
		}
		if(!flag) return 0;
	}
	return 1;
}
int main(){
	read(T);
	while(T--){
		tot=0;
		memset(d,0,sizeof(d));
		read(n);read(m);
		int t1,t2,t3;
		for(int i=1;i<=m;i++){
			read(t1);read(t2);read(t3);
			add(t1,t2,t3);
			if(t3>0) add(t2,t1,t3);
		}
		if(topsort()) cout<<"YE5"<<endl;
		else cout<<"N0"<<endl;
	}
}
