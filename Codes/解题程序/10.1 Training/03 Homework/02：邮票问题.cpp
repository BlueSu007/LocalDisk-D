#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 25600
int n , m , a[LEN] , b[LEN] ;

int main () {

    scanf ( "%d %d" , &m , &n ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        b[a[i]] = true ;
    }

    int value = 1 ;
    while ( true ) {
        for ( int i = 1 ; i <= m ; i++ ) {
            if ( value >= a[i] ) {
                int cnt = b[a[i]] + b[value - a[i]] ;
                if ( ! b[value] ) {
                    b[value] = cnt ;
                }
                else if ( cnt < b[value] ) {
                    b[value] = cnt ;
                }
            }
        }

        if ( b[value] > n || ! b[value] ) {
            break ;
        }

        value++ ;
    }

    printf ( "%d" , value - 1 ) ;

    return 0 ;
}