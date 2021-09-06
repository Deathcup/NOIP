#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
const int N=1e7;
int dui[N],head,tail;
int a[N],Max[N],Min[N];
int n,k;
void Get_Min(){
	memset(dui,0,sizeof(dui));
	head=1;tail=0;
	Min[1]=a[1];
	dui[++tail]=1;
	for(int i=2;i<=n;i++){
		while(tail>=head&&a[i]<=a[dui[tail]]) tail--;
		dui[++tail]=i;
		while(tail>=head&&dui[head]<i-k+1) head++;
		Min[i]=a[dui[head]];
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Get_Min();
	for(int i=k;i<=n;i++){
		printf("%d\n",Min[i]);
	}
}
