#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 15
int a[LEN][LEN] , vis[LEN][LEN] , ans ;
const int dx[4] = { 1 , -1 , 0 , 0 } ;
const int dy[4] = { 0 , 0 , 1 , -1 } ;
inline void dfs ( int x , int y ) ;

int main() {
	
	for ( int i = 1 ; i <= 10 ; i++ ) {
		for ( int j = 1 ; j <= 10 ; j++ ) {
			scanf ( "%d" , &a[i][j] ) ;
			vis[i][j] = a[i][j] ;
		}
	}
	
	dfs ( 0 , 0 ) ;

	for ( int i = 1 ; i <= 10 ; i++ ) {
		for ( int j = 1 ; j <= 10 ; j++ ) {
			if ( ! vis[i][j] ) {
				ans++ ;
			}
		}
	}

    printf ( "%d" , ans ) ;
	
	return 0 ;
}

inline void dfs ( int x , int y ) {
	if ( x < 0 || y < 0 || x > 11 || y > 11 || vis[x][y] ) {
		return ;
	}
	
	vis[x][y] = true ;
	for ( int i = 0 ; i < 4 ; i++ ) {
		dfs ( x + dx[i] , y + dy[i] ) ;
	}
}