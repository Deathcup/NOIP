#include<bits/stdc++.h>
using namespace std;
const int N=500001;
struct node{
	int x,y;
}point[N],ans[N];
int tot;
bool cmp(node a,node b){
	if(a.y==b.y) return a.x>b.x;
	else return a.y>b.y;
}
bool cmp2(node a,node b){
	return a.x<b.x;
}
void print(node a){
	cout<<"("<<a.x<<","<<a.y<<")";
}
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>point[i].x>>point[i].y;
	}
	sort(point+1,point+n+1,cmp);
	int maxx=-1;
	for(int i=1;i<=n;i++){
		if(point[i].x>maxx){
			ans[++tot]=point[i];
			maxx=point[i].x;
		}
	}
	sort(ans+1,ans+tot+1,cmp2);
	for(int i=1;i<=tot;i++){
		print(ans[i]);
		if(i!=tot) cout<<",";
		else cout<<endl;
	}
}
