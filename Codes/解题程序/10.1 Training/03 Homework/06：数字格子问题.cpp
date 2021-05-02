#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define LEN 20210226
#define AIM 24

struct node {
    int array[10] ;
    int step , hashValue ;
} startn ;

int vis[LEN] ;
const int factor[10] = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 } ;
queue < node > que ;

int cantor ( int a[] ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= 8 ; i++ ) {
        int cnt = 0 ;
        for ( int j = i + 1 ; j <= 8 ; j++ ) {
            if ( a[i] > a[j] ) {
                cnt++ ;
            }
        }

        ans += cnt * factor[8 - i] ;
    }

    return ans + 1 ;
}

int bfs () {
    que.push ( startn ) ;
    while ( ! que.empty () ) {
        node x = que.front () ;
        que.pop () ;

        if ( vis[x.hashValue] ) {
            continue ;
        }

        if ( x.hashValue == AIM ) {
            return x.step ;
        }

        vis[x.hashValue] = 1 , x.step++ ;

        // Operation 1. Change line 1 & line 2
        node nextn = x ;
        for ( int i = 1 ; i <= 4 ; i++ ) {
            swap ( nextn.array[i] , nextn.array[i + 4] ) ;
        }
        nextn.hashValue = cantor ( nextn.array ) ;
        que.push ( nextn ) ;

        //Operation 2. Push right one pixles
        nextn = x ;
        int up = nextn.array[4] , down = nextn.array[8] ;
        for ( int i = 4 ; i >= 2 ; i-- ) {
            nextn.array[i] = nextn.array[i - 1] ;
            nextn.array[i + 4] = nextn.array[i + 3] ;
        }

        nextn.array[1] = up , nextn.array[5] = down ;
        nextn.hashValue = cantor ( nextn.array ) ;
        que.push ( nextn ) ;

        // Operation 3. Turn the four pixles in middle by the clock condition
        nextn = x ;
        int twoPos = nextn.array[2] , threePos = nextn.array[3] ;
        int sixPos = nextn.array[6] , sevenPos = nextn.array[7] ;
        nextn.array[2] = sixPos , nextn.array[3] = twoPos ;
		 	nextn.array[7] = threePos , nextn.array[6] = sevenPos ;
        nextn.hashValue = cantor ( nextn.array ) ;
        que.push ( nextn ) ;
    }
}

int main () {

    for ( int i = 1 ; i <= 8 ; i++ ) {
        scanf ( "%d" , &startn.array[i] ) ;
    }

    startn.hashValue = cantor ( startn.array ) ;
    printf ( "%d\n" , bfs () ) ;

    return 0 ;
}