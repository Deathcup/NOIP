#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int> Q;
int n;
int main(){
	scanf("%d",&n);
	int t1,t2;
	while(n--){
		scanf("%d",&t1);
		if(t1==1){
			scanf("%d",&t2);
			Q.push(-t2);
		}
		else if(t1==2){
			printf("%d\n",-Q.top());
		}
		else{
			Q.pop();
		}
	}
}
