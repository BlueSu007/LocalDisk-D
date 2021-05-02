#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string a , b ;
int ans = -1 ;

int main () {

    getline ( cin , a ) ;
    getline ( cin , b ) ;
    
    int len1 = a.size () , len2 = b.size () ;
    for ( int i = 0 ; i <= len1 - len2 ; i++ ) {
        string tmp = a.substr ( i , len2 ) ;
        // cout << tmp << endl ;
        if ( tmp == b ) {
            ans = i + 1 ;
            break ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}