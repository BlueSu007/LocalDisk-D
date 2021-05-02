#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
int n , m , weight[LEN] , price[LEN] , dp[LEN] ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &weight[i] , &price[i] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = m ; j >= weight[i] ; j-- ) {
            dp[j] = max ( dp[j] , dp[j - weight[i]] + price[i] ) ;
        }
    }

    printf ( "%d" , dp[m] ) ;

    return 0 ;
}