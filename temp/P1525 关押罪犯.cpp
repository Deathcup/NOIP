#include<bits/stdc++.h>
using namespace std;
const int N=20005,M=10005;
int n,m,t1,t2,t3,t4;
int f[100500];
struct node{
	int a,b,c;
}e[M];
bool cmp(node x,node y){
	return x.c>y.c;
}
int find(int x){
	return f[x]==x?x:find(f[x]);
}
inline int getint(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while('0'<=ch&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
int main(){
	n=getint();m=getint();
	for(int i=1;i<=n*2;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		e[i].a=getint();e[i].b=getint();e[i].c=getint();
	}
	sort(e+1,e+1+m,cmp);
	int i;
	for(i=1;i<=m;i++){
		t1=find(e[i].a);t2=find(e[i].a+n);
		t3=find(e[i].b);t4=find(e[i].b+n);
		if(t1==t3||t2==t4)	break;
		f[t1]=t4;f[t3]=t2; 
	}
	if(i>m) cout<<0<<endl;
	else cout<<e[i].c<<endl;
	return 0;
}
