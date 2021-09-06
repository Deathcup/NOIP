#include<bits/stdc++.h>
using namespace std;
map<string,int> h;
int a[1001],tot;
bool cmp(int x,int y){
	return x>y;
}
void init(){
    h["one"] = h["first"] = h["a"] = h["another"] = 1;
    h["two"] = h["second"] = h["both"] = 4;
    h["three"] = h["third"] = 9;
    h["four"] = 16;
    h["five"] = 25;
    h["six"] = 36;
    h["seven"] = 49;
    h["eight"] = 64;
    h["nine"] = 81;
    h["ten"] = 0;
    h["eleven"] = 21;
    h["twelve"] = 44;
    h["thirteen"] = 69;
    h["fourteen"] = 96;
    h["fifteen"] = 25;
    h["sixteen"] = 56;
    h["seventeen"] = 89;
    h["eighteen"] = 24;
    h["nineteen"] = 61;
    h["twenty"] = 0;
}
int main(){
	init();	
	string s;
	while(cin>>s){
		if(s==".") break;
		for(int i=0;i<s.length();i++){
			if(a[i]<='Z'&&a[i]>='A'){
				a[i]+=32;
			}
		}
		if(h[s]!=0||s=="ten"||s=="twenty"){
			a[++tot]=h[s];
		}
	}
	sort(a+1,a+1+tot,cmp);
	int cc=0;
	if(a[tot]!=0)
	printf("%d",a[tot]),cc=1;
	for(int i=tot-1;i>=1;i--){
		cc=1;
		printf("%02d",a[i]);
	}
	if(!cc) printf("%d\n",(int)cc);
	return 0;
}

