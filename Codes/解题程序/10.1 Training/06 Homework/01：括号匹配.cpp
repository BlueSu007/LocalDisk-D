#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <stack>
using namespace std;

stack <int> t ;
string s ;
inline bool add ( char c ) ;

int main () {

    cin >> s ;
    int len = s.size () ;

    for ( int i = 0 ; i < len ; i++ ) {
        if ( s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' ) {
            continue ;
        }

        if ( ! add ( s[i] ) ) {
            printf ( "NO" ) ;
            exit ( false ) ;
        }
    }

    if ( t.empty () ) {
        printf ( "YES" ) ;
    }
    else {
        printf ( "NO" ) ;
    }

    return 0 ;
}

inline bool add ( char c ) {
    if ( c == '(' || c == '[' ) {
        t.push (c) ;
        return true ;
    }

    if ( t.empty () ) {
        return false ;
    }
    
    if ( ( c == ')' && t.top() == '(' )
     ||  ( c == ']' && t.top() == '[' ) ) {
        t.pop () ;
        return true ;
    }

    return false ;
}