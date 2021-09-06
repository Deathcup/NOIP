#include<cstdio>
#define MAXN 26
#include<cstdlib>
#include<cstring>
int a[MAXN+10],n,e[MAXN+10];
char x[MAXN+10],y[MAXN+10],z[MAXN+10];
bool vis[MAXN+10];
void print(){
    for(int i=0;i<n-1;i++)
            printf("%d ",a[i]);
        printf("%d",a[n-1]);
}
void prepare(){
    int i,cnt=0;
    for(i=n-1;i>=0;i--){
        if(!vis[x[i]]){
            e[++cnt]=x[i];
            vis[x[i]]=1;
        }
        if(!vis[y[i]]){
            e[++cnt]=y[i];
            vis[y[i]]=1;
        }
        if(!vis[z[i]]){
            e[++cnt]=z[i];
            vis[z[i]]=1;
        }
    }
}
bool check(){
    int i,jw=0;
    for(i=n-1;i>=0;i--){
        if(a[x[i]]==-1||a[y[i]]==-1||a[z[i]]==-1)
            jw=-1;
        else{
            if(jw==-1){
                if((a[x[i]]+a[y[i]])%n==a[z[i]])
                    jw=(a[x[i]]+a[y[i]])/n;
                else if((a[x[i]]+a[y[i]]+1)%n==a[z[i]])
                    jw=(a[x[i]]+a[y[i]]+1)/n;
                else
                    return 0;
            }
            else if((a[x[i]]+a[y[i]]+jw)%n==a[z[i]])
                jw=(a[x[i]]+a[y[i]]+jw)/n;
                else
                    return 0;
        }
    }
    if(jw!=1)
        return 1;
    return 0;
}
void dfs(int i){
    if(i>n){
        print();
        exit(0);
    }
    int j;
    for(j=n-1;j>=0;j--){
        a[e[i]]=j;
        if(!vis[j]&&check()){
            vis[j]=1;
            dfs(i+1);
            vis[j]=0;
        }
    }
    a[e[i]]=-1;
}
int main()
{
    memset(a,-1,sizeof a);
    scanf("%d",&n);
    scanf("%s%s%s",x,y,z);
    for(int i=0;i<n;i++)
        x[i]-='A',y[i]-='A',z[i]-='A';
    prepare();
    memset(vis,0,sizeof vis);
    dfs(1);
}
