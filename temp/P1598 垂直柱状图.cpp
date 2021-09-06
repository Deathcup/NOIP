#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char s1[60],s2[60],s3[60],s4[60];
int a[30],maxn=-1;
void deal(string s){
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='A'&&s[i]<='Z')
		a[s[i]-'A'+1]++;
	}
}
void find_max(){
	for(int i=1;i<=26;i++){
		maxn=maxn<a[i]?a[i]:maxn;
	}
}
void print(){
	for(int i=maxn;i>=1;i--){
		for(int j=1;j<=26;j++){
			if(a[j]<i) cout<<" ";
			else cout<<"*";
		}
		cout<<endl;
	}
	for(int i='A';i<='Z';i++){
		cout<<(char)i<<" ";
	}
}
int main(){
	gets(s1);gets(s2);gets(s3);gets(s4);
	deal(s1);deal(s2);deal(s3);deal(s4);
	find_max();
	print();
	return 0;
}
