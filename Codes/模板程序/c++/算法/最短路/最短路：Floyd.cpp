#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000 + 5][1000 + 5] , n , m ;
int x , y , z ;
const int INF = 0x7fffff ;

int main() {
	
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			a[i][j] = ( i == j ) ? 0 : INF ;
		}
	}
	
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d %d" , &x , &y , &z ) ;
		a[x][y] = z ;
	}
	
	for ( int k = 1 ; k <= n ; k++ ) {
		for ( int i = 1 ; i <= n ; i++ ) {
			for ( int j = 1 ; j <= n ; j++ ) {
				a[i][j] = a[i][j] > ( a[i][k] + a[k][j] ) ? ( a[i][k] + a[k][j] ) : a[i][j] ;
			}
		} 
	} 
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			printf ( "%10d" , a[i][j] ) ;
		}
		
		printf( "\n" ) ;
	}
	
	return 0;
}
/*
//aha!algorithm P152~P154
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12

         0         2         5         4
         9         0         3         4
         6         8         0         1
         5         7        10         0
*/
