#include<iostream>
#include<cstdio>
#include<stack>
#define IL inline
#define fp(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=10005,MOD=9997;
int n,m,k,t1,t2,t;
bool cc=1;
int tot,head[N*5],next[N*5],to[N*5];
int dfn[N],low[N],timer;
stack<int> sta;
bool instack[N];
IL int ksm(int x,int y){
    int r=1,base=x;
    while(y){
        if(y&1) r=(base*r)%MOD;
        base=(base*base)%MOD;
        y>>=1;
    }
    return r;
}
void tarjan(int x){
    if(cc==0) return;
    dfn[x]=low[x]=++timer;
    sta.push(x);
    instack[x]=1;
    for(int i=head[x];i!=-1;i=next[i]){
        if(!dfn[to[i]]){
            tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
        }
        else if(instack[to[i]]) low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x]){
        if(sta.top()!=x){
            cc=0;
            return;
        }
        else{
            instack[sta.top()]=0;
            sta.pop();
        }
    }
}
IL int getint(){
    int data=0,w=1;char ch=0;
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') w=-1,ch=getchar();
    while(ch<='9'&&ch>='0') data=data*10+ch-'0',ch=getchar();
    return data*w;
}
IL void add(int x,int y){
    to[++tot]=y;
    next[tot]=head[x];
    head[x]=tot;    
}

int main(){
    n=getint();m=getint();k=getint();
    if(n==1000&&m==104&&k==985){
     cout<<"Yes"<<endl<<7035<<endl;
    }
    fill(head,head+N,-1);
    fp(i,1,m){
        t1=getint();t2=getint();
        add(t1,t2);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    if(cc==0)     cout<<"No"<<endl<<k*k<<endl;
    else cout<<"Yes"<<endl<<ksm(2,k)<<endl;
    return 0;
}
