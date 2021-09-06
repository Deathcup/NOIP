#include<bits/stdc++.h>
using namespace std;
int n,m,pre[2005][2005],s[2005][2005],t,k,ans;
void init(){
	pre[1][0]=1;pre[1][1]=1;
	for(int i=2;i<=2001;i++){
		for(int j=0 ;j<=i+1;j++){
			if(j==0)
			pre[i][j]=pre[i-1][j]%k;
			else 
			pre[i][j]=(pre[i-1][j]%k+pre[i-1][j-1]%k)%k;
		}
	}
}
void init_s(){
    for(int i=1;i<=2000;i++)
        for(int j=1;j<=2000;j++)
        {
             s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
                if(pre[i][j]==0&&j<=i)
                    s[i][j]++;//Ç°×ººÍ
        }
}
int main(){
	cin>>t>>k;
	init();
	init_s();
	while(t--){
		cin>>n>>m;
		ans=0;
/*		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(i,m);j++){
				if(pre[i][j]==0) ans++;
			}
		}*/
		if(m>n) m=n;
		ans=s[n][m];
		cout<<ans<<endl;
	}
}
