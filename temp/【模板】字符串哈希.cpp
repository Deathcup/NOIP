#include<bits/stdc++.h>
using namespace std;
int n;
string t;
std::set<string> s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		s.insert(t);
	}
	cout<<s.size()<<endl;
	return 0;
}
