#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=10005,M=1e6+5;
int n,m,gen,a[N],pos[N],color[M],ans[N],tot,timer;
struct node{
	int l,r,id,t;
}q[N];
struct node2{
	int x,y;
}turn[N];
void change(int now,int i,int &res){
	if(turn[now].x>=q[i].l&&turn[now].x<=q[i].r){
		color[a[turn[now].x]]--;
		if(color[a[turn[now].x]]==0) res--;
		color[turn[now].y]++;
		if(color[turn[now].y]==1) res++;
	}
	swap(a[turn[now].x],turn[now].y);
}
bool cmp(node x,node y){
	if(pos[x.l]==pos[y.l]){
		if(pos[x.r]==pos[y.r]) return x.t<y.t;
		else return pos[x.r]<pos[y.r];
	}
	else return pos[x.l]<pos[y.l];
}
void modui(){
	int l=0,r=0,res=0,now=0;
	for(int i=1;i<=tot;i++){
		while(l<q[i].l){
			color[a[l]]--;
			if(color[a[l]]==0) res--;
			l++;
		}
		while(l>q[i].l){
			l--;
			color[a[l]]++;
			if(color[a[l]]==1) res++;
		}
		while(r<q[i].r){
			r++;
			color[a[r]]++;
			if(color[a[r]]==1) res++;
		}
		while(r>q[i].r){
			color[a[r]]--;
			if(color[a[r]]==0) res--;
			r--;
		}
		while(now<q[i].t){
			now++;
			change(now,i,res);
		}
		while(now>q[i].t){
			change(now,i,res);
			now--;
		}
		ans[q[i].id]=res;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	gen=sqrt(n);
	for(int i=1;i<=n;i++){
		pos[i]=(i-1)/gen+1;
		cin>>a[i];
	}
	char t1;
	int t2,t3;
	for(int i=1;i<=m;i++){
		cin>>t1>>t2>>t3;
		if(t1=='Q'){
			q[++tot].l=t2;
			q[tot].r=t3;
			q[tot].id=tot;
			q[tot].t=timer;
		}
		else{
			turn[++timer].x=t2;
			turn[timer].y=t3;
		}
	}
	sort(q+1,q+1+tot,cmp);
	modui();
	for(int i=1;i<=tot;i++){
		cout<<ans[i]<<endl;
	}
}
