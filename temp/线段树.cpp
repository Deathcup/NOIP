#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll data,w;
char ch;
ll num[N],n,m;
ll segtree[N*2],add[N*2];
inline ll read(){
	data=0,w=1;ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch<='9'&&ch>='0') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
void up(int x){
	segtree[x]=segtree[x*2]+segtree[x*2+1];
	return;
}
void down(int root,int l,int r ){
	if(add[root]){
		add[2*root]+=add[root];
		add[2*root+1]+=add[root];
        int mid=(l+r)/2;
        segtree[2*root]+=(mid-l+1)*add[root];
        segtree[2*root+1]+=(r-mid)*add[root];
        add[root]=0;
	}
}
void build(int root,int is,int ie){
	if(is==ie){
		segtree[root]=num[is];
		return;
	} 
	else{
		int mid=(is+ie)/2;
		build(2*root,is,mid);
		build(2*root+1,mid+1,ie);
		up(root);
		return;
	}
}
void update(int root, int l, int r, int x, int y, int v)
{
    if (x<=l && r<=y) {
        add[root]+=v;
        segtree[root]+=(r-l+1)*v;
        return;
    }

    down(root, l, r);
    int mid=(l+r)/2;
    if (x<=mid) update(2*root, l, mid, x, y, v);
    if (mid<y) update(2*root+1, mid+1, r, x, y, v);
    up(root);
    return;
}
ll query(int root, int l, int r, int x, int y)
{
    if (x<=l && r<=y) {
        return segtree[root];
    }

    down(root, l, r);
    int mid=(l+r)/2;
    ll ret=0;
    if (x<=mid) ret+=query(2*root, l, mid, x, y);
    if (mid<y) ret+=query(2*root+1, mid+1, r, x, y);
    return ret;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		num[i]=read();
	}
	build(1,1,n);
	ll t1,t2,t3,t4;
	for(int i=1;i<=m;i++){
		t1=read();
		if(t1==1){
			t2=read();t3=read();t4=read();
			update(1,1,n,t2,t3,t4);
		}
		else{
			t2=read();t3=read();
			cout<<query(1,1,n,t2,t3)<<endl;
		}
	}
}
