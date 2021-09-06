#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=10007;
LL ksm(LL a,LL b,LL p){
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;    
    }
    return res;
}
LL C(LL a,LL b,LL p){
    if(a<b) return 0;
    if(b==0||b==a) return 1;
    if(b>a-b) b=a-b;
    LL up,down,res=1;
    for(int i=1;i<=b;i++){
        up=(a-i+1)%p;
        down=(i)%p;
        res=(res*((up*ksm(down,p-2,p))%p))%p;
    }
    return res;
}
LL Lucas(LL a,LL b,LL p){
    if(a<b) return 0;
    if(b==0||b==a) return 1;
    LL res=1;
    while(a&&b&&res){
        res=(res*C(a%p,b%p,p))%p;
        a/=p;
        b/=p;
    }
    return res;
}
LL lucas(LL a,LL b,LL p){
    if(b==0) return 1;
    return C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
int main(){
	LL a,b,k,n,m; 
    scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
    printf("%lld",Lucas(k,m,mod)*ksm(a,n,mod)*ksm(b,m,mod)%mod);
    return 0;
}
