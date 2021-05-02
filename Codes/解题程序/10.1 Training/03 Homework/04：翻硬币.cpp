#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define LEN 3005
int n , m , k , vis[LEN] , que[LEN][2] , head , tail ;
inline int bfs () ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    int ans = bfs () ;
    if ( ans == -1 ) {
        printf ( "No solution!" ) ;
    }
    else {
        printf ( "%d" , ans ) ;
    }

    return 0 ;
}

inline int bfs () {
    head = tail = vis[m] = 1 , tail++ ;
    que[head][0] = m , que[head][1] = 0 ;

    while ( head < tail ) {
        int nowPositive = que[head][0] ;
        int nowNegetive = n - nowPositive ;
        int nowStep = que[head][1] ;
        head++ ;

        for ( int i = 0 ; i <= k ; i++ ) {
            int nextPositive = nowPositive + k - 2 * i ;
            int nextNegetive = nowNegetive - k + 2 * i ;
            if ( nowPositive - i < 0 || nowNegetive - k + i < 0
                 || nextPositive < 0 || nextNegetive < 0 || nextPositive > n || nextNegetive > n || vis[nextPositive] ) {
                continue ;
            }

            que[tail][0] = nextPositive , que[tail++][1] = nowStep + 1 , vis[nextPositive] = true ;

            if ( ! nextPositive ) {
                return que[tail - 1][1] ;
            }
        }
    }

    return -1 ;
}