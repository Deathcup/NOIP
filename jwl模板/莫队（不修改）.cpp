#include<iostream>
#include<cstdio>
#include<cmath> 
#include<algorithm>
using namespace std;
const int N=50005,M=1000005;
int n,m,a[N],color[M],pos[N],ans[N],gen;
struct node{
	int l,r,id;
}q[N<<2];
bool cmp(node x,node y){
	if(pos[x.l]==pos[y.l]) return pos[x.r]<pos[y.r];
	else return pos[x.l]<pos[y.l];
}
bool cmp2(node x,node y){
	if(x.l==y.l) return x.r<y.r;
	else return x.l<y.l;
}
void modui(){
	int l=0,r=0,res=0;
	for(int i=1;i<=m;i++){
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
		ans[q[i].id]=res;
	}
}
int main(){
	scanf("%d",&n);
//	gen=sqrt(n);	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) pos[i]=(i-1)/gen+1;	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	modui();
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
 
