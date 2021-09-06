#include<bits/stdc++.h>
using namespace std;
int n;
bool a[200001];
int main(){
	cin>>n;
	double b;int c;
	int maxt=-1;
	while(n--){
		cin>>b>>c;
		for(int i=1;i<=c;i++){
			double now=b*i;
			int t=(int)now;
            if(a[t]==false){//如果路灯没打开，就打开
                a[t]=true;
            }
            else{//如果路灯打开了，就关上
                a[t]=false;
            }
		}
	}
	for(int i=1;i<=200000;i++){
		if(a[i]==1){
			cout<<i<<endl;
			return 0;
		}
	}
}
