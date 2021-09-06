#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,t;
struct node {
	int r,l,data;
}e[1000001];
int tot=1;
void dfs(int x){
	if(x==0) return;
	dfs(e[x].l);
	cout<<x<<" ";
	dfs(e[x].r);
}
int main(){
	cin>>n;
	int now=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t>now){
			if(!e[now].r)	
			e[now].r=t;
			else{
				e[t].l=now;
				now=t;
			}
		}
		if(t<now){
			if(!e[now].l)
			e[now].l=t;
			else{
				e[t].r=now;
				now=t;
			}
		}
		tot=now;
	}
	dfs(tot);
	
} 
