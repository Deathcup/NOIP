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
            if(a[t]==false){//���·��û�򿪣��ʹ�
                a[t]=true;
            }
            else{//���·�ƴ��ˣ��͹���
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
