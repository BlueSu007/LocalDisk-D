#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , y[20210206] , mid , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &y[i] ) ;
    }

    sort ( y + 1 , y + 1 + n ) ;

    if ( n % 2 == 1 ) {
        mid = y[n / 2 + 1] ;
    }
    else {
        mid = ( y[n / 2] + y[n / 2 + 1] ) / 2 ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        ans += abs ( y[i] - mid ) ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}