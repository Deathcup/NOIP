#include<bits/stdc++.h>
using namespace std;
const int N=50001,INF=2147483647;
int tot,head[N],to[N],nex[N],data[N];
void add(int x,int y){
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
int sum[N];
int n,ans,ansid=N*2;
void init_dfs(int x,int fa){
    sum[x]=1;
    for(int i=head[x];i;i=nex[i]){
        if(to[i]==fa) continue;
        init_dfs(to[i],x);
        sum[x]+=sum[to[i]];
        ans+=sum[to[i]];
    }
}
void work(int u,int fa,int cost)
{
    for(int i=head[u];i;i=nex[i])
        if(to[i]!=fa){
            int newcost=cost-sum[to[i]]+sum[1]-sum[to[i]];//从 u 转换到 point[i] 时的距离变化
            if(newcost<ans){ans=newcost;ansid=to[i];}// 更新答案
            if(newcost==ans&&to[i]<ansid)ansid=to[i]; //鉴于要输出最小值，所以加一句
            work(to[i],u,newcost);
        }
}
inline int readin(){
	int data=0,w=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-w,ch=getchar();
	while(ch<='9'&&ch>='0') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
int main(){
    n=readin();
    for(int u,v,i=1;i<=n-1;i++){
        u=readin();v=readin();
        add(u,v);
        add(v,u);
    }
    init_dfs(1,0);
    work(1,0,ans);
    printf("%d %d",ansid,ans);
  //  cout<<ansid<<" "<<ans<<endl;
} 
