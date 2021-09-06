#include<bits/stdc++.h>
using namespace std;
int n[4],last=-1;
char ch=0;
void read(){
	while(ch=getchar()){
		if(ch=='\n') return;
		if(ch==':'||ch==';'||ch=='=') continue;
		else {
			if(ch=='a'&&last!=-1) n[last]=n[0],last=-1;
			if(ch=='b'&&last!=-1) n[last]=n[1],last=-1;
			if(ch=='c'&&last!=-1) n[last]=n[2],last=-1;
			if(ch=='a'&&last==-1) last=0;
			if(ch=='b'&&last==-1) last=1;
			if(ch=='c'&&last==-1) last=2;
			if(ch<='9'&&ch>='0') n[last]=ch-'0',last=-1;
		}
	}
}
int main(){
	read();
	cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<endl;
}
