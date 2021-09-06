#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=1e9+7;
long long ans;
int n;
int pr[N],pr_tot,minpr[N];
int cnt[N];
bool ispr[N];
void shai(){
	fill(ispr,ispr+N,1);
	for(int i=2;i<=n;i++){
		if(ispr[i]){
			pr[++pr_tot]=i;
			minpr[i]=pr_tot;
		}
		for(int j=1;j<=pr_tot&&i*pr[j]<=n;j++){
			ispr[i*pr[j]]=0;
			minpr[i*pr[j]]=j;
            if(i%pr[j]==0)break;
		}	
	}
}
int main(){
	cin>>n;
	shai();
	for(int i=2;i<=n;i++){
		for(int j=i;j!=1;j=j/pr[minpr[j]]) cnt[minpr[j]]++;
	}
    for(int i=1;i<=pr_tot;i++)cnt[i]*=2;
    ans=1;
    for(int i=1;i<=n;i++)ans=ans*(cnt[i]+1)%mod;
    cout<<ans<<endl;
}
