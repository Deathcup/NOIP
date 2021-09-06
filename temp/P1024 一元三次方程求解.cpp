#include<bits/stdc++.h>
using namespace std;
double a,b,c,d,x1,x2;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
double erfen(double x,double y){
	double l=x,r=y,mid;
	while(abs(r-l)>=0.001){
		mid=(l+r)/2;
		double fmid=f(mid),fl=f(l),fr=f(r);
		if(fl*fmid<0) r=mid;
		else if(fr*fmid<0) l=mid;  
	}
	return mid;
}
void qiugen(){
	double derta=4*b*b-12*a*c;
	derta=sqrt(derta);
	 x1=(-2*b+derta)/(6*a);
	 x2=(-2*b-derta)/(6*a);
	if(x1>x2) swap(x1,x2);
}
int main(){
	cin>>a>>b>>c>>d;
	cout<<setiosflags(ios::fixed);
	qiugen();
	cout<< setprecision(2)<<erfen((double)-100,x1)<<" "<<erfen(x1,x2)<<" "<<erfen(x2,(double)100);
	cout<<endl;
}
