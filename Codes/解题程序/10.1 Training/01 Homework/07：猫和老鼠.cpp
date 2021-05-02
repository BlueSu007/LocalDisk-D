#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 15
char c ;
int map[LEN][LEN] , mouse[3][65] , cat[3][65] , index ;
int mx , my , cx , cy ; // mouse / cat
int jx , jy , tx , ty ; // jerry / tom
const int dx[4] = { -1 , 0 , 1 , 0 } ;
const int dy[4] = { 0 , 1 , 0 , -1 } ;

int main () {

    for ( int i = 1 ; i <= 10 ; i++ ) {
        for ( int j = 1 ; j <= 10 ; j++ ) {
            cin >> c ;
            if ( c == '*' ) {
                map[i][j] = true ;
            }
            if ( c == 'C' ) {
                cx = i , cy = j ;
            }
            if ( c == 'M' ) {
                mx = i , my = j ;
            }
        }
    }

    /*
    for ( int i = 1 ; i <= 10 ; i++ ) {
        for ( int j = 1 ; j <= 10 ; j++ ) {
            cout << map[i][j] << " " ;
        }

        cout << endl ;
    }
    */
    
    jx = mx , jy = my , tx = cx , ty = cy ;
    for ( int i = 1 ; i <= 60 ; i++ ) {
        jx += dx[index] , jy += dy[index] ;

        if ( jx == 0 || jx == 11 || jy == 0 || jy == 11 || map[jx][jy] ) {
            jx -= dx[index] , jy -= dy[index] ;
            index++ , index %= 4 ;
        }

        mouse[1][i] = jx , mouse[2][i] = jy ;
    }

    // for ( int i = 1 ; i <= 60 ; i++ ) {
    //     printf ( "( %d , %d )\n" , mouse[1][i] , mouse[2][i] ) ;
    // }
// -----------------------------------------------------------------------------------
    index = 0 ;
    for ( int i = 1 ; i <= 60 ; i++ ) {
        tx += dx[index] , ty += dy[index] ;

        if ( tx == 0 || tx == 11 || ty == 0 || ty == 11 || map[tx][ty] ) {
            tx -= dx[index] , ty -= dy[index] ;
            index++ , index %= 4 ;
        }

        cat[1][i] = tx , cat[2][i] = ty ;
    }

    // printf ( "-----------------------------------------\n" ) ;
    // for ( int i = 1 ; i <= 60 ; i++ ) {
    //     printf ( "( %d , %d )\n" , cat[1][i] , cat[2][i] ) ;
    // }

    int ans = -1 ;
    for ( int i = 1 ; i <= 59 ; i++ ) {
        if ( mouse[1][i] == cat[1][i] && mouse[2][i] == cat[2][i] ) {
            ans = i ;
            break ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}