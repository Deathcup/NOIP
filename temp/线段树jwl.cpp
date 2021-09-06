#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n,m,q;
int seg[N],lazy[N],num[N];
void up(int p){
	seg[p]=seg[p*2]+seg[p*2+1];
	return;
} 
void down(int p,int l,int r){
	if(lazy[p]){
		lazy[2*p]+=lazy[p];
		lazy[2*p+1]+=lazy[p];
		int mid=(l+r)>>1;
		seg[2*p]+=(mid-l+1)*lazy[p];
		seg[2*p+1]+=(r-mid)*lazy[p];
		lazy[p]=0;
	}
	return;
}
void build(int p,int l,int r){
	if(l==r){
		seg[p]=num[l];
		return;
	} 
	else{
		int mid=(l+r)/2;
		build(2*p,l,mid);
		build(2*p+1,mid+1,r);
		up(p);
		return;
	}
}
void update(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		lazy[p]+=z;
		seg[p]+=(r-l+1)*z;
		return;
	}
	down(p,l,r);
	int mid=(l+r)/2;
	if(x<=mid) update(2*p,l,mid,x,y,z);
	if(y>mid) update(2*p+1,mid+1,r,x,y,z);
	up(p);
	return;
}
int query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return seg[p];
	}
	down(p,l,r);
	int ret=0;
	int mid=(l+r)>>1;
	if(x<=mid) ret+=query(2*p,l,mid,x,y);
	if(y>mid) ret+=query(2*p+1,mid+1,r,x,y);
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	build(1,1,n);
	int t1,t2,t3,t4;
	for(int i=1;i<=n;i++){
		cin>>t1;
		if(t1==1){
			cin>>t2>>t3>>t4;
			update(1,1,n,t2,t3,t4);
		}
		else{
			cin>>t2>>t3;
			cout<<query(1,1,n,t2,t3)<<endl;
		}
	}
}
