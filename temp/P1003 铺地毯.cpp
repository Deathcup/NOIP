#include<bits/stdc++.h>
using namespace std;
int nn,x,y,k;
int main()
{  
          
    scanf("%d",&nn);   int arry[nn][4];    
    for(int i=1;i<=nn;i++){
        scanf("%d %d %d %d",&arry[i-1][0],&arry[i-1][1],&arry[i-1][2],&arry[i-1][3]);   
    }
    scanf("%d %d",&x,&y);          
    for(int i=1;i<=nn;i++)                          {
        if((x>=arry[i-1][0])&&(x<=arry[i-1][0]+arry[i-1][2])&&(y>=arry[i-1][1])&&(y<=arry[i-1][1]+arry[i-1][3])) {
            k=i;             
        }
    }
    if(k==0)  {
        k=-1;
    }
    printf("%d",k); 
    return 0;
}
