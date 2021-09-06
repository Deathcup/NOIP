#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
	int x,d,id;
	bool operator<(const node &tt)const{
		return x<tt.x;
	}
}a[N];
int b[N];
int n,m;
int main(){
	cin>>n>>m;
	for(int t1,t2,i=1;i<=n;i++){
		cin>>t1>>t2;
		a[i].x=t1;a[i].d=t2;
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[a[i].id]=i;
		a[i].x+=a[i].d*m;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++){
		if(a[i].x==a[i+1].x) a[i].d=a[i+1].d=0;
	}
	for(int i=1;i<=n;i++){
		cout<<a[b[i]].x<<" "<<a[b[i]].d<<endl;
	}
	return 0;
	
}
