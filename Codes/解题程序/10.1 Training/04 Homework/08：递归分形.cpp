#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
int n , len = 1 ;
char a[LEN][LEN] ;
inline void snowFlake ( int len , int x , int y ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 2 ; i <= n ; i++ ) {
        len *= 3 ;
    }

    for ( int i = 1 ; i <= len ; i++ ) {
        for ( int j = 1 ; j <= len ; j++ ) {
            a[i][j] = ' ' ;
        }
        a[i][len + 1] = '\0' ;
    }

    snowFlake ( len , 1 , 1 ) ;

    for ( int i = 1 ; i <= len ; i++ ) {
        for ( int j = 1 ; j <= len ; j++ ) {
            printf ( "%c" , a[i][j] ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}

inline void snowFlake ( int len , int x , int y ) {
    if ( len == 1 ) {
        a[x][y] = 'X' ;
    }
    else {
        len /= 3 ;
        snowFlake ( len , x , y ) ; // now
        snowFlake ( len , x + len * 2 , y ) ; // second floor
        snowFlake ( len , x , y + len * 2 ) ; // near room
        snowFlake ( len , x + len , y + len ) ; // middle
        snowFlake ( len , x + len * 2 , y + len * 2 ) ; // second floor near room
    }
    
    return ;
}