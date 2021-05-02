#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

string s ;
stack < char > t ;
inline bool isBigger ( char op1 , char op2 ) ;

int main () {

    cin >> s ;
    int len = s.size () ;

    for ( int i = 0 ; i < len ; i++ ) {
        if ( isdigit ( s[i] ) ) {
            printf ( "%c" , s[i] ) ;
        }
        else {
            if ( t.empty () ) {
                t.push ( s[i] ) ;
            }
            else {
                if ( s[i] == '(' ) {
                    t.push ( s[i] ) ;
                }
                else if ( s[i] == ')' ) {
                    while ( ! t.empty () && t.top () != '(' ) {
                        // cout << "BreakPoint1" << " t.top (): " << t.top () << " pos: " << i << endl ;
                        printf ( "%c" , t.top () ) ;
                        t.pop () ;
                    }
                    if ( ! t.empty () && t.top () == '(' ) {
                        t.pop () ;
                    }
                }
                else {
                    while ( ! t.empty () && isBigger ( t.top () , s[i] ) ) {
                        // cout << "BreakPoint2" << " t.top (): " << t.top () << " pos: " << i << endl ;
                        printf ( "%c" , t.top () ) ;
                        t.pop () ;
                    }
                    t.push ( s[i] ) ;
                }
            }
        }
    }

    while ( ! t.empty () ) {
        printf ( "%c" , t.top () ) ;
        t.pop () ;
    }

    return 0 ;
}

inline bool isBigger ( char op1 , char op2 ) {
    if ( op1 == '(' ) {
        return false ;
    }

    if ( op1 == '+' || op1 == '-' ) {
        if ( op2 == '*' || op2 == '/' ) {
            return false ;
        }
    }
    else {
        return true ;
    }
}

/*
7-(2+3*2)
1+(2+3*4)+5
1+2*3+(4*5+6)*7
(1+2)+(3+4)
1*2-3/5+6+7*1
(1+(2*3))+5
((1+2)*3)-(8/4)
1*2+3+4
*/