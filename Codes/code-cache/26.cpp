#include <iostream>//[Harry Potter] Professor Snape
#include <cstdio>
#include <cmath>
#include <algorithm>

int s , g , m , d , k ;

int main() {
	
	scanf ( "%d %d %d %d %d" , &s , &g , &m , &d , &k ) ;
	g += d ;
	
	if ( s == g ) {
		printf ( "G 1\n%d %d\n" , g , s ) ;
	}
	else if ( s > g ) {
		printf ( "%d %d\n" , g , s ) ;
	}
	else {
		if ( m * k < g - s ) {
			// printf ( 
		}
	}
	
	return 0 ;
}
