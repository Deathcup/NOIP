#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int N=30;
int a[N][N];
int n,m,r,c;
int f[N][N];
int w[N][N];
bitset<20>now;
int calc(int x)
{
    int last=0x3f3f3f3f,ret=0;
    for(int i=0;i<m;i++)
    if(now[i])
    {
        if(last!=0x3f3f3f3f)
        ret+=abs(a[x][i+1]-last);
        last=a[x][i+1];
    }
    return ret;
}
int work(int x,int y)
{
    if(y==0)return 0;
    int ret=0;
    for(int i=0;i<m;i++)
    if(now[i])
    ret+=abs(a[x][i+1]-a[y][i+1]);
    return ret;
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        int t1=calc(i);
        for(int j=i-1;j>=0;j--)
        w[i][j]=t1+work(i,j);
    }
}
void dp()
{
    int ans=0x3f3f3f3f;
    for(int s=0;s<(1<<m);s++)
    {    
        now=s;
        if(now.count()!=c)continue;
        memset(f,0x3f,sizeof f);
        f[0][0]=0;
        init();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                for(int k=0;k<i;k++)
                f[i][j]=min(f[k][j-1]+w[i][k],f[i][j]);
            }
            ans=min(ans,f[i][r]);
        }
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    scanf("%d",&a[i][j]);
    dp();
}
