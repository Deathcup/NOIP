#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
char buffer[N],*S,*T; 
int a[N],b[N],tot;
int Get_Int()
{
    char c;  
    int re=0;  
    for(c=getchar();c<'0'||c>'9';c=getchar());  
    while(c>='0'&&c<='9')  
           re=(re<<1)+(re<<3)+(c-'0'),c=getchar();  
    return re;  
}
int ans;
inline void merge(int A[],int l,int r,int left,int right){
    int lpin=l,rpin=left;tot=0;
    while(lpin<=r&&rpin<=right){
        if(A[lpin]<A[rpin]){
            b[++tot]=A[lpin];
            lpin++;
        }
        else{
        	b[++tot]=A[rpin],rpin++;
			ans+=r-lpin+1;	
        } 
    }
    for(;lpin<=r;lpin++) b[++tot]=A[lpin];
    for(;rpin<=right;rpin++) b[++tot]=A[rpin];
    for(int i=1;i<=tot;i++){
        A[l+i-1]=b[i];
    }
}
void msort(int A[],int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    msort(A,l,mid);
    msort(A,mid+1,r);
    merge(A,l,mid,mid+1,r);
}
int main(){
    n=Get_Int();
    for(int i=1;i<=n;i++){
        a[i]=Get_Int();
    }
    msort(a,1,n);
    cout<<ans<<endl;
} 
