#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const int N=200001;
int st[N][20];
int n,m,p,a,b;
bool flag;
vector<int> e[51];
int read(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
void init(){
	for(int j=1;j<=19;j++){
		for(int i=1;i+(1<<j)<=n+2;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int  RMQ(int l,int r){
	if(l>r) swap(l,r);
	int k=log(r-l+1)/log(2.0);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
void init2(){
	    for(int j=1;j<=19;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
long long ans;
int c[N];
int main(){
	memset(st,0x7f,sizeof(st));
	n=read();m=read();p=read();
	for(int t1,t2,i=1;i<=n;i++){
		t1=read();t2=read();
		st[i][0]=t2;
		c[i]=t1;
		e[t1].push_back(t2);
	}
	init();
	for(int k=0;k<m;k++){
		for(int i=e[k].size()-1;i>=0;i--){
			for(int j=i-1;j>=0;j--){
				int a=e[k][i],b=e[k][j];
				int t=RMQ(a,b);
				if(t<=p){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
