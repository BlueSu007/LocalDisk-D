#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int n ;
string a[100] , ans ;

inline bool cmp ( string x , string y ) {
    return x + y < y + x ;
}

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i] ;
    }

    sort ( a + 1 , a + 1 + n , cmp ) ;

    for ( int i = n ; i >= 1 ; i-- ) {
        ans += a[i] ;
    }

    cout << ans ;

    return 0 ;
}