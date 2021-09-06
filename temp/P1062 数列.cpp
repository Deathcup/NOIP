#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL; 
const int N=1001;
LL ans,t;
int n,k;
int main(){
    scanf("%d%d",&k,&n);
	t=1;
	while(n){
    	if(n&1) ans+=t;
		n>>=1;
		t=t*k;			
	}
    printf("%lld\n",ans);
    return 0;
}
