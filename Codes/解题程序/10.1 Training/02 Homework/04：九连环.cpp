#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[100] ;
inline void putOn ( int x , int cnt ) ;
inline void pushDown ( int x , int cnt ) ;
inline void print () ;
inline void tabs ( int cnt ) ;

int main () {

    // freopen ( "qwq.txt" , "w" , stdout ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = true ;
    }
    print () ;
    pushDown ( n , 0 ) ;

    return 0 ;
}

inline void putOn ( int x , int cnt ) {
    cout << "on-" << x << endl ;
    if ( x > 1 ) {
        tabs ( cnt ) ;
        cout << '(' << endl ;
        tabs ( cnt + 1 ) ;
        putOn ( x - 1 , cnt + 1 ) ;
        tabs ( cnt ) ;
        cout << ')' << endl ;
    }
    if ( x > 2 ) {
        tabs ( cnt ) ;
        cout << '[' << endl ;
        tabs ( cnt + 1 ) ;
        pushDown ( x - 2 , cnt + 1 ) ;
        tabs ( cnt ) ;
        cout << ']' << endl ;
    }

    a[x] = true ;
    tabs ( cnt ) ;
    print () ;

    if ( x > 2 ) {
        tabs ( cnt ) ;
        cout << '(' << endl ;
        tabs ( cnt + 1 ) ;
        putOn ( x - 2 , cnt + 1 ) ;
        tabs ( cnt ) ;
        cout << ')' << endl ;
    }
}

inline void pushDown ( int x , int cnt ) {
    cout << "down-" << x << endl ;
    if ( x > 2 ) {
        tabs ( cnt ) ;
        cout << '[' << endl ;
        tabs ( cnt + 1 ) ;
        pushDown ( x - 2 , cnt + 1 ) ;
        tabs ( cnt ) ;
        cout << ']' << endl ;
    }

    a[x] = false ;
    tabs ( cnt ) ;
    print () ;

    if ( x > 2 ) {
        tabs ( cnt ) ;
        cout << '(' << endl ;
        tabs ( cnt + 1 ) ;
        putOn ( x - 2 , cnt + 1 ) ;
        tabs ( cnt ) ;
        cout << ')' << endl ;
    }
    if ( x > 1 ) {
        tabs ( cnt ) ;
        cout << '[' << endl ;
        tabs ( cnt + 1 ) ;
        pushDown ( x - 1 , cnt + 1 ) ;
        tabs ( cnt ) ;
        cout << ']' << endl ;
    }
}

inline void print () {
    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d" , a[i] ) ;
    }
    printf ( "\n" ) ;
}

inline void tabs ( int cnt ) {
    for ( int i = 1 ; i <= cnt ; i++ ) {
        cout << "  " ;
    }
}