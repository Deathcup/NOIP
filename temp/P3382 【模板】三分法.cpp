#include<bits/stdc++.h>
using namespace std;
int n;
double ll,rr;
double a[14];
double count(double x){
	double ret=0;
	for(int i=1;i<=n+1;i++){
		ret+=a[i]*pow(x,n-i+1);
	}
	return ret;
}
double sanfen(double l,double r){
	if(r-l<0.001) return (l+r)/2;
	double t1=0,t2=0,t3=0,t4=0;
	if(l+r<0){
	t2=(l+r)/3;
	t1=(l+r)*2;t1=t1/3;
	t3=count(t1),t4=count(t2);		
	}
	else{
	t1=(l+r)/3;
	t2=(l+r)*2;t2=t2/3;
	t3=count(t1),t4=count(t2);		
	}
	if(t3>t4) return sanfen(l,t2);
	else return sanfen(t1,r);
}
int main(){
	cin>>n>>ll>>rr;
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	double lx=ll,rx=rr;
    while(abs(lx-rx)>0.000001)
    {
        double x1=lx+(rx-lx)/3,x2=lx+(rx-lx)/3*2;
        if(count(x1)>count(x2)) rx=x2;
        else lx=x1;
    }
    cout<<lx<<endl;
//	cout<<count(2)<<endl;
//	cout<<sanfen(ll,rr)<<endl;
}
