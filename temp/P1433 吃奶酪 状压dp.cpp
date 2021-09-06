#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <cmath>
using namespace std;
const int INF = 1e9;
int n;
double x[15];
double y[15];
double dp[15][1<<15];
inline int istrue( int A , int bit )
{
    return A&(1<<bit);
}
inline int set0( int A , int bit )
{
    return A&( ~(1<<bit) );
}
inline double dist( double x1 , double y1 , double x2 , double y2 )
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
void dfs( int now , int S )
{
    if( dp[now][S] != -1 ) return;
    dp[now][S] = INF;
    for( int i = 0 ; i < n ; ++i )
    {
        if( i == now ) continue;
        if( !istrue( S , i ) ) continue;
        dfs( i , set0( S , now ) );
        dp[now][S] = min( dp[now][S] , dp[i][ set0( S , now ) ] + dist( x[i] , y[i] , x[now] , y[now] ) );
    }
}
int main()
{
    cin >> n;
    for( int i = 0 ; i < n ; ++i ) cin >> x[i] >> y[i];
    for( int i = 0 ; i < n ; ++i )
    {
        for( int j = 1 ; j < (1<<n) ; ++j )
        {
            dp[i][j] = -1;
        }
    }
    for( int i = 0 ; i < n ; ++i ) dp[i][1<<i] = dist(0,0,x[i],y[i]);
    for( int i = 0 ; i < n ; ++i ) dfs( i , (1<<n)-1 );
    double mn = INF;
    for( int i = 0 ; i < n ; ++i ) mn = min( mn , dp[i][(1<<n)-1] );
    printf( "%.2lf" , mn );
    return 0;
}
