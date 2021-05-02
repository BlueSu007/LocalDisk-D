#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 55
int n , m , vis[LEN][LEN] , que[LEN * LEN][4] , head , tail , ans ;
const int dx[4] = { -2 , -1 , 1 , 2 } ;
const int dy[4] = { 1 , 2 , 2 , 1 } ;
inline int bfs ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    int qwq = bfs ( 1 , 1 ) ;

    if ( ( n % 2 && m % 2 && m != n ) || qwq == -1 || qwq == 0 ) {
        printf ( "No solution!" ) ;
    }
    else {
        printf ( "%d" , qwq ) ;
    }

    // for ( int i = 1 ; i <= tail ; i++ ) {
        // cout << "( " << que[i][1] << " , " << que[i][2] << " )\n" ;
    // }

    return 0 ;
}

inline int bfs ( int x , int y ) {
    que[++head][1] = x , que[head][2] = y , tail++ , vis[x][y] = true ;
    while ( head <= tail ) {
        for ( int i = 0 ; i < 4 ; i++ ) {
            int fx = dx[i] + que[head][1] ;
            int fy = dy[i] + que[head][2] ;
            if ( fx >= 1 && fy >= 1 && fx <= n && fy <= m && ! vis[fx][fy] ) {
                que[++tail][1] = fx , que[tail][2] = fy , que[tail][3] = que[head][3] + 1 ;
                vis[fx][fy] = true ;

                if ( fx == n && fy == m ) {
                    return que[tail][3] ;
                }
            }
        }

        head++ ;
    }

    return -1 ;
}