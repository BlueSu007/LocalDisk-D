#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 3005
int n , m , k , vis[LEN] , ans = INT_MAX ;
inline void dfs ( int positive , int step ) ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    dfs ( m , 0 ) ;

    if ( ans == INT_MAX ) {
        printf ( "No solution!" ) ;
    }
    else {
        printf ( "%d" , ans ) ;
    }

    return 0 ;
}

inline void dfs ( int positive , int step ) {
    if ( ! positive ) {
        ans = min ( ans , step ) ;
        return ;
    }

    int negetive = n - positive ;
    for ( int i = 0 ; i <= k ; i++ ) {
        int nextPositive = positive + k - 2 * i ;
        int nextNegetive = negetive - k + 2 * i ;
        
        if ( positive - i < 0 || negetive - k + i < 0
            || nextPositive < 0 || nextNegetive < 0 || nextPositive > n || nextNegetive > n || vis[nextPositive] ) {
            continue ;
        }

        vis[nextPositive] = true ;
        dfs ( nextPositive , step + 1 ) ;
    }
}