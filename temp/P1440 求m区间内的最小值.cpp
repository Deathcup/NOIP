#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue> 
using namespace std;
const int N=1e7;
int dui[N],head,tail;
int a[N],Max[N],Min[N];
int n,k;
void Get_Min(){
	deque<int> Q;
	Q.push_back(1);
	Min[1]=a[1];
	for(int i=2;i<=n;i++){
		while(!Q.empty()&&a[i]<=a[Q.back()]) Q.pop_back();
		Q.push_back(i);
		while(!Q.empty()&&Q.front()<i-k+1) Q.pop_front();
		Min[i]=a[Q.front()];
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Get_Min();
	for(int i=1;i<=n;i++){
		printf("%d\n",Min[i-1]);
	}
}
