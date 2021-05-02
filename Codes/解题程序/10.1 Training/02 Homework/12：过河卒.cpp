#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long sx , sy , n , m , a[100][100] , dp[100][100] ;

int main () {
	
	scanf ( "%lld %lld %lld %lld" , &n , &m , &sx , &sy ) ;
	sx += 2 , sy += 2 , n += 2 , m += 2 ;
	
	a[sx - 2][sy - 1] = a[sx - 2][sy + 1] = a[sx - 1][sy - 2] = a[sx - 1][sy + 2] = a[sx - 1][sy + 2] = 
	a[sx + 1][sy - 2] = a[sx + 1][sy + 2] = a[sx + 2][sy - 1] = a[sx + 2][sy + 1] = a[sx][sy] = dp[2][2] = 1 ;
	
	for ( int i = 2 ; i <= n ; i++ ) {
		for ( int j = 2 ; j <= m ; j++ ) {
			if ( ! a[i][j] ) {
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1] ;
			}
		}
	}
	
	printf ( "%lld" , dp[n][m] ) ;
	
	return 0 ;
}