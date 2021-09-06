#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001],b[100001],tot;
int mid;
void merge(int A[],int left,int right,int l,int r){
	int i=left,j=l;
	tot=0;
	while(i<=right&&j<=r){
		if(A[i]<A[j]){
			b[++tot]=A[i];
			i++;
		}
		else{
			b[++tot]=A[j];
			j++;
		}
	}
	for(;i<=right;i++) b[++tot]=A[i];
	for(;j<=r;j++) b[++tot]=A[j];
	for(int k=1;k<=tot;k++) A[left+k-1]=b[k];
}
void msort(int A[],int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	msort(A,l,mid);
	msort(A,mid+1,r);
	merge(A,l,mid,mid+1,r);
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	//	merge(a,1,2,3,4);
	msort(a,1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
