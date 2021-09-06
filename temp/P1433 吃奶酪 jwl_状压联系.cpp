#include <bits/stdc++.h>
using namespace std;
const int N=16;
double d[N][N];
double dp[N][(1<<N)];
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
double ans=(double)1e9+1.0;
double res=0.0;

bool issure(int A,int bit){
	if(A&(1<<bit)==0) return 1;
	else return 0;
}
int zip(int A,int bit){
	return A|(1<<bit);
}
void debug();
int main(){
    n=read();
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
    dp[0][0]=0;
    debug();
 //   dfs(0,0);
  //  printf("%.2lf",ans);
}
void debug(){
	int x=4;
	cout<<zip(4,1)<<endl;
	cout<<issure(zip(4,1),1)<<endl;
}
