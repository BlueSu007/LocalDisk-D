#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <stack>
using namespace std;

string s ;
stack < char > t ;
inline bool isBigger ( char op1 , char op2 ) ;
inline void print () ;

int main () {

    cin >> s ;
    int len = s.size () ;

    for ( int i = 0 ; i < len ; i++ ) {
        if ( isdigit ( s[i] ) ) {
            printf ( "%c" , s[i] ) ;
        }
        else {
            if ( ( t.empty () || ! isBigger ( t.top () , s[i] ) || s[i] == '(' ) && s[i] != ')' ) {
                t.push ( s[i] ) ;
            }
            else if ( s[i] == ')' ) {
                while ( ! t.empty () && t.top () != '(' ) {
                    print () ;
                }
            }
            else if ( isBigger ( t.top () , s[i] ) ) {
                while ( ! t.empty () && isBigger ( t.top () , s[i] ) && t.top () != '(' ) {
                    print () ;
                }
                t.push ( s[i] ) ;
            }
        }
    }

    while ( ! t.empty () ) {
        print () ;
    }

    return 0 ;
}

inline bool isBigger ( char op1 , char op2 ) {
    if ( op1 == ' ' ) {
        return true ;
    }

    if ( op1 == '+' || op1 == '-' ) {
        if ( op2 == '*' || op2 == '/' ) {
            return false ;
        }
        else {
            return true ;
        }
    }
    else {
        return true ;
    }
}

inline void print () {
    if ( t.top () == '(' ) {
        t.pop () ;
        return ;
    }
    printf ( "%c" , t.top () ) ;
    t.pop () ;
}


/*
7-(2+3*2)
1+(2+3*4)+5
1+2*3+(4*5+6)*7
(1+2)+(3+4)
1*2-3/5+6+7*1
(1+(2*3))+5 ERRCODE
((1+2)*3)-(8/4)
*/