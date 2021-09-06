#include <bits/stdc++.h>
using namespace std;
const int N=16;
double d[N][N];
struct node{
    double x,y;
}p[N];
int n;
int read(){
    int data=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) data=data*10+ch-'0',ch=getchar();
    return data;
}
bool vis[N];
/*struct node2{
	bool in[N];
	int id;
}vis;
map<node2,int> h;
int tot;*/
double ans=(double)1e9+1.0;
double res=0.0;
void dfs(int x,int step){
	
    if(res>ans) return;
    if(step==n){
        ans=min(ans,res);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        vis[i]=1;
		res+=d[i][x];
        dfs(i,step+1);
        res-=d[i][x];
        vis[i]=0;
    }
}
void debug(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<d[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    n=read();
//    cout<<(1<<15)<<endl;
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    p[0].x=0;p[0].y=0;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j) d[i][j]=d[j][i]=0;
            else d[i][j]=d[j][i]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        }
    }
//    debug();
    dfs(0,0);
    printf("%.2lf",ans);
}
