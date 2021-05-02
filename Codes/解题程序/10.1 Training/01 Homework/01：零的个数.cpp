// Please Judge This Code !!! DO NOT Disconnected My Computer !!!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , two , five ;

int main () {

    scanf ( "%d" , &n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        int qwq = i ;
        while ( qwq % 2 == 0 ) {
            two++ ;
            qwq /= 2 ;
        }
        while ( qwq % 5 == 0 ) {
            five++ ;
            qwq /= 5 ;
        }
    }

    printf ( "%d" , min ( two , five ) ) ;

    return 0 ;
}