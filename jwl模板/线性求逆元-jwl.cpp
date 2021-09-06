#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL n,p;
LL inv[3000005];
void init(){
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=(p-p/i)*inv[p%i]%p;
    }
}
inline void write(LL x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void read(LL &x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
}
int main(){
    read(n);read(p);
    init();	
    for(int i=1;i<=n;i++){
        write(inv[i]);putchar('\n');
    }
}
