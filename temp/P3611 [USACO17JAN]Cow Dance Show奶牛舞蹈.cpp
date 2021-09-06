#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n,tmax,a[1000005];
void clear(priority_queue<int>& q) {
    priority_queue<int> empty;
    swap(empty, q);
}
int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;	
}
int now,tt;
bool check(int k){
	clear(q);
	for(int i=1;i<=k;i++){
		q.push(-a[i]);
	}
	for(int i=k+1;i<=n;i++){
		now=-q.top();q.pop();
		tt=now+a[i];
		if(tt>tmax) return 0;
		q.push(-tt);
	}
	while(!q.empty()){
		now=-q.top();q.pop();
		if(now>tmax) return 0;
	}
	return 1;
}
int main(){
	n=read();tmax=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
		//	ans=min(ans,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",l);
}
