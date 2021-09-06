#include<cstdio>
#include<iostream>
using namespace std;
long long n,m,ans;
long long cal(long long p,long long a)
{
	long long t=0;
	for (long long i=n;i;i/=p) t+=i/p;
	return t/a;
}
int main()
{
	while(scanf("%lld%lld",&n,&m)==2){
	ans=9223372036854775806;
	for (long long t,s,i=2;i*i<=m;i++)
		if (m%i==0)
		{
			t=i;s=0;
			for (;m%i==0;m/=i) ++s;
			ans=min(ans,cal(t,s));
		}
	if (m>1) ans=min(ans,cal(m,1));
	printf("%lld\n",ans);		
	}

}
