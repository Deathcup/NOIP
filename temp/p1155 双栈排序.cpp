#include<bits/stdc++.h>
using namespace std;
 typedef vector<int>::iterator ITER;
 stack<int> s1,s2;
int n;
int a[1001];
int color[1001];
vector<int> e[1001];
int f[1001];
inline void  add(int x,int y){
	e[x].push_back(y);
}
 void A(int x){
 	s1.push(a[x]);
 	cout<<"a ";
 }
 void c(int y){
 	s2.push(a[y]);
 	cout<<"c ";
 }
 void b(){
 	s1.pop();
 	cout<<"b ";
 }
 void d(){
 	s2.pop();
 	cout<<"d ";
 }
void  dfs(int x,int fa){
	for(ITER i=e[x].begin();i!=e[x].end();i++){
		if(*i==fa) continue;
		if(color[*i]==0) color[*i]=-color[x];
		else if(color[*i]==color[x]){
			cout<<0<<endl;
			exit(0);
		}
		dfs(*i,x);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[n+1]=2147483647;
	for(int i=n;i>=1;i--) f[i]=f[i+1]<a[i]?f[i+1]:a[i];
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[j+1]<a[i]&&a[i]<a[j]){
//				cout<<i<<" "<<j<<endl;
				add(i,j);add(j,i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(color[i]==0) color[i]=1,dfs(i,0);
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(color[i]==1)	A(i);
		else c(i);
		while((!s1.empty()&&s1.top()==cnt)||(!s2.empty()&&s2.top()==cnt)){
			if(!s1.empty()&&s1.top()==cnt) b();
			else d();
			cnt++;
		}
	}
}
