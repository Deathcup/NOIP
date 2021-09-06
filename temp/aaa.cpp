#include<bits/stdc++.h>
using namespace std;
const int INF=1061109567;
int d[55][55][4];//存最短路 0表示N 1表示E 2表示S 3表示W 
int m[55][55],b[55][55];
bool vis[55][55][4];
int n,mm,sx,sy,ex,ey,sf;
char ch;
struct node{
	int x,y,f;
};
void spfa(){ 	//跑一遍最短的路，状态有点多，spfa比堆优化的dijkstra 
	queue<node> q;
	d[sx][sy][sf]=0;
	node node_t;
	node_t.x=sx;node_t.y=sy;node_t.f=sf;
	vis[sx][sy][sf]=1;
	q.push(node_t);
	while(!q.empty()){
		node node_now=q.front();q.pop();	
		int tx=node_now.x,ty=node_now.y,tf=node_now.f;
		vis[tx][ty][tf]=0;
		for(int i=1;i<=3;i++){   //直走 
			if(tf==0){ 			//写到一块太麻烦了不如复制粘贴 
				int tox=tx-i;
				int toy=ty;
				if(tox<1||b[tox][toy])	break; //一定要break 
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
					if(!vis[tox][toy][tf]){
						q.push(tt);
						vis[tox][toy][tf]=1;
					}
				}
			}
			else if(tf==1){
				int tox=tx;
				int toy=ty+i;
				if(toy>mm||b[tox][toy]) break;//我一开始写的continue然后我的机器人就学会了闪现穿墙 
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
					if(!vis[tox][toy][tf]){
						q.push(tt);
						vis[tox][toy][tf]=1;
					}
				}
			}
			else if(tf==2){
				int tox=tx+i;
				int toy=ty;
				if(tox>n+1||b[tox][toy]) break; //就是这个break让我浪费了1个小时 
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
					if(!vis[tox][toy][tf]){
						q.push(tt);
						vis[tox][toy][tf]=1;
					}
				}
			}
			else if(tf==3){
				int tox=tx;
				int toy=ty-i;
				if(toy<0||b[tox][toy]) break;//罪魁祸首！！ 
				if(d[tox][toy][tf]>d[tx][ty][tf]+1){
					d[tox][toy][tf]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tox;tt.y=toy;tt.f=tf;
					if(!vis[tox][toy][tf]){
						q.push(tt);
						vis[tox][toy][tf]=1;
					}
				}
			}
		}
		for(int i,k=1;k<=3;k+=2){ //转向 
			i=(tf+k)%4; 
			if(i!=tf){
				if(d[tx][ty][i]>d[tx][ty][tf]+1){
					d[tx][ty][i]=d[tx][ty][tf]+1;
					node tt;
					tt.x=tx;tt.y=ty;tt.f=i;
					if(!vis[tx][ty][i]){
						q.push(tt);
						vis[tx][ty][i]=1;
					}
				}
			}
		}	
	}
}
void debug(){	//调试的时候用的  
		for(int i=1;i<=n+1;i++){
		for(int j=0;j<=mm;j++){
			printf("%-3d",b[i][j]); //这样输出极其整齐 
		}
		cout<<endl;
	}
	cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<" "<<endl;
	cout<<endl;
	for(int k=0;k<4;k++){
		for(int i=1;i<=n+1;i++){
			for(int j=0;j<=mm;j++){
				if(d[i][j][k]==INF) printf("%-3d",-1); //不然看的眼晕 
				else printf("%-3d",d[i][j][k]);	//我才不是强迫症 
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
	cin>>sx>>sy>>ex>>ey>>ch;
	sx++;ex++;		//emm…行和列有点错位 
	if(ch=='N') sf=0;
	else if(ch=='E') sf=1;
	else if(ch=='S') sf=2;
	else if(ch=='W') sf=3;
	for(int i=1;i<=n+1;i++){ //预处理:把方格图换成点图，不如每次判断很麻烦，50×50时间也不会慢很多，说不定还赚点 
		for(int j=0;j<=mm;j++){
			if(i==1||i==n+1||j==0||j==mm) b[i][j]=1;
			if(m[i][j]){
				b[i][j]=1;b[i][j-1]=1;b[i+1][j]=1;b[i+1][j-1]=1;
			}
		}
	}
	spfa();			//spfa 
//	debug();
	int minn=INF;	//找最小 
	for(int i=0;i<4;i++){
		minn=min(minn,d[ex][ey][i]);
	}
	if(minn==INF) cout<<-1<<endl; //咳咳 一开始忘写了 
	else cout<<minn<<endl;
}
