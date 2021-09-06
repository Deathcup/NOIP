#include<iostream>
#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1061109567;
int d[55][55][4];
int m[55][55],b[55][55];
bool vis[55][55][4];
int n,mm,sx,sy,ex,ey,sf;
char ch;
struct node{
	int x,y,f;
	bool operator <(const node &c)const{
		if(x==c.x&&y==c.y) return f<c.f;
		else{
			if(x==c.x) return y<c.y;
			else{
				return x<c.x;
			}
		}
	}
};
map<node,int> h;
int tot;
bool in[1111];
void spfa(){
	queue<node> q;
	d[sx][sy][sf]=0;
	node node_t;
	node_t.x=sx;node_t.y=sy;node_t.f=sf;
//	if(h[node_t]==0)	h[node_t]=++tot;
//	in[h[node_t]]=1;
	vis[sx][sy][sf]=1;
	q.push(node_t);
	while(!q.empty()){
		node node_now=q.front();q.pop();
//		in[h[node_now]]=0;		
		int tx=node_now.x,ty=node_now.y,tf=node_now.f;
		vis[tx][ty][tf]=0;
	//	if(tx==2&&ty==5) cin>>ch;
		for(int i=1;i<=3;i++){
			if(tf==0){
				int tox=tx-i;
				int toy=ty;
				if(tox<1||b[tox][toy])	break;
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
			//		if(h[tt]==0) h[tt]=++tot;
					if(!vis[tox][toy][tf]){
						q.push(tt);
			//			in[h[tt]]=1;
						vis[tox][toy][tf]=1;
					}
				}
			}
			else if(tf==1){
				int tox=tx;
				int toy=ty+i;
				if(toy>mm||b[tox][toy]) break;
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
				//	if(h[tt]==0) h[tt]=++tot;
					if(!vis[tox][toy][tf]){
						q.push(tt);
				//		in[h[tt]]=1;
						vis[tox][toy][tf]=1;
					}
				}
			}
			else if(tf==2){
				int tox=tx+i;
				int toy=ty;
				if(tox>n+1||b[tox][toy]) break;
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
				//	if(h[tt]==0) h[tt]=++tot;
					if(!vis[tox][toy][tf]){
						q.push(tt);
				//		in[h[tt]]=1;
						vis[tox][toy][tf]=1;
					}
				}
			}
			else if(tf==3){
				int tox=tx;
				int toy=ty-i;
				if(toy<0||b[tox][toy]) break;
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
				//	if(h[tt]==0) h[tt]=++tot;
					if(!vis[tox][toy][tf]){
						q.push(tt);
				//		in[h[tt]]=1;
						vis[tox][toy][tf]=1;
					}
				}
			}
		}
		for(int i,k=1;k<=3;k+=2){
			i=(tf+k)%4;
			if(i!=tf){
				if(d[tx][ty][i]>d[tx][ty][tf]+1){
					d[tx][ty][i]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tx;tt.y=ty;tt.f=i;
				//	if(h[tt]==0) h[tt]=++tot;
					if(!vis[tx][ty][i]){
						q.push(tt);
				//		in[h[tt]]=1;
						vis[tx][ty][i]=1;
					}
				}
			}
		}	
	}
}
void debug(){
		for(int i=1;i<=n+1;i++){
		for(int j=0;j<=mm;j++){
			printf("%-3d",b[i][j]);
		}
		cout<<endl;
	}
	cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<" "<<endl;
	cout<<endl;
	for(int k=0;k<4;k++){
		for(int i=1;i<=n+1;i++){
			for(int j=0;j<=mm;j++){
				if(d[i][j][k]==INF) printf("%-3d",-1);
				else printf("%-3d",d[i][j][k]);
			}
			cout<<endl;
		}
		cout<<endl;		
	}

}
int main(){
	cin>>n>>mm;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=mm;j++){
			cin>>m[i][j];
		}
	}
	memset(d,0x3f,sizeof(d));
/*	for(int i=0;i<=50;i++){
		for(int j=0;j<=50;j++){
			d[i][j][0]=INF;
			d[i][j][1]=INF;
			d[i][j][2]=INF;
			d[i][j][3]=INF;
		}
	}*/
	cin>>sx>>sy>>ex>>ey>>ch;
	sx++;ex++;
	if(ch=='N') sf=0;
	else if(ch=='E') sf=1;
	else if(ch=='S') sf=2;
	else if(ch=='W') sf=3;
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=mm;j++){
			if(i==1||i==n+1||j==0||j==mm) b[i][j]=1;
			if(m[i][j]){
				b[i][j]=1;b[i][j-1]=1;b[i+1][j]=1;b[i+1][j-1]=1;
			}
		}
	}
//	cout<<b[9][2]<<endl;
	spfa();
//	debug();
	int minn=INF;
	for(int i=0;i<4;i++){
		minn=min(minn,d[ex][ey][i]);
	}
	if(minn==INF) cout<<-1<<endl;
	else cout<<minn<<endl;
}
