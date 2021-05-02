#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define LEN 105
int n , a[LEN] , dp[2][LEN] , ans ;

int main() {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}
	
	// 写注释的时候想复杂了。其实就是对于每个数，暴力枚举一下前面的数，如果小于它就加一，然后实时更新最大值
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 0 ; j < i ; j++ ) {
			if ( a[i] > a[j] ) {
				dp[0][i] = max ( dp[0][i] , dp[0][j] + 1 ) ;
			}
		}
	}
	
	a[n + 1] = 0 ;
	
	for ( int i = n ; i ; i-- ) {
		for ( int j = n + 1 ; j > i ; j-- ) {
			if ( a[i] > a[j] ) {
				dp[1][i] = max ( dp[1][i] , dp[1][j] + 1 ) ;
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		ans = max ( dp[0][i] + dp[1][i] - 1 , ans ) ;
	}
	
	printf ( "%d" , n - ans ) ;
	
	return 0 ;
}