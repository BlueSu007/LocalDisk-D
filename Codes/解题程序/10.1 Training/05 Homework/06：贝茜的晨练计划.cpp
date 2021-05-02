#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100000
#define TIRED_MAX 505
int n , m , a[LEN] , dp[LEN][TIRED_MAX] ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = m ; j >= 0 ; j-- ) {
            if ( i + j <= n ) {
                dp[i + j][0] = max ( dp[i + j][0] , dp[i - 1][j + 1] ) ; // 一次性必须休息完
            }

            if ( j == 0 ) {
                dp[i][j] = max ( dp[i][j] , dp[i - 1][0] ) ; // 本来就在休息，继续休息
            }
            else {
                dp[i][j] = max ( dp[i][j] , dp[i - 1][j - 1] + a[i] ) ; // 向前走一步
            }
        }
    }

    printf ( "%d" , dp[n][0] ) ;

    return 0 ;
}