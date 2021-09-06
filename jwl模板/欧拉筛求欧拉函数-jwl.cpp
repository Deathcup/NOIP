#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6;
bool ispr[N];
int pr[N],tot,n;
int phi[N];
void shai(){
	for(int i=2;i<=n;i++){
		if(!ispr[i]) pr[++tot]=i,phi[i]=i-1;;
		for(int j=1;pr[j]*i<=n&&j<=tot;j++){
			ispr[pr[j]*i]=1;
			if(i%pr[j]==0){
				 phi[i*pr[j]]=pr[j]*phi[i];  
				 break;
			}
			else{
				 phi[i*pr[j]]=(pr[j]-1)*phi[i];
			}
		}
	}
}
int main(){
	cin>>n;
	shai();
	for(int i=1;i<=tot;i++){
		cout<<phi[i]<<" "; 
	}
} 
