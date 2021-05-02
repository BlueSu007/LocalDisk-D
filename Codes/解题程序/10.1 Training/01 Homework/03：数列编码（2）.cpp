#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

#define LEN 105
int n , a[LEN] , b[LEN] ;
vector < int > list ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &b[i] ) ;
    }

    // cout << 1 ;

    for ( int i = 0 ; i < n * 2 ; i++ ) {
        if ( i >= n ) {
            list.push_back (0) ;
            continue ;
        }
        list.push_back (i) ;
    }

    // cout << 2 ;

    for ( int i = n ; i >= 1 ; i-- ) {
        a[i] = list[b[i]] ;
        list.erase ( list.begin () + b[i] ) ;
    /*
        for ( int i = 0 ; i < list.size () ; i++ ) {
            printf ( "%d " , list[i] ) ;
        }
        printf ( "\n" ) ;
    */
    }

    // cout << 3 ;

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , a[i] ) ;
    }

    return 0 ;
}