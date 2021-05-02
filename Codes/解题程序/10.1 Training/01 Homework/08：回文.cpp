#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string s , a ;

int main () {

    getline ( cin , s ) ;
    a = s ;
    reverse ( a.begin () , a.end () ) ;
    if ( a == s ) {
        printf ( "YES" ) ;
    }
    else {
        printf ( "NO" ) ;
    }

    return 0 ;
}