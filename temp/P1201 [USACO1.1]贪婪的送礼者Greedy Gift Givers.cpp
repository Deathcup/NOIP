#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int N=12;
int n,num[N];
string s;
map<string,int> h;
queue<string> q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		h[s]=i;
		q.push(s);
	}
	int t1,t2,t3;
	for(int i=1;i<=n;i++){
		cin>>s>>t1>>t2;
		if(t1==0){
			for(int i=1;i<=t2;i++){
				cin>>s;
			}	
			continue;
		} 
		else if(t1!=0&&t2==0){
			num[h[s]]+=t1;
			continue;
		}
		else t3=t1/t2;
		num[h[s]]-=t1;
		num[h[s]]+=t1%t2;
		for(int i=1;i<=t2;i++){
			cin>>s;
			num[h[s]]+=t3;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<q.front()<<" "<<num[i]<<endl;
		q.pop();
	}
	return 0;
}
