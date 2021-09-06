#include <bits/stdc++.h>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
map<string,int> h;
string st;
string es="123804765";
struct node{
	string s;
	int x,y,step;
};
int sx,sy,ti;
int map_tot;
void init(){
	if(ti==0) sx=1,sy=1;
	if(ti==1) sx=1,sy=2;
	if(ti==2) sx=1,sy=3;
	if(ti==3) sx=2,sy=1;
	if(ti==4) sx=2,sy=2;
	if(ti==5) sx=2,sy=3;
	if(ti==6) sx=3,sy=1;
	if(ti==7) sx=3,sy=2;
	if(ti==8) sx=3,sy=3;
}
/*void change_a(string &ts,int &A[][]){
	for(int i=0;i<3;i++) A[1][i+1]=ts[i];
	for(int i=0;i<3;i++) A[2][i+1]=ts[i+3];
	for(int i=0;i<3;i++) A[3][i+1]=ts[i+6];
}
void change_s(int &A[][],string &ts){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			sprintf(ts,"%d",A[i][j]);
		}
	}
}*/
void bfs(){
	queue<node> q;
//	h[st]=++map_tot;
	q.push(node{st,sx,sy,0});
	while(!q.empty()){
		string ns=q.front().s;
		int nx=q.front().x,ny=q.front().y;
		int nstep=q.front().step;
		q.pop();
		if(ns==es){
	//		cout<<ns<<endl;
			cout<<nstep<<endl;
			exit(0);
		}
		if(h[ns]!=0) continue;
		else h[ns]=++map_tot;
		int a[4][4];
//		change_a(ns,a);
	for(int i=0;i<3;i++) a[1][i+1]=ns[i]-'0';
	for(int i=0;i<3;i++) a[2][i+1]=ns[i+3]-'0';
	for(int i=0;i<3;i++) a[3][i+1]=ns[i+6]-'0';
	//
		for(int i=0;i<4;i++){
			int tx=nx+dx[i];
			int ty=ny+dy[i];
			if(tx<1||tx>3||ty<1||ty>3) continue;
			swap(a[tx][ty],a[nx][ny]);
		//	change_s(a,ns);
			int cnt=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					ns[++cnt]=a[i][j]+'0';
				}
			}
	//		cout<<ns<<endl;
			q.push(node{ns,tx,ty,nstep+1});
			swap(a[tx][ty],a[nx][ny]);
		}
	}

}
int main(){
	cin>>st;
	for(int i=0;i<st.length();i++){
		if(st[i]=='0') ti=i; 
	}
	init();
	if(st==es){
		cout<<0<<endl;
		return 0;
	} 
	bfs();
}
