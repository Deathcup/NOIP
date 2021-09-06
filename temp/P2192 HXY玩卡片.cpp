#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	cin>>n;
	int cnt_5=0,cnt_0=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t==5) cnt_5++;
		else cnt_0++;
	}
	if(cnt_0==0){
		cout<<"-1"<<endl;
		return 0;
	}
	if(cnt_5<9){
		cout<<0<<endl;
		return 0;
	}
   	for (int i = 1;i <= cnt_5 / 9 * 9;i++) cout << 5;
    for (int i = 1;i <= cnt_0;i++) cout << 0;
	cout<<endl;
	return 0;	
}
