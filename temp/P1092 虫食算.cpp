#include<bits/stdc++.h>
using namespace std;
int h[30];
bool vis[30],in[30];
char s1[30],s2[30],s3[30];
int n1[30],n2[30],n3[30];
int n;
int e[30],tot=-1;
void init(){
	for(int i=0;i<n;i++){
		if(!in[n1[i]]) e[++tot]=n1[i],in[n1[i]]=1;
		if(!in[n2[i]]) e[++tot]=n2[i],in[n2[i]]=1;
		if(!in[n3[i]]) e[++tot]=n3[i],in[n3[i]]=1;
	}
	return;
}
bool check(){
	int jw=0;
	for(int i=0;i<n;i++){
		if(h[n1[i]]==-1||h[n2[i]]==-1||h[n3[i]]==-1) jw=-1;
		else{
			if(jw==-1){
				if((h[n1[i]]+h[n2[i]])%n==h[n3[i]]){
					jw=(h[n1[i]]+h[n2[i]])/n;
				}
				else if((h[n1[i]]+h[n2[i]]+1)%n==h[n3[i]]){
					jw=(h[n1[i]]+h[n2[i]]+1)/n;
				}
				else return 0;
			}
			else if((h[n1[i]]+h[n2[i]]+jw)%n==h[n3[i]]){
				jw=(h[n1[i]]+h[n2[i]]+jw)/n;
			}
			else{
				return 0;
			}
		}
	}
	if(jw!=1) return 1;
	return 0; 
}
void dfs(int x){
    if(x>n-1){
  //      if(check()){
            for(int i=0;i<n;i++){
                printf("%d ",h[i]);
            }
            exit(0);
    //    }
    //    return;
    }
    int i;
    for(int i=n-1;i>=0;i--){
    	h[e[x]]=i;
        if(!vis[i]&&check()){
	        vis[i]=1;
	        dfs(x+1);
	        vis[i]=0;        	
        }
  //      h[e[x]]=-1;
//		if(vis[i]) continue;
    }
    h[e[x]]=-1;
	return;
}
int main(){
	memset(h,-1,sizeof(h));
    scanf("%d",&n);
    scanf("%s%s%s",&s1,&s2,&s3);
    for(int i=0;i<n;i++){
        n1[n-i-1]=s1[i]-'A';    
        n2[n-i-1]=s2[i]-'A';        
        n3[n-i-1]=s3[i]-'A';        
    }
    init();
//    h[0]=1;h[1]=0;h[2]=3;h[3]=2;h[4]=4;h[5]=5;h[6]=6;h[7]=7;h[8]=8;h[9]=9;h[10]=10;h[11]=11;h[12]=12;h[13]=13;h[14]=14;h[15]=15;h[16]=16;h[17]=17;h[18]=18;h[19]=19;h[20]=20;
//	cout<<check()<<endl;
    dfs(0);
//    h[0]=1;h[1]=0;h[2]=3;h[3]=4;h[4]=2;
//    cout<<check()<<endl;
}
