#include <bits/stdc++.h>
using namespace std;
const int N=1001;
bool a[N],b[N],c[N];
int ans[N];
int n;
int tot_ans,cnt=0;
void dfs(int x){
	if(x>n){
		tot_ans++;
		if(cnt<3){
			cnt++;
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<endl;
			return;
		}
		else return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]&&!b[i+x]&&!c[x-i+n]){
			a[i]=b[i+x]=c[x-i+n]=1;ans[x]=i;
			dfs(x+1);
			a[i]=b[i+x]=c[x-i+n]=0;ans[x]=0;
		}
	}
	return ;
}
int main(){
	cin>>n;
	dfs(1);
	cout<<tot_ans<<endl;
}
