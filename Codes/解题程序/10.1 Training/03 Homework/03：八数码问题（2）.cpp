#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 4000005
struct node {
    int array[10] ;
    int zeroPos , hashValue , step ;
} now , finaln ;

int vis[LEN] , x , step = INT_MAX ;
const int factor[10] = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 } ;
const int dx[4] = { -1 , 0 , 1 , 0 } ;
const int dy[4] = { 0 , -1 , 0 , 1 } ;
inline int cantor ( int a[] ) ;
inline void dfs ( node x ) ;

int main () {

    for ( int i = 0 ; i < 9 ; i++ ) {
        scanf ( "%d" , &x ) ;
        if ( ! x ) {
            now.zeroPos = i ;
        }
        now.array[i] = x ;
    }

    for ( int i = 0 ; i < 9 ; i++ ) {
        scanf ( "%d" , &x ) ;
        if ( ! x ) {
            finaln.zeroPos = i ;
        }
        finaln.array[i] = x ;
    }

    now.hashValue = cantor ( now.array ) ;
    finaln.hashValue = cantor ( finaln.array ) ;
    vis[now.hashValue] = true ;

    dfs ( now ) ;
    printf ( "%d" , step ) ;

    return 0 ;
}

inline int cantor ( int a[] ) {
    int ans = 0 ;
    for ( int i = 0 ; i < 9 ; i++ ) {
        int cnt = 0 ;
        for ( int j = i + 1 ; j < 9 ; j++ ) {
            if ( a[i] > a[j] ) {
                cnt++ ;
            }
        }

        ans += cnt * factor[8 - i] ;
    }

    return ans + 1 ;
}

inline void dfs ( node x ) {
    if ( x.step > 50 ) {
        return ;
    }
    if ( x.hashValue == finaln.hashValue ) {
        step = min ( step , x.step ) ;
        return ;
    }

    int zeroX = x.zeroPos / 3 ;
    int zeroY = x.zeroPos % 3 ;
    for ( int i = 0 ; i < 4 ; i++ ) {
        int nextX = zeroX + dx[i] ;
        int nextY = zeroY + dy[i] ;
        if ( nextX < 0 || nextY < 0 || nextX > 2 || nextY > 2 ) {
            continue ;
        }

        node nextn = x ;
        nextn.zeroPos = 3 * nextX + nextY ;
        nextn.array[x.zeroPos] = nextn.array[nextn.zeroPos] ;
        nextn.array[nextn.zeroPos] = 0 ;
        nextn.hashValue = cantor ( nextn.array ) ;

        if ( vis[nextn.hashValue] ) {
            continue ;
        }

        vis[nextn.hashValue] = true , nextn.step++ ;
        dfs ( nextn ) ;
        vis[nextn.hashValue] = false ;
    }

    return ;
}