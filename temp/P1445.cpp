//P1445
#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const int N=1e6+5;
bool com[N];
int pri[N],tot,g[N],cnt[N];
int n,m,mo=1e9+7;
Ll ans;
void make(){
    for(int i=2;i<=n;i++){
        if(!com[i])pri[++tot]=i,g[i]=tot;
        for(int j=1;j<=tot;j++){
            if(pri[j]*i>n)break;
            com[pri[j]*i]=1;
            g[pri[j]*i]=j;
            if(i%pri[j]==0)break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    make();
    for(int i=2;i<=n;i++)
        for(int x=i;x!=1;x/=pri[g[x]])cnt[g[x]]++;
    for(int i=1;i<=tot;i++)cnt[i]*=2;
    ans=1;
    for(int i=1;i<=n;i++)ans=ans*(cnt[i]+1)%mo;
    printf("%d",ans);
}
