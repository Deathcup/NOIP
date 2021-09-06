#include<iostream>
#include<cstdio>
using namespace std;
int n,k,pre,p,tk;
int num[24];
inline int read(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return w*data;
}
int main(){
	n=read();k=read();
	if(n<k){
	putchar(-1+'0');return 0;	
	} 
	if(n==k) {for(int i=1;i<=n;i++) putchar(96+i);return 0;}
	p=n-k;tk=k;
	p=p+2;
	while(p--){
			if(pre==1) putchar(98),pre=2;
			else putchar(97),pre=1;
	}
		for(int i=3;i<=k;i++){
			putchar(96+i);
		}
}
