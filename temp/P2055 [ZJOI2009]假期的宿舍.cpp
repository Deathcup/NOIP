#include<iostream>
#include<cstdio>
using namespace std;
const int N=51;
int T,n,t,ans;
int master[N];
bool student[N],home[N],a[N][N],vis[N];
bool fate(int x){
	for(int i=1;i<=n;i++)
		if(student[i] && a[x][i] && !vis[i]){
			vis[i]=1;
			if(master[i]==-1||fate(master[i])){
				master[i]=x;
				return 1;
			}
		}
	return 0;
}
void yes(){
	putchar(94);putchar(95);putchar(94);
	cout<<endl;
}
void no(){
	putchar(84);putchar(95);putchar(84);
	cout<<endl;
}
int main(){
	cin>>T;
	while(T--){
		ans=0;
		fill(student,student+N,0);
		fill(home,home+N,0);
		for(int i=1;i<=N;i++)
		fill(a[i],a[i]+N,0);
		fill(master,master+N,-1);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>student[i];
		}
	for(int i=1;i<=n;i++){
		cin>>home[i];
	}
	for(int i=1;i<=n;i++){
		if(student[i]&&!home[i]){
			a[i][i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>t;
			if(student[j]&&t)
			a[i][j]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!student[i]||(student[i]&&!home[i])){
			fill(vis,vis+N,0);
			cnt++;
			if(fate(i)) ans++;
		}
	}
	if(cnt==ans) yes();
	else no();
}
}
