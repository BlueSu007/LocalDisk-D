#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100005
int a[LEN] , b[LEN] , n ;
long long ans ;
inline void divide ( int left , int right ) ;
inline void merge ( int left , int mid , int right ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    divide ( 1 , n ) ;
    printf ( "%lld" , ans ) ;

    return 0 ;
}

inline void divide ( int left , int right ) {
    if ( left < right ) {
        int mid = ( left + right ) / 2 ;
        divide ( left , mid ) ;
        divide ( mid + 1 , right ) ;
        merge ( left , mid , right ) ;
    }

    return ;
}

inline void merge ( int left , int mid , int right ) {
    int i = left , j = mid + 1 , k = left ;
    while ( i <= mid && j <= right ) {
        if ( a[i] <= a[j] ) {
            b[k] = a[i] , k++ , i++ ;
        }
        else {
            b[k] = a[j] , k++ , j++ ;
            ans += mid - i + 1 ;
        }
    }

    while ( i <= mid ) {
        b[k] = a[i] , k++ , i++ ;
    }
    while ( j <= right ) {
        b[k] = a[j] , k++ , j++ ;
    }

    for ( int i = left ; i <= right ; i++ ) {
        a[i] = b[i] ;
    }

    return ;
}