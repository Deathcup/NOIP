#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=1000001;
int n,m,root;
struct node
{
    int u;
    int v;
    int next;
}edge[MAXN];
int num=1;
int head[MAXN];
int deep[MAXN];
int f[MAXN][20];
void edge_add(int x,int y)
{
    edge[num].u=x;
    edge[num].v=y;
    edge[num].next=head[x];
    head[x]=num++;
}
void build_tree(int p)
{
    for(int i=head[p];i!=-1;i=edge[i].next)// 遍历与p节点相邻的节点 
    {
        int will=edge[i].v;
        if(deep[will]==0)// 如果点will没有被访问过的话 
        {
            deep[will]=deep[p]+1;// 则点will的深度==p的深度+1 
            f[will][0]=p;// will点向上跳2^0的节点是p 
            build_tree(will);//继续初始化will节点 
        }
    }
}
void initialize_step()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    // 第j个节点，向上跳i能到达的节点就是 跳到i-1处再向上跳i-1能到达的节点
    // 因为倍增是以次方的形式增加的 
}
int LCA(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);// 如果说节点x的深度比节点y的深度小的话，就交换他俩的位置，让x<y 
    for(int i=19;i>=0;i--)// 因为跳的步数越小越好，所以从最大的值开始跳
    {
        if(deep[f[x][i]]>=deep[y])// 如果跳完i步之后x还在y下方的话 ，这里必须加等于号 
        x=f[x][i];// 就更新x的值，继续跳
    }
    if(x==y)return y;//判断一下，如果x和y在同一条线上，就直接返回x的值 ，y也可以 
    for(int i=19;i>=0;i--)//再让x和y一起向上跳
    if(f[x][i]!=f[y][i])
    x=f[x][i],y=f[y][i];// 如果他们跳完之后的祖先不相等的话,就继续跳 
    return f[x][0];//按这样跳下去，一定会跳到只要再跳一步就能找到最近公共祖先的位置！ 
}
void read(int & x)
{
    char c=getchar();x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();// 读入优化，必须要有！ 
}
int main()
{
    //scanf("%d%d%d",&n,&m,&root);
    read(n);read(m);read(root);
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        //scanf("%d%d",&x,&y);
        read(x);read(y);
        edge_add(x,y);
        edge_add(y,x);
    }
    deep[root]=1;//将根节点的深度设为1 
    build_tree(root);// 建立起一棵树 
    	cout<<endl;
	for(int i=1;i<=n;i++) cout<<deep[i]<<" ";
	cout<<endl;
    initialize_step();// 初始化向上跳的距离 
    for(int i=1;i<=m;i++)
    {
        int x,y;
        //scanf("%d%d",&x,&y);
        read(x);read(y);// 求x与y的最近公共祖先
        printf("%d\n",LCA(x,y));// ans 
    }
    return 0;
}
