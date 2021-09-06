#include<bits/stdc++.h> 
using namespace std;
const int mod=9901;
map<vector<int>,int> h;
int ans,n,m;
int main(){
	cin>>n>>m;
    vector<int> a(m); //ÔªËØ¸öÊı 
    h[a]=0;
    for(int x,i=1;i<=n;i++){
		cin>>x;
        for(int j=0;j<m;j++)
            if(x&(1<<j)) a[j]++;
        if(x&1)
		for(int j=0;j<m;j++) a[j]--;
        if(h.count(a))	ans=max(ans,i-h[a]);
        else h[a]=i;
    }
   	cout<<ans<<endl;
}
