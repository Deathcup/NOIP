#include<bits/stdc++.h>
using namespace std;
string s[21];
bool cmp(string x,string y){
	return x+y>y+x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	cout<<endl;
}
