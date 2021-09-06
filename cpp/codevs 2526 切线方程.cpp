#include<iostream>
#include<cstdio>
using namespace std;
double a[10];
int n;
double k,b,y,x;
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)	cin>>a[i];
	cin>>x;
	b=1;y=a[0];
	for(int i=1;i<=n;i++)
	{
		k+=a[i]*b*i;
		b*=x;
		y+=a[i]*b;
	} 
	b=y-k*x;
	cout<<k<<" "<<b;
} 
