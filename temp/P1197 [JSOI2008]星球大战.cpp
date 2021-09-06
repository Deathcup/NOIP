#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,m,f[N*2],rk[N*2],ans[N*2],tot,t1,t2;
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
bool in[N*2];
stack<int> sta;
vector<int> e[N*2];
inline void add(int x,int y){
	e[x].push_back(y);
}
inline void uni(int x,int y){
    if(rk[x]>rk[y]) f[y]=x;
    else{
        f[x]=y; if(rk[x]==rk[y]) rk[y]++;
    }
}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		read(t1);read(t2);
		t1++;t2++;
		add(t1,t2);
		add(t2,t1);
	}
	read(q);
	for(int t,i=1;i<=q;i++){
		read(t);
		t++;
		sta.push(t);
		in[t]=1;
	}
	ans[++tot]=n-q;
	for(int now=1;now<=n;now++){
		if(!in[now])
		for(int i=0;i<e[now].size();i++){
			int &to=e[now][i];
			if(!in[to]){
				t1=find(now);t2=find(to);
				if(t1!=t2){
					ans[tot]--;
					uni(t1,t2);
				}
			}
		}	
	}
	while(!sta.empty()){
		int now=sta.top();
		in[now]=0;sta.pop();
		tot++;
		ans[tot]=ans[tot-1]+1;
		for(int i=0;i<e[now].size();i++){
			int &to=e[now][i];
			if(!in[to]){
				t1=find(now);t2=find(to);
				if(t1!=t2){
					uni(t1,t2);
					ans[tot]--;
				}
			}
		}
	}
	for(int i=tot;i>=1;i--){
		printf("%d\n",ans[i]);
	}
	return 0;
}
