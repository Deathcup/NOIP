#include<bits/stdc++.h>
using namespace std;
double sn;
int k,i;
int main(){
	cin>>k;
	i=1;
	while(1){
		sn+=(1.0)/i;
		if(sn>k) break;
		i++;
	}
	cout<<i;
}
