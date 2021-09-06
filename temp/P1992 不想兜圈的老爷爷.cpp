#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#define IL inline
using namespace std;
const int N=10005,MOD=9997;
int n,m,k,t1,t2,t,rd[N];
bool cc=1;
int tot,head[N*5],next[N*5],to[N*5];
int dfn[N],low[N],timer;
queue<int> q;
bool instack[N];
IL int ksm(int x,int y){
	int r=1,base=x;
	while(y){
		if(y&1) r=(base*r)%MOD;
		base=(base*base)%MOD;
		y>>=1;
	}
	return r;
}
IL int getint(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch<='9'&&ch>='0') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
IL void add(int x,int y){
	to[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;	
}
void Yes(){
	cout<<"Yes"<<endl<<ksm(2,k)<<endl;
}
void No(){
	cout<<"No"<<endl<<k*k<<endl;
}
bool topsort(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!rd[i]) cnt++,q.push(i);
	}
	while(!q.empty()){
		t=q.front();
		q.pop();
		for(int i=head[t];i!=-1;i=next[i]){
			rd[to[i]]--;
			if(!rd[to[i]]){
				cnt++;
				q.push(to[i]);
			}
		}		
	}
	if(cnt<n) return 0; 
	else return 1;
}
int main(){
	n=getint();m=getint();k=getint();
	fill(head,head+N,-1);
	for(int i=1;i<=m;i++){
		t1=getint();t2=getint();
		rd[t2]++;
		add(t1,t2);
	}
	if(topsort()) Yes();
	else No();
	return 0;
}
