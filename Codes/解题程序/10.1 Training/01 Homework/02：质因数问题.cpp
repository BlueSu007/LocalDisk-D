#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n , box[1000000] ;
inline bool isprime ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    int qwq = n ;

	for ( int i = 2 ; i <= n ; i++ ) {
		while ( n % i == 0 ) {
			n /= i , box[i]++ ;
		}
	}

    for ( int i = 2 ; i <= qwq / 2 ; i++ ) {
        if ( isprime (i) && box[i] ) {
            printf ( "%d " , i ) ;
        }
    }

    return 0 ;
}

inline bool isprime ( int x ) {
    for ( int i = 2 ; i * i <= x ; i++ ) {
        if ( x % i == 0 ) {
            return false ;
        }
    }

    return true ;
}