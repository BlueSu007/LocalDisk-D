#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
int k , dp[LEN] ;

int main () {

    scanf ( "%d" , &k ) ;
    dp[1] = dp[2] = dp[3] = dp[5] = dp[10] = dp[20] = 1 , dp[9] = dp[17] = dp[18] = dp[19] = 2 ;
    for ( int i = 1 ; i <= k ; i++ ) {
        if ( ! dp[i] ) {
            int minn = INT_MAX ;
            for ( int j = 1 ; j <= ( i + 1 ) / 2 ; j++ ) {
                minn = min ( minn , dp[j] + dp[i - j] ) ;
            }

            dp[i] = minn ;
        }
    }

    printf ( "%d" , dp[k] ) ;

    return 0 ;
}