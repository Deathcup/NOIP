#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int a[N],tot;
int n,k,ans,h,b;
int main(){
	cin>>n>>k;
	cin>>h>>b;
	for(int t,c,i=1;i<=n;i++){
		cin>>t>>c;
		if(h+b>=t){
			a[++tot]=c;
		}
	}
	sort(a+1,a+1+tot);
	ans=0;
	for(int i=1;i<=tot;i++){
		if(k-a[i]>=0){
			k-=a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
8 15
20 130
120 3
150 2
110 7
180 1
50 8
200 0
140 3
120 2
*/
