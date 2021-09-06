#include<bits/stdc++.h>
using namespace std;
int main(){
	int l,n;
	cin>>l>>n;
	int minn=-1,maxn=-1;
	for(int t,i=1;i<=n;i++){
		cin>>t;
		minn=max(minn,min(t,l-t+1));
		maxn=max(maxn,max(t,l-t+1));
	}
	cout<<minn<<" "<<maxn<<endl;
}
