#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int r,l,c;
}a[1001];
int n,ans,dp[1001];
bool cmp1(node x,node y)
{
	return x.r<y.r;
}
inline int read()
{
    int data=0,w=1; char ch=0;
    while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
    if(ch=='-') w=-1,ch=getchar();
    while(ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
    return data*w;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i].l=read();
		a[i].r=read();
		a[i].c=read();
	} 
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++)
	{
		int maxn=0;
		for(int j=1;j<=i;j++)
		{
			if(a[i].l>=a[j].r)  maxn=max(maxn,dp[j]);
		} 
		dp[i]=maxn+a[i].c;
		ans=max(ans,dp[i]);
	}
	write(ans);
	return 0;
}
