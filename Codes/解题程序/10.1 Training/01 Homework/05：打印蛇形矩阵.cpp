#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 15
int map[LEN][LEN] , n , x = 1 , y , qaq = 1 ;

int main () {

    scanf ( "%d" , &n ) ;

    while ( qaq <= n * n ) {
        while ( y < n && ! map[x][y + 1] ) {
            map[x][++y] = qaq++ ;
        }

        while ( x < n && ! map[x + 1][y] ) {
            map[++x][y] = qaq++ ;
        }

        while ( y > 1 && ! map[x][y - 1] ) {
            map[x][--y] = qaq++ ;
        }

        while ( x > 1 && ! map[x - 1][y] ) {
            map[--x][y] = qaq++ ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            printf ( "%d " , map[i][j] ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}