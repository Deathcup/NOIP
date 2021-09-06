#include <bits/stdc++.h>
using namespace std;
int d[10][10],b[10][10],a[6][4];
int n;
inline bool judge(){
	for(int i=1;i<=5;i++){
		if(d[i][1]!=0) return 0;
	}
	return 1;
}
inline void down(){
	for(int i=1;i<=5;i++){
		for(int j=2;j<=7;j++){
			int k=j;
			while(d[i][k]!=0&&d[i][k-1]==0&&k-1>=1){
				swap(d[i][k],d[i][k-1]);
				k--;
			}
		}
	}
}
inline void cle(){
	down();
	bool cc=0;
	memset(b,0,sizeof(b));
	for(int i=1;i<=5;i++){
		for(int j=1;j<=7;j++){
			b[i][j]=d[i][j];
		}
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<=7;j++){
			if(b[i][j]==0) break;
			if(b[i][j]==b[i][j+1]&&b[i][j+1]==b[i][j-1]){
				cc=1;
				d[i][j]=d[i][j+1]=d[i][j-1]=0;
			}
			if(b[i][j]==b[i+1][j]&&b[i+1][j]==b[i-1][j]){
				cc=1;
				d[i][j]=d[i+1][j]=d[i-1][j]=0;
			}
		}
	}
	if(cc){
		cle();
	}
}
inline void dfs(int u){
	int c[10][10];
	if(u==n+1){
		if(judge()){
			for(int i=1;i<=n;i++){
				printf("%d %d %d\n",a[i][1],a[i][2],a[i][3]);
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<=7;j++){
			if(d[i][j]==0) break;
			for(int l=1;l<=5;l++){
				for(int r=1;r<=7;r++){
					c[l][r]=d[l][r];
				}
			}
			if(d[i][j]!=d[i+1][j]&&i+1<=5){
				swap(d[i][j],d[i+1][j]);
				cle();
				a[u][1]=i-1;
				a[u][2]=j-1;
				a[u][3]=1;
				dfs(u+1);
				for (int l=1;l<=5;l++)
					for (int r=1;r<=7;r++) 
						d[l][r]=c[l][r];
			}
			if(d[i-1][j]==0&&i-1>=1){
				swap(d[i-1][j],d[i][j]);
				cle();
				a[u][1]=i-1;
				a[u][2]=j-1;
				a[u][3]=-1;
				dfs(u+1);
				for (int l=1;l<=5;l++)
					for (int r=1;r<=7;r++) 
						d[l][r]=c[l][r];
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int t,lv,i=1;i<=5;i++){
		lv=0;
		while(scanf("%d",&t)==1){
			if(t==0) break;
			d[i][++lv]=t;
		}
	}
	dfs(1);
	cout<<-1<<endl;
}
