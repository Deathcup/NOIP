#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=2;
	int sum=0;
//	while(x-=1) sum++;
	for(x+=1;x;x-=1) sum++;
	cout<<sum;
}
