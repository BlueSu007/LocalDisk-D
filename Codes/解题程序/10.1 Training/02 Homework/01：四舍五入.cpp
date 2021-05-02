#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string s , a , b ;
int len , len1 , len2 ;
inline void getParts () ;
inline void rouding () ;

int main () {

    cin >> s ;
    len = s.size () ;
    getParts () ;

    len1 = a.size () , len2 = b.size () ;
    if ( len2 <= 10 ) {
        while ( b.size () < 10 ) {
            b += '0' ;
        }
    }
    else if ( len2 > 10 ) {
        if ( b[10] >= '5' ) {
            rounding () ;
        }

        b = b.substr ( 0 , 10 ) ;
    }

    cout << a << '.' << b << endl ;

    return 0 ;
}

inline void getParts () {
    int i = 0 ;
    while ( i < len && s[i] != '.' ) {
        a += s[i++] ;
    }

    i++ ;
    while ( i < len ) {
        b += s[i++] ;
    }
}

inline void rounding () {
    int i = 9 ;
    b[9]++ ;
    while ( b[i] > '9' && i > 0 ) {
        b[i] = '0' , b[i - 1]++ , i-- ;
    }

    if ( b[0] > '9' ) {
        i = len1 - 1 , a[len1 - 1]++ ;
        while ( a[i] > '9' && i > 0 ) {
            a[i] = '0' , a[i - 1]++ , i-- ;
        }
    }

    if ( a[0] > '9' ) {
        a[0] = b[0] = '0' ;
        cout << '1' ;
    }
}