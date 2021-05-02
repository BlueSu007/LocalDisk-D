#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[105] , ans = INT_MAX , pos , leftn = INT_MAX , rightn = INT_MIN ;
inline int check ( int pos ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        leftn = min ( leftn , a[i] ) ;
        rightn = max ( rightn , a[i] ) ;
    }

    cout << "LEFT: " << leftn << "\t RIGHT: " << rightn << endl ;

    while ( leftn < rightn ) {
        int mid = ( leftn + rightn ) >> 1 ;
        if ( check ( mid ) != INT_MIN ) {
            rightn = mid , ans = check ( mid ) ;
        }
        else {
            leftn = mid + 1 ;
        }

        cout << "leftn: " << leftn << "\t rightn: " << rightn << "\t ans: " << ans << endl ;
    }

    ans = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        ans += abs ( a[i] - leftn ) ;
    }
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline int check ( int pos ) {
    int tmp = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        tmp += abs ( a[i] - pos ) ;
    }

    if ( tmp >= ans ) {
        return INT_MIN ;
    }
    else {
        return tmp ;
    }
}