#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define MOD 12345
int n , a[1000 + 5] , x , base ;

int main () {

    scanf ( "%d" , &n ) ;

    a[1] = x = 9 , base = 10 ;
    for ( int i = 2 ; i <= n ; i++ ) {
        a[i] = ( 8 * x + ( base - x ) ) % MOD ;
        x += a[i] ;
        base *= 10 , base %= MOD ;
    }

    printf ( "%d" , a[n] ) ;

    return 0 ;
}