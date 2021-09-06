#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main(){
	int n;
	cin>>n;
	int k=n,t;
	while(k--){
		cin>>t;
		q.push(-t);
	}
	int ans=0;
	for(int i=1;i<=n-1;i++){
		int a=-q.top();q.pop();
		int b=-q.top();q.pop();
		ans+=a+b;
		q.push(-(a+b));
	}
	cout<<ans<<endl;
	return 0;
}
