#include<bits/stdc++.h> 
using namespace std;
const int N=410;
//typedef int LL;
int e[N][N]; 
int sum[N][N];
int mod[1000005];
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res;
}
int n,m,k;
long long ans=0;
//LL cal(int sx,int sy,int ex,int ey){
//    return sum[ex][ey]-sum[sx-1][ey]-sum[ex][sy-1]+sum[sx-1][sy-1];
//}
int main(){
	n=read();m=read();k=read();
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++){
			e[i][j]=read();
			sum[i][j]=(e[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1])%k;
		}
	}
	mod[0]=1;
	int t;
	for(register int i=1;i<=m;i++){
		for(register int j=i;j<=m;j++){
			for(register int d=1;d<=n;d++){
				t=(sum[d][j]-sum[d][i-1]+(k<<1))%k;
				ans+=mod[t];
				mod[t]++;
			}
			for(register int d=1;d<=n;d++){
				t=(sum[d][j]-sum[d][i-1]+(k<<1))%k;
				mod[t]--;
			}
//			for(int d=0;d<=k;d++) mod[d]=0;
//			memset(mod,0,sizeof(mod));
//			mod[0]=1;	
		}
	} 
	printf("%lld\n",ans);
}
