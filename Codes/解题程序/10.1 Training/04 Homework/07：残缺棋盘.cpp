#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define upLeft dfs ( breakX + len - 1 , breakY + len - 1 , breakX , breakY , len )
#define upRight dfs ( breakX + len - 1 , breakY + len , breakX , breakY + len , len )
#define downLeft dfs ( breakX + len , breakY + len - 1 , breakX + len , breakY , len ) 
#define downRight dfs ( breakX + len , breakY + len , breakX + len , breakY + len , len )
#define X breakX + len
#define Y breakY + len

int k , x , y , a[2000][2000] , cnt ;
inline void dfs ( int fillX , int fillY , int breakX , int breakY , int len ) ;

int main () {

    scanf ( "%d %d %d" , &k , &x , &y ) ;
    int qaq = 1 << k ;
    if ( x > qaq || y > qaq ) {
        printf ( "wrong" ) ;
        exit ( false ) ;
    }

    dfs ( x , y , 1 , 1 , qaq ) ;
    a[x][y] = 7 ;
    for ( int i = 1 ; i <= qaq ; i++ ) {
        for ( int j = 1 ; j <= qaq ; j++ ) {
            printf ( "%d " , a[i][j] ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}

inline void dfs ( int fillX , int fillY , int breakX , int breakY , int len ) {
    if ( len == 1 ) {
        return ;
    }
    len >>= 1 ;

    if ( fillX - breakX < len && fillY - breakY < len ) {
        // printf ( "%d %d 1\n" , breakX + len , breakY + len ) ;
        a[X][Y] = a[X - 1][Y] = a[X][Y - 1] = 1 ;
        dfs ( fillX , fillY , breakX , breakY , len ) ;
        upRight , downLeft , downRight ;
    }

    if ( fillX - breakX < len && fillY - breakY >= len ) {
        // printf ( "%d %d 2\n" , breakX + len , breakY + len - 1 ) ;
        a[X][Y - 1] = a[X][Y] = a[X - 1][Y - 1] = 2 ;
        upLeft , dfs ( fillX , fillY , breakX , breakY + len , len ) ;
        downLeft , downRight ;
    }

    if ( fillX - breakX >= len && fillY - breakY < len ) {
        // printf ( "%d %d 3\n" , breakX + len - 1 , breakY + len ) ;
        a[X - 1][Y] = a[X - 1][Y - 1] = a[X][Y] = 3 ;
        upLeft , upRight ;
        dfs ( fillX , fillY , breakX + len , breakY , len ) , downRight ;
    }

    if ( fillX - breakX >= len && fillY - breakY >= len ) {
        // printf ( "%d %d 4\n" , breakX + len - 1 , breakY + len - 1 ) ;
        a[X - 1][Y - 1] = a[X - 1][Y] = a[X][Y - 1] = 4 ;
        upLeft , upRight , downLeft ;
        dfs ( fillX , fillY , breakX + len , breakY + len , len ) ;
    }
}