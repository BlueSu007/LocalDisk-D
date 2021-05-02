#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100005
int n , a[LEN] , seq1[LEN] , seq2[LEN] ;

int main () {
	
	while ( scanf ( "%d" , &a[++n] ) != EOF ) ;
	n-- ;

	int len1 = 1 , len2 = 1 ;	
	seq1[1] = a[1] , seq2[1] = a[1] ;
	
	for ( int i = 2 ; i <= n ; i++ ) {
		if ( seq1[len1] >= a[i] ) {
			seq1[++len1] = a[i] ;
		}
		else {
			int tmp1 = upper_bound ( seq1 + 1 , seq1 + 1 + len1 , a[i] , greater < int > () ) - seq1 ;
			seq1[tmp1] = a[i] ;
		}
		
		if ( seq2[len2] < a[i] ) {
			seq2[++len2] = a[i] ;
		}
		else {
			int tmp2 = lower_bound ( seq2 + 1 , seq2 + 1 + len2 , a[i] ) - seq2 ;
			seq2[tmp2] = a[i] ;
		}
	}
	
	printf ( "%d\n%d" , len1 , len2 ) ;
	
	return 0 ;
}