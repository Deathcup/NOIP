#include<bits/stdc++.h>
using namespace std;
const int N=2005*2;
vector<int> e[N*2];
typedef vector<int>::iterator ITER;
int n,m,t,t1,t2,ans;
int master[N*4];
bool vis[N];
inline int getint(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-w,ch=getchar();
	while(ch>='0'&&ch<='9') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
inline void add(int x,int y){
	e[x].push_back(y);
}
 bool fate(int U)
 {
     for(ITER it=e[U].begin();it!=e[U].end();it++)
       if(!vis[*it])
         {
           vis[*it]=1;
           if(master[*it]==-1||fate(master[*it]))
             {
               master[*it]=U;
               return 1;
             }
         }
       return 0;
 }
bool dfs(int x){
	for(int i=0;i<e[x].size();i++){
		t=e[x][i];
		if(!vis[t]){
			vis[t]=1;
			if(master[t]==-1 || fate(master[t])){
				master[t]=x;
				return 1;
			}			
		}
	}
	return 0;
}
int main(){
	n=getint();
	m=n*2;
	fill(master,master+N*4,-1);
	for(int i=1;i<=m;i++){
		t1=getint();t2=getint();
		add(i,t1+m);
		add(i,t1+m+n);
		add(i,t2+m);
		add(i,t2+m+n);
	}
	for(int i=1;i<=m;i++){
		fill(vis,vis+N,0);
		if(fate(i)) ans++;
	}
	cout<<ans<<endl;
}
