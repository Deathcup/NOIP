#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[4][4];
	string ns="123804765";
	for(int i=0;i<3;i++) a[1][i+1]=ns[i]-'0';
	for(int i=0;i<3;i++) a[2][i+1]=ns[i+3]-'0';
	for(int i=0;i<3;i++) a[3][i+1]=ns[i+6]-'0';
	string ts;
	int cnt=-1;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			ts[++cnt]=a[i][j]+'0';
		}
	}
	for(int i=0;i<9;i++){
		cout<<ts[i];
	}
//			cout<<ts<<endl;
}
