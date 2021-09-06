#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[30];
int maxn=1,minn=0x7f;
bool is_prime(int n){//ÅĞËØÉñÆ÷ 
    if(n<2)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
         return false;
    }
    return true;
} 
bool check(int x){
	if(x==0) return 0;
	if(x==1) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
//	for(int i=3;i*i<=x;i+=2){
//		if(x%i==0) return 0;
//	}
	for(int i=1;i<x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		cnt[s[i]-97]++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]!=0)
		maxn=max(maxn,cnt[i]);
		if(cnt[i]!=0)
		minn=min(minn,cnt[i]);
	}
	int k=maxn-minn;
	if(is_prime(k)){
		puts("Lucky Word");
		cout<<k<<endl;
	}
	else{
		puts("No Answer");
		cout<<0<<endl;
	}
	return 0;
}
