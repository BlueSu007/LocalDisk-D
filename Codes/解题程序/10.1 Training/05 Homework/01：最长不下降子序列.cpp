#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 10005
int a[LEN] , dp[LEN] , n , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    dp[1] = a[1] , ans = 1 ;
    ans = 1 ;

    for ( int i = 2 ; i <= n ; i++ ) {
        if ( a[i] >= dp[ans] ) {
            dp[++ans] = a[i] ;
        }
        else {
            int tmp = upper_bound ( dp + 1 , dp + 1 + ans , a[i] ) - dp ;
            dp[tmp] = a[i] ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}