#include<bits/stdc++.h>
using namespace std;
int n;
bool dp[2001][2001];
int hight[101];int sum;int max_h;
int ans=0;
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0'); 
}
int main()
{
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(hight[i]);
        sum+=hight[i];
    }
    dp[0][0]=true;max_h=sum/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=max_h;j>=0;j--)
        {
            for(int k=max_h;k>=0;k--)
            {
                if(dp[j][k]==true)
                {
                    dp[j+hight[i]][k]=true;dp[j][k+hight[i]]=true;
                }
            }
        }
    }
    for(int i=0;i<=max_h;i++)
    {
        if(dp[i][i])ans=i;
    }
    if(ans==0)	puts("Impossible");
    else write(ans),putchar('\n');
    return 0;
}
