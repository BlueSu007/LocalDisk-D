#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 20
int n , a[LEN][LEN] , b[LEN][LEN] , c[LEN][LEN] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            scanf ( "%d" , &b[i][j] ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            int sum = 0 ;
            for ( int k = 1 ; k <= n ; k++ ) {
                c[i][j] += a[i][k] * b[k][j] ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            printf ( "%d " , c[i][j] ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}