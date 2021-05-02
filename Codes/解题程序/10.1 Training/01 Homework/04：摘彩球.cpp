#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , ball[100 + 5] , student[20 + 5] , ans ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &ball[i] ) ;
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &student[i] ) ;
        student[i + m] = student[i] ;
    }

    sort ( ball + 1 , ball + 1 + n ) ;
    sort ( student + 1 , student + 1 + ( m * 2 ) ) ;

    int cnt = 1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( student[cnt] >= ball[i] ) {
            // printf ( "%d " , student[cnt] ) ;
            ans++ , cnt++ ;
        }
        if ( cnt == ( m * 2 ) + 1 ) {
            break ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}