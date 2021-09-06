#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int f[N*3];
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void merge(int x,int y){
 	int r1=find(f[x]),r2=find(f[y]);
    if(r1!=r2)	f[r1]=r2;
}
inline int read()
{
    int sum=0;
    char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
    return sum;
}
int n,k,ans;
int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++){
		f[i]=i;f[i+n]=i+n;f[i+2*n]=i+2*n;
	}
	int t,u,v;
	while(k--){
		t=read();u=read();v=read();
		if(u>n||v>n){
			ans++;continue;
		}
		if(t==1){
			if(find(u+n)==find(v)||find(u+2*n)==find(v)){
				ans++;continue;
			}
			merge(u,v);merge(u+n,v+n);merge(u+2*n,v+2*n);
		}
		else if(t==2){
			if(u==v){
				ans++;continue;
			}
			if(find(u)==find(v)||find(u+2*n)==find(v)){
				ans++;continue;
			}
			merge(u,v+2*n); merge(u+n,v); merge(u+2*n,v+n);
		}
	}
	printf("%d\n",ans);
	return 0;
}
