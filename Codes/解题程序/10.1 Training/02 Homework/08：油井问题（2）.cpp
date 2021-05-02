#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[105] , minnAns = INT_MAX , minn = INT_MAX , maxn = INT_MIN ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        minn = min ( minn , a[i] ) ;
        maxn = max ( maxn , a[i] ) ;
    }

    for ( int i = minn ; i <= maxn ; i++ ) {
        int tmp = 0 ;
        for ( int j = 1 ; j <= n ; j++ ) {
            tmp += abs ( a[j] - i ) ;
        }

        minnAns = min ( minnAns , tmp ) ;
    }

    printf ( "%d" , minnAns ) ;

    return 0 ;
}