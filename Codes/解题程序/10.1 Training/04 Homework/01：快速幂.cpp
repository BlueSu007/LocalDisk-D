#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std ;

int n , k , p ;
inline long long quickPow ( int n , int k ) ;

int main () {
	
	scanf ( "%d %d %d" , &n , &k , &p ) ;
	printf ( "%lld" , quickPow ( n , k ) ) ;
	
	return 0 ;
}

inline long long quickPow ( int n , int k ) {
	long long ans = 1 , base = n ;
	while ( k ) {
		if ( k & 1 ) {
			ans *= base ;
			ans %= p ;
		}
		
		base *= base , base %= p ;
		k >>= 1 ;
	}
	
	return ans % p ;
}