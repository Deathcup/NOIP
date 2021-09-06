#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],n,len,ans1,ans2;
int main(){
    while(cin>>a[++n]);
    n--;
    memset(b,0x3f,sizeof(b));
    reverse(a+1,a+1+n);
    len=1;
    b[len]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>=b[len]) b[++len]=a[i];
        else{
            int pos=upper_bound(b+1,b+1+len,a[i])-b;
            b[pos]=a[i];
        }
    }
    ans1=len;
//	cout<<len<<endl;
    reverse(a+1,a+1+n);
    memset(b,0x3f,sizeof(b));
    len=1;b[len]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>b[len]) b[++len]=a[i];
        else{
            int pos=lower_bound(b+1,b+1+len,a[i])-b;
            b[pos]=a[i];
        }
    }
    ans2=len;
    printf("%d\n%d\n",ans1,ans2);
}
