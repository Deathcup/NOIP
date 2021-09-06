#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct cmp1 {
        bool operator ()(int &a,int &b){
                return a>b;
        }
};
priority_queue<int,vector<int>,cmp1> q;
int n,ans;
int main(){
        std::cin>>n;
        for(int i=1; i<=n; i++) {
                int t;
                std::  cin>>t;
                q.push(t);
        }
        while(!q.empty()) {
                int t1=q.top(); q.pop();
                if(q.empty()) {
                        cout<<ans<<endl;
                        return 0;
                }
                else{
                        int t2=q.top(); q.pop();
                        ans=ans+t1+t2;
                        q.push(t1+t2);
                }
        }
        return 0;
}
