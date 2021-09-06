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
    for(int i=head[p];i!=-1;i=edge[i].next)// ������p�ڵ����ڵĽڵ� 
    {
        int will=edge[i].v;
        if(deep[will]==0)// �����willû�б����ʹ��Ļ� 
        {
            deep[will]=deep[p]+1;// ���will�����==p�����+1 
            f[will][0]=p;// will��������2^0�Ľڵ���p 
            build_tree(will);//������ʼ��will�ڵ� 
        }
    }
}
void initialize_step()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    // ��j���ڵ㣬������i�ܵ���Ľڵ���� ����i-1����������i-1�ܵ���Ľڵ�
    // ��Ϊ�������Դη�����ʽ���ӵ� 
}
int LCA(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);// ���˵�ڵ�x����ȱȽڵ�y�����С�Ļ����ͽ���������λ�ã���x<y 
    for(int i=19;i>=0;i--)// ��Ϊ���Ĳ���ԽСԽ�ã����Դ�����ֵ��ʼ��
    {
        if(deep[f[x][i]]>=deep[y])// �������i��֮��x����y�·��Ļ� ���������ӵ��ں� 
        x=f[x][i];// �͸���x��ֵ��������
    }
    if(x==y)return y;//�ж�һ�£����x��y��ͬһ�����ϣ���ֱ�ӷ���x��ֵ ��yҲ���� 
    for(int i=19;i>=0;i--)//����x��yһ��������
    if(f[x][i]!=f[y][i])
    x=f[x][i],y=f[y][i];// �����������֮������Ȳ���ȵĻ�,�ͼ����� 
    return f[x][0];//����������ȥ��һ��������ֻҪ����һ�������ҵ�����������ȵ�λ�ã� 
}
void read(int & x)
{
    char c=getchar();x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();// �����Ż�������Ҫ�У� 
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
    deep[root]=1;//�����ڵ�������Ϊ1 
    build_tree(root);// ������һ���� 
    	cout<<endl;
	for(int i=1;i<=n;i++) cout<<deep[i]<<" ";
	cout<<endl;
    initialize_step();// ��ʼ���������ľ��� 
    for(int i=1;i<=m;i++)
    {
        int x,y;
        //scanf("%d%d",&x,&y);
        read(x);read(y);// ��x��y�������������
        printf("%d\n",LCA(x,y));// ans 
    }
    return 0;
}
