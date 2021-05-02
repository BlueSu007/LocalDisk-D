#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string a , b ;
string integerA , integerB , decimalA , decimalB ;
int ansLen , integerLenAns , decimalLenAns ;
int integerLenA , integerLenB , decimalLenA , decimalLenB ;
int a1[100] , b1[100] , ans[100] , len1 , len2 ;
inline void init () ;
inline void fillZero () ;
inline void changeToInt () ;

int main () {

    cin >> a >> b ;
    init () , fillZero () , changeToInt () ;

    for ( int i = 0 ; i < ansLen ; i++ ) {
        ans[i] += a1[i] + b1[i] ;
        ans[i + 1] += ans[i] / 10 ;
        ans[i] %= 10 ;
    }

    // for ( int i = 0 ; i <= ansLen ; i++ ) {
    //     cout << a1[i] << " " ;
    // }
    // cout << endl ;
    // for ( int j = 0 ; j <= ansLen ; j++ ) {
    //     cout << b1[j] << " " ;
    // }
    // cout << endl ;

    if ( ans[ansLen] ) {
        ansLen++ , integerLenAns++ ;
    }

    reverse ( ans , ans + 99 ) ;
    int pos = 99 ;
    while ( ! ans[pos--] && pos ) ;

    int flag = false , cnt = 0 ;
    for ( int i = 0 ; i <= pos + 1 ; i++ ) {
        if ( ! flag && ! ans[i] ) {
            continue ;
        }

        flag = true , cnt++ ;
        printf ( "%d" , ans[i] ) ;

        if ( cnt == integerLenAns && i != pos + 1 ) {
            printf ( "." ) ;
        }
    }

    // cout << "\nintegerA: " << integerA << "\nintegerB: " << integerB << "\ndecimalA: " << decimalA << "\ndecimalB: " << decimalB ;
    // cout << "\nansLen: " << ansLen << "\nintegerLenAns: " << integerLenAns << "\ndecimalLenAns: " << decimalLenAns ;
    // cout << "\nintegerLenA: " << integerLenA << "\nintegerLenB: " << integerLenB << "\ndecimalLenA: " << decimalLenA << "\ndecimalLenB: " << decimalLenB ;

    return 0 ;
}

inline void init () {
    int flagA = false , flagB = false ;
    integerLenA = a.find ('.') , integerLenB = b.find ('.') ;
    if ( integerLenA == -1 && integerLenB == -1 ) {
        integerA = a.substr ( 0 , integerLenA ) ;
        integerB = b.substr ( 0 , integerLenB ) ; 
        return ;
    }
    if ( integerLenA == -1 ) {
        flagA = true , integerLenA = a.size () - 1 ;
    }
    if ( integerLenB == -1 ) {
        flagB = true , integerLenB = b.size () - 1 ;
    }

    decimalLenA = a.size () - integerLenA - 1 , decimalLenB = b.size () - integerLenB - 1 ;

    if ( flagA ) {
        integerLenA++ ;
    }
    if ( flagB ) {
        integerLenB++ ;
    }
    
    if ( decimalLenA > 0 ) {
        decimalA = a.substr ( integerLenA + 1 ) ;
    }
    if ( decimalLenB > 0 ) {
        decimalB = b.substr ( integerLenB + 1 ) ;
    }

    integerA = a.substr ( 0 , integerLenA ) ;
    integerB = b.substr ( 0 , integerLenB ) ;
    integerLenAns = max ( integerLenA , integerLenB ) ;
    decimalLenAns = max ( decimalLenA , decimalLenB ) ;

    if ( ! flagA ) {
        a.erase ( integerLenA , 1 ) ;
    }
    if ( ! flagB ) {
        b.erase ( integerLenB , 1 ) ;
    }

    // cout << a << endl << b << endl ;
}

inline void fillZero () {
    while ( integerA.size () < integerLenAns ) {
        integerA = "0" + integerA ;
    }
    while ( decimalA.size () < decimalLenAns ) {
        decimalA = decimalA + "0" ;
    }

    while ( integerB.size () < integerLenAns ) {
        integerB = "0" + integerB ;
    }
    while ( decimalB.size () < decimalLenAns ) {
        decimalB = decimalB + "0" ;
    }

    a = integerA + decimalA ;
    b = integerB + decimalB ;
    // cout << a << endl << b << endl ;
}

inline void changeToInt () {
    ansLen = a.size () ;
    for ( int i = 0 ; i < ansLen ; i++ ) {
        a1[ansLen - i - 1] = a[i] - '0' ;
        b1[ansLen - i - 1] = b[i] - '0' ;
    }
}