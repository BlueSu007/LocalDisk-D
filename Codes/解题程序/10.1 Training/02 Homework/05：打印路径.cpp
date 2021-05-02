#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 15
int n , map[LEN][LEN] , route[LEN] , vis[LEN] ;
inline void dfs ( int cur , int step ) ;
inline void print ( int len ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= 2 && j + i <= n ; j++ ) {
            map[i][i + j] = true ;
        }
    }

    dfs ( 0 , 1 ) ;

    return 0 ;
}

inline void dfs ( int cur , int step ) {
    if ( cur == n ) {
        print ( step ) ;
        return ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( map[cur][i] && ! vis[i] ) {
            vis[i] = true , route[step + 1] = i ;
            dfs ( i , step + 1 ) ;
            vis[i] = false ;
        }
    }
}

inline void print ( int len ) {
    for ( int i = 1 ; i < len ; i++ ) {
        printf ( "%d-" , route[i] ) ;
    }
    printf ( "%d\n" , n ) ;
}