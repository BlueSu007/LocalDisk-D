// https://www.luogu.com.cn/blog/li-dongxiao-dx-duxiu/li-dongxiao-dx-duxiu
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

double d1 , d2 , c , P , d[15] , p[15] ;
double goalDis , maxDis , minPrice = 23333 , oil , ans ;
int pos , n ;

int main () {

    scanf ( "%lf %lf %lf %lf %d" , &d1 , &c , &d2 , &P , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lf %lf" , &d[i] , &p[i] ) ;
    }

    maxDis = c * d2 ;
    // 特判无解：相邻加油站的距离超过x
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( d[i] - d[i - 1] > maxDis ) {
            printf ( "No Solution" ) ;
            exit ( false ) ;
        }
    }

    // 如果没走到终点（当总路程大于已走的路程时）
    while ( d1 - goalDis ) {
        // 找到最便宜的加油站，当在范围内的时候 (maxDis表示加满油最多能走的路程)
        for ( int i = pos + 1 ; d[i] - goalDis <= maxDis && i <= n ; i++ ) {
            if ( p[i] < minPrice ) {
                minPrice = p[i] , pos = i ;
            }
        }

        // 如果范围内的加油站比自己便宜，那么就刚好走到这个加油站
        if ( minPrice <= P ) {
            ans += ( ( d[pos] - goalDis ) / d2 - oil ) * P ;
            oil = ( d[pos] - goalDis ) / d2 ;
        }
        // 反之，如果比自己贵，并且无法一次性到达终点，那么就加满再走
        else if ( d1 - goalDis > maxDis ) {
            ans += ( c - oil ) * P ;
            oil = c ;
        }
        // 如果比自己贵但是能一次性到达终点，直接去终点即可
        else {
            ans += ( ( d1 - goalDis ) / d2 - oil ) * P ;
            break ;
        }

        oil = oil - ( d[pos] - goalDis ) / d2 ; // 走多少路，用多少油
        goalDis = d[pos] ; // 更新当前位置
        P = minPrice , minPrice = 23333 ; // 更新当前加油站的价钱，还原最小值
    }

    printf ( "%.2lf" , ans ) ;

    return 0 ;
}