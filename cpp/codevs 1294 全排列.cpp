#include<iostream>
#include<cstdio>
using namespace std;
const int size=11;
int n; 
int a[size];
bool c[size];
inline int read()
{
    int data=0,w=1; char ch=0;
    while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
    if(ch=='-') w=-1,ch=getchar();
    while(ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
    return data*w;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
void print()
{
	for(int i=1;i<=n;i++)
	{
		write(a[i]);putchar(' ');
	}
	putchar('\n');
}
void dfs(int x){
	if(n==x){
		print();
		return;
	}
	for(int i=1;i<=n;i++)
	{	
		if(!c[i]){
			c[i]=1;
			a[x+1]=i;
			dfs(x+1);
			c[i]=0;
		} 
	}
} 
int main(){
	n=read();
	dfs(0);
	return 0;
}
