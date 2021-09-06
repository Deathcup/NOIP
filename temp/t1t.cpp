#include <stdio.h>  
#include <queue>  
#include <string.h>  
#include<iostream>
using namespace std;  
  
struct node  
{  
    int x,y,step;  
};  
  
int vis[8][8];  
int sx,sy,ex,ey,n,ans;  
int to[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};  
  
int check(int x,int y)  
{  
    if(x<0 || y<0 || x>=n || y>=n)  
    return 1;  
    if(vis[x][y])  
    return 1;  
    return 0;  
}  
  
void bfs()  
{  
    int i;  
    queue<node> Q;  
    node a,next;  
    a.x = sx;  
    a.y = sy;  
    a.step = 0;  
    vis[sx][sy] = 1;  
    Q.push(a);  
    while(!Q.empty())  
    {  
        a = Q.front();  
        Q.pop();  
        if(a.x == ex && a.y == ey)  
        {  
            ans = a.step;  
            return ;  
        }  
        for(i = 0;i<8;i++)  
        {  
            next = a;  
            next.x+=to[i][0];  
            next.y+=to[i][1];  
            if(check(next.x,next.y))  
            continue;  
            next.step = a.step+1;  
            vis[next.x][next.y] = 1;  
            Q.push(next);  
        }  
    }  
    return ;  
}  
  
int main()  
{  
    char ch1[10],ch2[10];  
	cin>>n;
	char ct;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ct;
			if(ct=='X') ex=i,ex=j;
			if(ct=='O') sx=i,sy=j;
		}
	}  
    memset(vis,0,sizeof(vis));  
    vis[ex+1][ey]=1;
    vis[ex+1][ey+1]=1;
    vis[ex+1][ey-1]=1;
    vis[ex][ey+1]=1;
    vis[ex][ey-1]=1;
    vis[ex-1][ey+1]=1;
    vis[ex-1][ey]=1;
    vis[ex-1][ey-1]=1;
    bfs();  
    printf("%d",ans-1);    
  
    return 0;  
}  
