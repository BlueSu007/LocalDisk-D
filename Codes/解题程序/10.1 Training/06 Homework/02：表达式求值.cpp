#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <stack>
using namespace std;

string s ;
stack < char > operatorX ;
stack < double > value ;
inline bool isBigger ( char op1 , char op2 ) ;
inline void work () ;
inline double calculate ( double x , double y , char op ) ;

int main () {

    cin >> s ;
    int len = s.size () ;
    s = " " + s ;

    double num = 0 ;
    operatorX.push ( '!' ) ;
    for ( int i = 1 ; i <= len ; i++ ) {
        if ( isdigit ( s[i] ) ) {
            value.push ( s[i] - '0' ) ;
        }
        else {
            if ( s[i] == ')' ) {
                while ( ! operatorX.empty () && operatorX.top () != '(' ) {
                    work () ;
                }
                if ( operatorX.top () == '(' ) {
                    operatorX.pop () ;
                }
                continue ;
            }

            if ( isBigger ( operatorX.top () , s[i] ) ) {
                work () ;
            }
            operatorX.push ( s[i] ) ;
            
            if ( operatorX.size () && operatorX.top () == '(' && s[i] == ')' ) {
                operatorX.pop () ;
            }
        }
    }

    while ( operatorX.size () > 1 ) {
        work () ;
    }

    printf ( "%.2lf" , value.top () ) ;

    return 0 ;
}

inline bool isBigger ( char op1 , char op2 ) {
    if ( op1 == '(' || op1 == '!' ) {
        return false ;
    }
    else if ( op2 == '(' ) {
        return false ;
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

inline void work () {
    char op = operatorX.top () ; 
    operatorX.pop () ;
    double x = value.top () ;    
    value.pop () ;
    double y = value.top () ;    
    value.pop () ;

    if ( operatorX.top () == '-' && op == '-' ) {
        value.push ( y + x ) ;
        return ;
    }
    else if ( operatorX.top () == '/' && op == '/' ) {
        value.push ( y * x ) ;
        return ;
    }
    else if ( operatorX.top () == '-' && op == '+' ) {
        value.push ( y - x ) ;
        return ;
    }
    else if ( operatorX.top () == '/' && op == '*' ) {
        value.push ( y / x ) ;
        return ;
    }
    
    value.push ( calculate ( y , x , op ) ) ;
}

inline double calculate ( double x , double y , char op ) {
    if ( op == '+' ) {
        return x + y ;
    }
    else if ( op == '-' ) {
        return x - y ;
    }
    else if ( op == '*' ) {
        return x * y ;
    }
    else {
        return x / y ;
    }
}