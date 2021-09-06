#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int data,w;char ch;
int n;
int a[N][3];
int f[N][3];
int pre[N];
inline int read(){
	data=0;w=1;ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch<='9'&&ch>='0') data=data*10+ch-'0',ch=getchar();
	return data*w;
}
int main(){
	n=read();
	for(int j=0;j<=2;j++)
	for(int i=1;i<=n;i++){
		a[i][j]=read();
	}
	pre[2]=a[1][0];
	for(int i=2;i<=n;i++){
		for(int p=0;p<=2;p++){
			for(int j=1;j<=i-1;j++){
				for(int k=0;k<=2;k++){
					if(p==0){
						if(a[j][k]<=a[i][p]){
							f[i][p]=max(f[i][p],f[j][k]+1);
						}
					}
					if(p==1){
						if(a[j][k]>=a[i][p]){
							f[i][p]=max(f[i][p],f[j][k]+1);
						}
					}
					if(p==2&&k!=2){
						if(f[i][p]<f[j][k]+1){
							f[i][p]=f[j][k]+1;
							pre[i]=-1;
						}
					}
					if(p==2&&k==2){
						if(pre[j]==-1){
							if(f[i][p]<f[j][k]+1){
								f[i][p]=f[j][k]+1;	
								pre[i]=a[j][k];								
							}
						}
						else if(pre[j]<=a[j][k]&&a[j][k]<=a[i][p]){
							if(f[i][p]<f[j][k]+1){
								f[i][p]=f[j][k]+1;
								pre[i]=a[j][k];
							}
						}
						else if(pre[j]>=a[j][k]&&a[j][k]>=a[i][p]){
							if(f[i][p]<f[j][k]+1){
								f[i][p]=f[j][k]+1;
								pre[i]=a[j][k];
							}
						}
					}
				}
			}			
		}

	}
	int ans=-1;
	for(int i=0;i<=2;i++)	ans=max(ans,f[n][i]);
	ans++;
	printf("%d\n",ans);
	return 0;
}
