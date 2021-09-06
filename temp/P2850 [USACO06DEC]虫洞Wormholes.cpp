#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5010;
int d[N];
bool in[N],flag;
struct node{
	int u,v,c;
}e[M*2];
int T,n,m,w,tot;
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
		int x,y,z;
        tot=0;
        read(n);read(m);read(w);
        for(int j=1;j<=m;j++){
            read(x);read(y);read(z);
            add(x,y,z);add(y,x,z);
        }
        for(int j=1;j<=w;j++){
            read(x);read(y);read(z);
            add(x,y,-z);
        }
        if(topsort())printf("YES\n");
        else printf("NO\n");
	}
}
